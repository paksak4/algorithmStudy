// 방문 여부 확인 확실하게 할 것.

#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n,k;
    cin >> n >> k;

    int visit[100001] = {0,};
    visit[n]=1; //방문 표시 1

    queue<pair<int, int>> que;
    // 위치, 경과 시간

    que.push({n, 0});

    pair<int, int> p;

    while(!que.empty())
    {
        p = que.front();
        que.pop();

        if(p.first==k)
        {
            break;
        }
        else
        {
            for(int i : {p.first+1, p.first-1, p.first*2})
            {
                if(i>=0 && i<=100000 && visit[i]==0)
                {
                    que.push({i, p.second+1});
                    visit[i]=1;
                }
            }
        }
    }

    cout<<p.second;    

    return 0;
}