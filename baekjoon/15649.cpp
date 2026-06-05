#include <iostream>
#include <vector>

using namespace std;

vector<int> vec(8);
bool visit[8] = {false, }; // 방문했는지

void rec(int n, int m, int t) // n, m, 삽입개수
{
    if(m==t) // base condition
    {
        for(int i=0; i<m; i++)
            cout<<vec[i]<<" ";
        cout<<"\n";
        return;
    }
    
    for(int i=1; i<=n; i++)
    {
        if(visit[i-1])
            continue;
        visit[i-1]=true;
        vec[t]=i;
        rec(n, m, t+1);
        visit[i-1]=false;
    }
    return;
}

int main(void)
{
    int n, m;
    cin>>n>>m;

    rec(n, m, 0);
    
    return 0;
}