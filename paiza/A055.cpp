#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int main(void){
    int h, w;
    cin>>h>>w;

    pair<int, int> start;
    // 보드판
    vector<vector<char>> board(h, vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>board[i][j];
            if(board[i][j]=='S'){
                start={i, j};
            }
        }
    }

    queue<pair<int, int>> toVisit;
    toVisit.push(start);
    board[start.first][start.second]='x';

    while(!toVisit.empty()){
        int x=toVisit.front().first;
        int y=toVisit.front().second;
        toVisit.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=h||ny<0||ny>=w){
                cout<<"YES";
                exit(0);
            }
            if(board[nx][ny]!='.'){
                continue;
            }
            toVisit.push({nx, ny});
            board[nx][ny]='x';
        }
    }

    cout<<"NO";

    return 0;
}