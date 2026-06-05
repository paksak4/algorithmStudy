#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, k;
    cin>>n>>k;
    vector<int> coin(n);
    for(int i=0; i<n; i++)
        cin>>coin[i];
    vector<int> dp(k+1, 0);
    dp[0]=1;
    for(int c:coin)
    {
        for(int i=c; i<k+1; i++)
            dp[i]+=dp[i-c];
    }    
    cout<<dp[k];

    return 0;
}