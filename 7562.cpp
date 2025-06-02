#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int visit[300][300] = {0,}; // 방문 확인
        int i; // 체스판의 크기
        cin>>i;

        int cx, cy; // 현재 칸
        int mx, my; // 이동하려는 칸

        cin>>cx>>cy;
        cin>>mx>>my;

        queue<pair<pair<int, int>, int>> que;
        // 좌표, 몇번 움직였는지

        que.push({{cx, cy},0});
        visit[cx][cy]=1;

        while(!que.empty())
        {
            pair<pair<int, int>, int> p;
            p = que.front();
            que.pop();

            if(p.first.first==mx && p.first.second==my)
            {
                cout<<p.second<<"\n";
                break;
            }

            if((p.first.first-1 >=0 && p.first.first-1 < i) && (p.first.second-2 >=0 && p.first.second-2 < i) && visit[p.first.first-1][p.first.second-2]==0)
            {
                que.push({{p.first.first-1, p.first.second-2}, p.second+1});
                visit[p.first.first-1][p.first.second-2]=1;
            }
            if((p.first.first-1 >=0 && p.first.first-1 < i) && (p.first.second+2 >=0 && p.first.second+2 < i) && visit[p.first.first-1][p.first.second+2]==0)
            {
                que.push({{p.first.first-1, p.first.second+2}, p.second+1});
                visit[p.first.first-1][p.first.second+2]=1;
            }
            if((p.first.first+1 >=0 && p.first.first+1 < i) && (p.first.second-2 >=0 && p.first.second-2 < i) && visit[p.first.first+1][p.first.second-2]==0)
            {
                que.push({{p.first.first+1, p.first.second-2}, p.second+1});
                visit[p.first.first+1][p.first.second-2]=1;
            }
            if((p.first.first+1 >=0 && p.first.first+1 < i) && (p.first.second+2 >=0 && p.first.second+2 < i) && visit[p.first.first+1][p.first.second+2]==0)
            {
                que.push({{p.first.first+1, p.first.second+2}, p.second+1});
                visit[p.first.first+1][p.first.second+2]=1;
            }
            if((p.first.first-2 >=0 && p.first.first-2 < i) && (p.first.second-1 >=0 && p.first.second-1 < i) && visit[p.first.first-2][p.first.second-1]==0)
            {
                que.push({{p.first.first-2, p.first.second-1}, p.second+1});
                visit[p.first.first-2][p.first.second-1]=1;
            }
            if((p.first.first-2 >=0 && p.first.first-2 < i) && (p.first.second+1 >=0 && p.first.second+1 < i) && visit[p.first.first-2][p.first.second+1]==0)
            {
                que.push({{p.first.first-2, p.first.second+1}, p.second+1});
                visit[p.first.first-2][p.first.second+1]=1;
            }
            if((p.first.first+2 >=0 && p.first.first+2 < i) && (p.first.second-1 >=0 && p.first.second-1 < i) && visit[p.first.first+2][p.first.second-1]==0)
            {
                que.push({{p.first.first+2, p.first.second-1}, p.second+1});
                visit[p.first.first+2][p.first.second-1]=1;
            }
            if((p.first.first+2 >=0 && p.first.first+2 < i) && (p.first.second+1 >=0 && p.first.second+1 < i) && visit[p.first.first+2][p.first.second+1]==0)
            {
                que.push({{p.first.first+2, p.first.second+1}, p.second+1});
                visit[p.first.first+2][p.first.second+1]=1;
            }
        }
    }

    return 0;
}