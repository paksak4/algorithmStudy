#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    //　縦、横、個数
    int h, w, n;
    cin>>h>>w>>n;
    vector<vector<string>> board(n, vector<string>(h));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<h; j++){
            cin>>board[i][j];
        }
    }

    //　計画図の縦、横
    int r, c;
    cin>>r>>c;
    vector<vector<int>> plan(r, vector<int>(c));

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>plan[i][j];
            plan[i][j]--;
        }
    }

    //アート予定図
    vector<vector<string>> art(r*h, vector<string>(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            //　n番のスタンプか
            int num=plan[i][j];
            for(int k=0; k<h; k++) {
                art[i*h+k][j]=board[num][k];
            }
        }
    }

    for(int i=0; i<r*h; i++) {
        for(int j=0; j<c; j++) {
            cout<<art[i][j];
        }
        cout<<"\n";
    }


    return 0;
}