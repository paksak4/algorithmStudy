#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.first==b.first)
        return a.second<b.second;
    else
        return a.first<b.first;
}

int main(void)
{
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++)
    {
        int s, t;
        cin>>s>>t;
        v.push_back({s,t});
        //pq.push({s,t});
    }

    sort(v.begin(), v.end(), compare);

    pq.push(v[0].second);
    for(int i=1; i<n; i++)
    {
        if(v[i].first<pq.top())
        {
            pq.push(v[i].second);
        }
        else
        {
            pq.pop();
            pq.push(v[i].second);
        }
    }
    cout<<pq.size();

    return 0;
}