#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

// o(h*5*4*h)
int main(void){

    int h;
    cin>>h;

    vector<string> board(h);

    for(int i=0; i<h; i++){
        cin>>board[i];
        //cout<<"입력함";
    }

    
    while(1) {
        //cout<<"==========\n";
        queue<pair<int, int>> corToDelete;

        //　消去するところ探し
        for(int i=0; i<h; i++){
            for(int j=0; j<5; j++){
                if(board[i][j]=='.')
                    continue;
                bool check=true;
                queue<pair<int, int>> temp;
                for(int k=0; k<4; k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<0 || nx>=h || ny<0 || ny>=5)
                        continue;
                    if(board[i][j]!=board[nx][ny]){
                        check=false;
                        break;
                    }
                    temp.push({nx,ny});
                }
                if(check){
                    temp.push({i,j});
                    while(!temp.empty()){
                        corToDelete.push(temp.front());
                        temp.pop();
                    }
                } 
            }
        }

        if(corToDelete.empty()){
            break;
        }

        // 消し
        while(!corToDelete.empty()) {
            pair<int, int> p=corToDelete.front();
            corToDelete.pop();
            board[p.first][p.second]='.';
        }

        //　下に落とし
        queue<char> temp;
        for(int i=0; i<5; i++){
            for(int j=h-1; j>=0; j--){
                if(board[j][i]!='.'){
                    temp.push(board[j][i]);
                }
                board[j][i]='.';
            }
            for(int j=h-1; j>=0; j--){
                if(temp.empty()){
                    break;
                }
                board[j][i]=temp.front();
                temp.pop();
            }
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<5; j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }   

    return 0;
}