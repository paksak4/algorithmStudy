#include <iostream>
#include <vector>

using namespace std;

int n, s, t;
vector<pair<int, int>> vec(36);
vector<int> rear;


int dfs(int cnt, int weight) {
    if(weight>t){
        //cout<<weight<<" +0 됨\n";
        return 0;
    }
    if(cnt>n){
        //cout<<weight<<" +1 됨\n";
        return 1;
    }

    return dfs(cnt+1, weight-vec[cnt].first) + dfs(cnt+1, weight+vec[cnt].second);
}

int main(void){

    cin>>n>>s>>t;
    for(int i=1; i<=n; i++){
        cin>>vec[i].first>>vec[i].second;
    }

    cout<<dfs(2, s-vec[1].first)+dfs(2, s+vec[1].second);

    return 0;
}