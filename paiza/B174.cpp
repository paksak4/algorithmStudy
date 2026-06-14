#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int h, w;
    cin>>h>>w;

    vector<vector<char>> board(h+1, vector<char>(w+1, '.'));
    int n;
    cin>>n;
    //cout<<n;

    for(int i=0; i<n; i++){
        int r,c,b;
        cin>>r>>c>>b;
        string str;
        cin>>str;
        if(b==0){
            for(int j=r; j<r+str.length(); j++){
                board[j][c]=str[j-r];
            }
        } else if(b==1){
            for(int j=c; j<c+str.length(); j++){
                board[r][j]=str[j-c];
            }
        }
    }

    for(int i=1; i<h+1; i++){
        for (int j=1; j<w+1; j++)
        {
            cout<<board[i][j];
        }
        cout<<"\n";
    }

    return 0;
}