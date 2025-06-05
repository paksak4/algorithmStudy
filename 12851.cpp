#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n,k;
    cin >> n >> k; // 수빈, 동생 위치

    vector<pair<int, int>> visit(100001); 
    // first개 방문했고, second만큼 걸림 --> 방문기록용
    queue<int> que;
    // 위치

    que.push(n);
    visit[n]={1,0};
    int time=0;
    int ans=-1;
    while(!que.empty())
    {
        int p=que.front();
        que.pop();

        if(p==k)
        {    
            ans=p;
            break;
        }
        
        for(int i : {p+1, p-1, p*2})
        {
            if(i<0 || i>100000)
                continue;
            if(visit[i].first==0) // 방문하지 않았으면
            {
                visit[i].first+=visit[p].first;
                visit[i].second=visit[p].second+1;
                que.push(i);
            }
            else if(visit[i].first!=0 && visit[i].second==visit[p].second+1) // 방문했는데 걸린 시간이 작거나 같을 경우
            {
                visit[i].first+=visit[p].first;
            }
        }
    }

    cout<<visit[ans].second<<"\n"<<visit[ans].first;

    return 0;
}