#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    stack<pair<int, int>> tower;
    stack<pair<int, int>> tmp; 
    // tmpー＞실시간으로(?) 관리하기 위한 stack
    // height, 確認できる建物の数

    long long total = 0;

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int num; // 높이
        cin>>num;
        tower.push({num, 0});
    }

    while(!tower.empty())
    {
        if(tmp.empty())
        {
            tmp.push(tower.top());
            tower.pop();
        }
        else if(tmp.top().first>=tower.top().first)
        {
            tmp.push(tower.top());
            tower.pop();
        }
        else if(tmp.top().first<tower.top().first)
        {
            tower.top().second++;
            tower.top().second+=tmp.top().second;
            total+=tmp.top().second;
            tmp.pop();
        }
    }

    while(!tmp.empty())
    {
        total+=tmp.top().second;
        tmp.pop();
    }

    cout<<total;

    return 0;
}