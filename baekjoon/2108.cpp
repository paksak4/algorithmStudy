#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    }
    return a.second>b.second;
}

int main(void)
{
    int n;
    cin>>n;
    vector<int> vec(n);
    map<int, int> m;
    vector<pair<int, int>> v;
    int total=0;
    
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
        total+=vec[i];
        m[vec[i]]++;
    }
    for(auto it = m.begin(); it!=m.end(); it++)
    {   
        //cout<<it->first<<" "<<it->second<<"\n";
        v.push_back({it->first, it->second}); // 값과 빈도
    }
    sort(v.begin(), v.end(), compare);
    // for(int i=0; i<n; i++)
    //      cout<<v[i].first<<" "<<v[i].second<<"\n";
    
    cout<<(int)round((double)total/n)<<"\n";
    sort(vec.begin(), vec.end());
    cout<<vec[n/2]<<"\n";
    if(v[0].second==v[1].second)
        cout<<v[1].first<<"\n";
    else
        cout<<v[0].first<<"\n";
    cout<<vec[n-1]-vec[0]<<"\n";

    return 0;
}
