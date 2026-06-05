#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    int n;
    cin>>n;
    vector<pair<int, int>> vec(n);

    for(int i=0; i<n; i++){
        cin>>vec[i].first>>vec[i].second;
    }

    //　整列
    sort(vec.begin(), vec.end());

    for(int i=0; i<n-1; i++){
        if(vec[i].second>=vec[i+1].second){
            cout<<"No";
            return 0;
        }
    }

    cout<<"Yes";
    
    return 0;
}