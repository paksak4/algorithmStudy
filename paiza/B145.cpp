#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    // nは奇数
    int n, k;
    cin>>n>>k;
    
    // ビンゴカード
    vector<vector<int>> board(n, vector<int>(n, 0));
    // ビンゴカードのどの位置にどんな数字があるか
    // 数字、行、列
    vector<pair<int, pair<int, int>>> place(n*n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>board[i][j];
            place[i*n+j].first=board[i][j];
            place[i*n+j].second={i,j};
        }
    }

    board[n/2][n/2]=-1;

    for(int i=0; i<k; i++){
        int num;
        cin>>num;
        for(int j=0; j<n*n; j++){
            if(num==place[j].first){
                board[place[j].second.first][place[j].second.second]=-1;
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int count=0;
    
    //横
    for(int i=0; i<n; i++) {
        bool isBingo=true;
        for(int j=0; j<n; j++){
            if(board[i][j]!=-1){
                isBingo=false;
                break;
            }
        }
        if(isBingo){
            count++;
        }
    }

    //縦
    for(int i=0; i<n; i++) {
        bool isBingo=true;
        for(int j=0; j<n; j++){
            if(board[j][i]!=-1){
                isBingo=false;
                break;
            }
        }
        if(isBingo){
            count++;
        }
    }

    // 対角
    bool isBingo=true;
    for(int i=0, j=0; i<n && j<n; i++, j++){
        if(board[i][j]!=-1) {
            isBingo=false;
            break;
        }
    }
    if(isBingo==true){
        count++;
    }

    // 対角
    isBingo=true;
    for(int i=0, j=n-1; i<n && j>=0; i++, j--){
        if(board[i][j]!=-1) {
            isBingo=false;
            break;
        }
    }
    if(isBingo==true){
        count++;
    }

    cout<<count;

    return 0;
}