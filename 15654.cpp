#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
vector<pair<int, bool>> vec;
vector<int> ans;

void bt(int t)
{
    if(t==m)
    {
        for(int num:ans)
            cout<<num<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(vec[i].second)
            continue;
        vec[i].second=true;
        ans[t]=vec[i].first;
        bt(t+1);
        vec[i].second=false;
    }
}

int main(void)
{
    cin>>n>>m;
    vec = vector<pair<int, bool>>(n);
    ans = vector<int> (m);
    for(int i=0; i<n; i++)
        cin>>vec[i].first;
    sort(vec.begin(), vec.end());
    bt(0);

    return 0;
}