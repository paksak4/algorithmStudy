#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    int n, m;
    cin>>n>>m;

    //路線別値段
    vector<vector<int>> fee(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>fee[i][j];
        }
    }

    //経由すべき駅の数
    int pass;
    cin>>pass;

    // 現在の駅
    int nowStation=0;
    // 運賃総額
    int total=0;

    for(int i=0; i<pass; i++){
        int line, station;
        cin>>line>>station;
        line--;
        station--;

        total+=abs(fee[line][nowStation]-fee[line][station]);
        nowStation=station;
    }

    cout<<total;

    return 0;
}