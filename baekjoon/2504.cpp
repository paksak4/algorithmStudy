#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int k, n;
    cin>>k>>n;
    vector<int> vec(k);
    for(int i=0; i<k; i++)
        cin>>vec[i];
    long long start=1;
    long long end=INT_MAX;
    long long mid;
    while(start<end)
    {
        mid=(start+end+1)/2;
        int sum=0; // 갯수
        for(int i=0; i<k; i++)
            sum+=vec[i]/mid;
        if(sum>=n)
            start=mid;
        else
            end=mid-1;
    }
    cout<<start;
    return 0;
}