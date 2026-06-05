#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int dp[3][300];
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>dp[0][i];

    dp[1][0]=0;
    dp[2][0]=dp[0][0];

    dp[1][1]=dp[0][1];
    dp[2][1]=dp[2][0]+dp[0][1];

    for(int i=2; i<n; i++)
    {
        dp[2][i]=dp[1][i-1]+dp[0][i];
        dp[1][i]=max(dp[1][i-2], dp[2][i-2])+dp[0][i];
    }

    // for(int j=0; j<2; j++)
    // {    
    //     for(int i=0; i<n; i++)
    //         cout<<dp[j+1][i]<<" ";
    //     cout<<"\n";
    // }

    cout<<max(dp[1][n-1], dp[2][n-1]);

    return 0;
}