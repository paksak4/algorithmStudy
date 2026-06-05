#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){

    int h, w;
    cin>>h>>w;

    vector<string> board(h);
    //訪問したか
    vector<vector<bool>> visit(h, vector<bool>(w,0));
    queue<pair<int, int>> que;

    for(int i=0; i<h; i++){
        cin>>board[i];
    }

    int r=0, g=0, b=0;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char target;
            if(visit[i][j]==false){
                que.push({i, j});
                visit[i][j]=true;
                target=board[i][j];
                if(target=='R')
                    r++;
                else if(target=='G')
                    g++;
                else if(target=='B')
                    b++;
            }
            while(!que.empty()){
                int x, y;
                x=que.front().first;
                y=que.front().second;
                que.pop();

                for(int k=0; k<4; k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx<0 || nx>=h || ny<0 || ny>=w)
                        continue;
                    if(visit[nx][ny]==true || board[nx][ny]!=target)
                        continue;
                    
                    que.push({nx, ny});
                    visit[nx][ny]=true;
                }
            }
        }
    }

    cout<<r<<" "<<g<<" "<<b;

    return 0;
}