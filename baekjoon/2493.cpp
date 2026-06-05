#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
    stack<pair<int, int>> tower; // hegith, number
    vector<int> ans;

    int t;
    cin>>t;
    
    for(int i=1; i<=t; i++)
    {
        int towerHeight;
        cin>>towerHeight;

        while(1)
        {
            if(tower.empty()) // 비어있을때
            {
                ans.push_back(0);
                tower.push({towerHeight, i});
                break;
            }
            else if(tower.top().first < towerHeight)
            {
                tower.pop();
            }
            else if(tower.top().first > towerHeight)
            {
                ans.push_back(tower.top().second);
                tower.push({towerHeight, i});
                break;
            }
        }      
    }

    for(int i=0; i<t; i++)
        cout<<ans[i]<<" ";

    return 0;
}