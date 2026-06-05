#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);
    // 실제 값, 오큰수

    stack<pair<int, int>> stk;
    // 실제 값, 오큰수

    for(int i=0; i<n; i++)
        cin>>vec[i].first;

    // vec[n-1].second = -1;
    // stk.push(vec[n-1]);
   
    //cout<<"여기까진옴"<<endl;

    for(int i=n-1; i>=0;)
    {
        //cout<<vec[i].first<<"접근"<<endl;
        if(stk.empty())
        {
            vec[i].second = -1;
            stk.push(vec[i]);
            i--;
        }
        else if(vec[i].first<stk.top().first)
        {
            vec[i].second = stk.top().first;
            stk.push(vec[i]);
            i--;
        }
        else
        {
            stk.pop();
        }
    }

    for(pair<int, int> p : vec)
    {
        cout<<p.second<<" ";
    }

    return 0;
}