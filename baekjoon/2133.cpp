#include <iostream>

using namespace std;

int main(void)
{
    long long n;
    cin>>n;
    if(n%2==1)
        cout<<"0";
    else
    {
        long long dp[30];
        dp[1]=3;
        dp[3]=11;
        
        for(int i=5; i<n; i+=2)
            dp[i] = dp[i-2]*4-dp[i-4];
        cout<<dp[n-1];
    }
    return 0;
}