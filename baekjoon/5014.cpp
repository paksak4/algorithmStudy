#include <iostream>
#include <queue>
#include <vector>

int main(void)
{
    int f, s, g, u, d;
    std::cin>>f>>s>>g>>u>>d;
    if(s==g)
    {
        std::cout<<"0";
        return 0;
    }
    std::queue<std::pair<int, int>> que;
    std::vector<bool> visit(f+1, false);
    visit[s]=true;
    que.push({s,0});
    while(!que.empty())
    {
        std::pair<int, int> c=que.front();
        que.pop();
        
        for(int i:{u,(-d)})
        {
            if(c.first+i<1 || c.first+i>f)
                continue;
            if(visit[c.first+i])
                continue;
            
            que.push({c.first+i, c.second+1});
            visit[c.first+i]=true;
            //std::cout<<c.first+i<<", "<<c.second+1<<"\n";
            if(c.first+i==g)
            {
                std::cout<<c.second+1;
                return 0;
            }
        }
    }

    std::cout<<"use the stairs";

    return 0;
}