#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main(void)
{
    long long n, m;
    cin>>n>>m;
    vector<long long> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];
    sort(vec.begin(), vec.end());
    int start = 0, end = 0;
    long long minNum = __LONG_LONG_MAX__;
    while(start<n && end<n)
    {
        if(vec[end]-vec[start]<m)
            end++;
        else if(vec[end]-vec[start]>=m)
        {
            minNum=min(minNum, vec[end]-vec[start]);
            start++;
        }
    }
    cout<<minNum;
    return 0;
}