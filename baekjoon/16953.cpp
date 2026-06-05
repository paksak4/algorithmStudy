#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    long long a, b;
    cin>>a>>b;
    queue<pair<long long, long long>> que;
    que.push({a, 1});

    while(!que.empty())
    {
        pair<long long, long long> p = que.front();
        que.pop();

        if(p.first*2==b || p.first*10+1==b)
        {
            cout<<p.second+1;
            return 0;
        }

        if(p.first*2<b)
            que.push({p.first*2, p.second+1});
        if(p.first*10+1<b)
            que.push({p.first*10+1, p.second+1});
    
    }
    cout<<"-1";
    return 0;
}