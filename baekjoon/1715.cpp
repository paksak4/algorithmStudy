#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        pq.push(t);
    }
    int total=0;
    while(pq.size()!=1)
    {
        int n1, n2;
        n1=pq.top();
        pq.pop();
        n2=pq.top();
        pq.pop();
        total+=(n1+n2);
        pq.push(n1+n2);
    }
    cout<<total;

    return 0;
}