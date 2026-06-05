#include <iostream>
#include <queue>

using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int board[10][10];
int visit[10][10];

int maxTotal=0;
int h, w, k;

void dfs(int x, int y, int count, int total){
    if(count==k){
        if(total>maxTotal)
            maxTotal=total;
        return;
    }

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<0 || nx>=h || ny<0 || ny>=w)
            continue;

        if(visit[nx][ny]==1)
            continue;

        visit[nx][ny]=1;
        total+=board[nx][ny];
        dfs(nx, ny, count+1, total);
        total-=board[nx][ny];
        visit[nx][ny]=0;
    }

    return;
}

int main(void){

    cin>>h>>w>>k;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>board[i][j];
        }
    }

    int total=0;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            visit[i][j]=1;
            total=board[i][j];
            dfs(i, j, 0, total);
            total-=board[i][j];
            visit[i][j]=0;
        }
    }

    cout<<maxTotal;

    return 0;
}