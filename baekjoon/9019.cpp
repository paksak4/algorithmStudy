#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main(void) 
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        queue<pair<int, string>> que;
        vector<bool> visit(10000, false);
        que.push({a,""});
        visit[a]=true;
        while(!que.empty())
        {
            pair<int, string> c = que.front();
            que.pop();

            if(c.first==b)
            {    
                cout<<c.second<<"\n";
                break;
            }
            
            // pair<int, string> d = {(c.first*2)%10000, c.second+"D"};
            // pair<int, string> s = {(c.first!=0?c.first-1:9999), c.second+"S"};
            // pair<int, string> l = {((c.first*10)+(c.first/1000))%10000, c.second+"L"};
            // pair<int, string> r = {(c.first/10)+((c.first%10)*1000), c.second+"R"};
            int d = (c.first*2)%10000;
            int s = (c.first!=0?c.first-1:9999);
            int l = ((c.first*10)+(c.first/1000))%10000;
            int r =(c.first/10)+((c.first%10)*1000);
            if(!visit[d])
            {
                visit[d]=true;
                que.push({d, c.second+"D"});
            }
            if(!visit[s])
            {
                visit[s]=true;
                que.push({s, c.second+"S"});
            }
            if(!visit[l])
            {
                visit[l]=true;
                que.push({l, c.second+"L"});
            }
            if(!visit[r])
            {
                visit[r]=true;
                que.push({r, c.second+"R"});
            }

            // for(pair<int, string> p : {d,s,l,r})
            // {
            //     if(visit[p.first])
            //         continue;
            //     visit[p.first]=true;
            //     que.push(p);
            // }
        }
    }
    return 0;
}