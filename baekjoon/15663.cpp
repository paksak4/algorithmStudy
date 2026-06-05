#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ansList;
vector<int> ans;
vector<pair<int, bool>> vec;

int n,m;

void bt(int t)
{
    if(t==m)
    {
        ansList.push_back(ans);
        return ;
    }
    else
    {
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
}

int main(void)
{
    cin>>n>>m;
    vec = vector<pair<int, bool>>(n);
    ans = vector<int>(m);
    for(int i=0; i<n; i++)
        cin>>vec[i].first;
    sort(vec.begin(), vec.end());
    bt(0);
    sort(ansList.begin(), ansList.end());
    ansList.erase(unique(ansList.begin(), ansList.end()), ansList.end());

    for(vector<int> i:ansList)
    {
        for(int t:i)
            cout<<t<<" ";
        cout<<"\n";
    }

    return 0;
}


