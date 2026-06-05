#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin>>n;

    int dp[5000];
    dp[0] = dp[1] = dp[3] = -1;
    dp[2] = dp[4] = 1;

    for(int i=5; i<n; i++)
    {
        if(dp[i-5]!=-1)
            dp[i]=(dp[i-5]+1);
        else if(dp[i-3]!=-1)
            dp[i]=(dp[i-3]+1);
        else
            dp[i]=-1;
    }

    cout<<dp[n-1];

    return 0;
}