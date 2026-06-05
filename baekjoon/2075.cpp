#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<n; i++)
    {   
        for(int j=0; j<n; j++)
        {
            int t;
            scanf("%d", &t);
            pq.push(t);
        }
        
        while(pq.size()>n)
            pq.pop();
    }
    printf("%d", pq.top());

    return 0;
}