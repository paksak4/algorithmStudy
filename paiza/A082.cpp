#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(void){

    int h,w;
    cin>>h>>w;
    
    //マップ
    vector<vector<char>> board(h, vector<char>(w));
    // 湖の左表
    queue<pair<int, int>> mizu;


    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>board[i][j];
            if(board[i][j]=='#'){
                mizu.push({i,j});
            }
        }
    }

    int count=h*w;

    //　スタート
    int xS=mizu.front().first;
    int yS=mizu.front().second;
    mizu.pop();

    while(!mizu.empty()){

        // 建物の座標
        int xB=mizu.front().first;
        int yB=mizu.front().second;
        mizu.pop();
        board[xB][yB]='B';

        queue<pair<int, int>> toVisit;
        vector<vector<bool>> visit(h, vector<bool>(w, false));

        toVisit.push({xS, yS});
        visit[xS][yS]=true;

        bool place=false;

        while(!toVisit.empty()){
            pair<int, int> s=toVisit.front();
            toVisit.pop();

            for(int i=0; i<4; i++){
                int x=s.first+dx[i];
                int y=s.second+dy[i];

                if(x<0 || x>=h || y<0 || y>=w){
                    continue;
                }
                
                if(board[x][y]=='#'&&!visit[x][y]){
                    visit[x][y]=true;
                    toVisit.push({x, y});
                }
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(board[i][j]=='#'&&!visit[i][j])
                    place=true;
            }
        }
        
        if(place)
            count--;
        board[xB][yB]='#';
    }

    cout<<count;
    return 0;
}