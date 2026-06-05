#include <iostream>
#include <vector>

using namespace std;

int main(void){

    // 作業回数、作物の種類数
    int n, m;
    cin>>n>>m;
    // 行、列
    int h, w;
    cin>>h>>w;

    // 0は何も植えられていない
    vector<vector<int>> board(h, vector<int>(w, 0));
    vector<int> count(m+1, 0);

    for(int i=0; i<n; i++){
        int a_i, b_i, c_i, d_i, e_i;
        cin>>a_i>>b_i>>c_i>>d_i>>e_i;
        a_i--;
        b_i--;
        c_i--;
        d_i--;
        for(int j=a_i; j<=b_i; j++){
            for(int k=c_i; k<=d_i; k++){
                count[board[j][k]]++;
                board[j][k]=e_i;
            }
        }
    }

    for(int i=1; i<=m; i++){
        cout<<count[i]<<"\n";
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(board[i][j]==0){
                cout<<".";
                continue;
            }
            cout<<board[i][j];
        }
        cout<<"\n";
    }

    return 0;
}