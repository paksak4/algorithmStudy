#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(void)
{
    int n, k;
    cin>>n>>k;
    map<int, bool> coin;
    vector<int> dp(k+1, -1);
    for(int i=0; i<n; i++)
    {
        int v;
        cin>>v;
        if(v>k)
            continue;
        coin[v]=true;
    }
    for(auto p : coin)
    {
        dp[p.first]=1;
        for(int i=p.first+1; i<k+1; i++)
        {
            if(dp[i]==-1 && dp[i-p.first]!=-1)
                dp[i]=dp[i-p.first]+1;
            else if(dp[i]!=-1 && dp[i-p.first]!=-1)
                dp[i]=min(dp[i], dp[i-p.first]+1);
        }
    }
    cout<<dp[k];
    return 0;
}