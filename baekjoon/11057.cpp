#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin>>n;

    int dp[1000][10];
    fill(dp[0], dp[0]+10, 1);

    for(int i=1; i<n; i++)
    {
        dp[i][0] = 1;
        for(int j=1; j<10; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%10007;          
        }
    }

    int total=0;
    for(int i=0; i<10; i++)
        total+=dp[n-1][i];

    cout<<total%10007;

    return 0;
}