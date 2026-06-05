#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    vector<pair<int, int>> dp(n,{0,1});
    for(int i=0; i<n; i++)
        cin>>dp[i].first;
    int lmax=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(dp[i].first>dp[j].first)
                dp[i].second=max(dp[j].second+1, dp[i].second);
        }
        lmax=max(lmax, dp[i].second);
    }
    cout<<lmax;

    return 0;
}