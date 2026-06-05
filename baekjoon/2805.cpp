#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int n, m; // 나무의 수, 나무의 길이
    cin>>n>>m;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];
    long long start=0;
    long long end=INT_MAX;
    long long mid;
    while(start<end)
    {
        mid=(start+end+1)/2; // 절단기의 높이
        long long sum=0;
        for(int num : vec)
        {
            if(num<mid) // 나무의 높이가 낮으면 잘리지 않기 때문
                continue;
            sum+=(num-mid);
        }
        if(sum>=m)
            start=mid;
        else
            end=mid-1;
    }
    cout<<start;
    return 0;
}