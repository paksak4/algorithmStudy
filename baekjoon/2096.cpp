#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    vector<int> dp(3);
    vector<int> maxAns(3);
    vector<int> minAns(3);
    cin>>dp[0]>>dp[1]>>dp[2];
    maxAns[0]=minAns[0]=dp[0];
    maxAns[1]=minAns[1]=dp[1];
    maxAns[2]=minAns[2]=dp[2];
    for(int i=1; i<n; i++)
    {
        cin>>dp[0]>>dp[1]>>dp[2];
        int maxA, maxB, maxC;
        maxA=dp[0]+max(maxAns[0], maxAns[1]);
        maxB=dp[1]+max(maxAns[0], max(maxAns[1], maxAns[2]));
        maxC=dp[2]+max(maxAns[1], maxAns[2]);
        maxAns[0]=maxA;
        maxAns[1]=maxB;
        maxAns[2]=maxC;
        int minA, minB, minC;
        minA=dp[0]+min(minAns[0], minAns[1]);
        minB=dp[1]+min(minAns[0], min(minAns[1], minAns[2]));
        minC=dp[2]+min(minAns[1], minAns[2]);
        minAns[0]=minA;
        minAns[1]=minB;
        minAns[2]=minC;
    }
    cout<<max(max(maxAns[0], maxAns[1]), maxAns[2])<<" ";
    cout<<min(min(minAns[0], minAns[1]), minAns[2]);

    return 0;
}