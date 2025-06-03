#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    stack<pair<int, int>> stk; // 키와 연속된 키의 수
    long long totalPair = 0;
    for(int i=0; i<n; i++)
    {
        int h;
        cin>>h;
        int con = 1; // 앞에 큰 거나 같은 수가 몇 개 있는지
        while(!stk.empty()&&stk.top().first<=h)
        {
            //cout<<stk.top().ㄹ<<", "<<h<<", "<<"\n";
            if(stk.top().first==h)
            {
                con=stk.top().second+1;
                break;
            }
            totalPair++;
            stk.pop();
        }
        if(stk.empty()) // 비어 있을때
            stk.push({h, 0});  
        else // 비어 있지 않을때
        {
            totalPair+=con;
            stk.push({h, con});
        }
    }
    cout<<totalPair;
    return 0;
}