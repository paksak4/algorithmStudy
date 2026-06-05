#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--)
    {
        int k;
        cin>>k;
        if(k==0)
        {   
            if(pq.empty())
                cout<<"0\n";
            else
            {
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else
            pq.push(k);
    }
    return 0;
}