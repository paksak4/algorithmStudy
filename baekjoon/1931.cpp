#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) 
{
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second < b.second;
}

int main(void)
{
    int n;
    cin>>n;

    vector<pair<int, int>> vec(n);
    for(int i=0; i<n; i++)
    {
        int s, e;
        cin>>s>>e;
        vec[i]={s, e};
    }

    sort(vec.begin(), vec.end(), compare); // second 기준 오름차순[2]

    // for(int i=0; i<n; i++)
    //     cout<<"("<<vec[i].first<<", "<<vec[i].second<<")\n";

    int e = 0;
    int t = 0;

    for(int i=0; i<n; i++)
    {
        if(vec[i].first>=e)
        {    
            e=vec[i].second;
            // if(vec[i].first==vec[i].second)
            //     e++;
            cout<<"("<<vec[i].first<<", "<<vec[i].second<<")\n";
            t++;
        }
    }

    cout<<t;
    
    return 0;
}