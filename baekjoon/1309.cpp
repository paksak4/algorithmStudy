#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    vector<vector<int>> dp(3, vector<int>(n));
    // 0 행은 x 경우, 1 행은 상, 2행은 하
    dp[0][0]=dp[1][0]=dp[2][0]=1;
    for(int i=1; i<n; i++)
    {
        dp[0][i]=(dp[0][i-1]+dp[1][i-1]+dp[2][i-1])%9901;
        dp[1][i]=(dp[0][i-1]+dp[2][i-1])%9901;
        dp[2][i]=(dp[0][i-1]+dp[1][i-1])%9901;
    }
    cout<<(dp[0][n-1]+dp[1][n-1]+dp[2][n-1])%9901;
    return 0;
}