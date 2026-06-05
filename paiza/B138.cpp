#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int x[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main(void){

    int h, w;
    cin>>h>>w;

    //　ドーナツの絵
    vector<string> board(h);
    //　白の座標
    queue<pair<int, int>> place;

    for(int i=0; i<h; i++){
        cin>>board[i];
        for(int j=0; j<w; j++){
            //　白の場合、座標を保存
            if(board[i].at(j)=='.'){
                place.push({i,j});
            }
        }
    }

    int count = 0;
    while(place.size()!=0){
        pair<int, int> p = place.front();
        place.pop();
        //cout<<p.first<<" "<<p.second<<"\n";

        bool isDonut = true;
        for(int i=0; i<8; i++){

            // 範囲の外
            if(p.first+x[i]<0 || p.first+x[i]>=h || p.second+y[i]<0 || p.second+y[i]>=w) {
                isDonut=false;
                break;
            }


            if(board[p.first+x[i]][p.second+y[i]]!='#') {
                isDonut=false;
                break;
            }
        }

        if(isDonut)
            count++;
    }
    
    cout<<count;

    return 0;
}