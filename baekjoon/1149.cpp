#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin>>n;

    int dp[3][1000];

    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            cin>>dp[j][i];

    for(int i=1; i<n; i++)
    {
        dp[0][i]+=min(dp[1][i-1], dp[2][i-1]);
        dp[1][i]+=min(dp[0][i-1], dp[2][i-1]);
        dp[2][i]+=min(dp[0][i-1], dp[1][i-1]);
    }

    cout<<min(min(dp[0][n-1], dp[1][n-1]), dp[2][n-1]);

    return 0;
}