#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct VALUE
{
    int first, second, third;
};

int main(void)
{
    int n;
    cin>>n;
    vector<VALUE> vec(n);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i].first;
        vec[i].second=vec[i].third=1;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(vec[i].first>vec[j].first)
                vec[i].second=max(vec[j].second+1, vec[i].second);
        }
    }
    for(int i=n-1; i>=0; i--)
    {
        for(int j=n-1; j>i; j--)
        {
            if(vec[i].first>vec[j].first)
                vec[i].third=max(vec[j].third+1, vec[i].third);
        }
    }
    // for(int i=0; i<n; i++)
    //     cout<<vec[i].second<<" ";
    // cout<<"\n";
    // for(int i=0; i<n; i++)
    //     cout<<vec[i].third<<" ";
    // cout<<"\n";

    int m=0;
    for(int i=0; i<n; i++)
        m=max(m, vec[i].second+vec[i].third-1);
    cout<<m;
    return 0;
}