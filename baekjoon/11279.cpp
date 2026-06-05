#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    priority_queue<int> pq;
    while(n--)
    {
        int x;
        scanf("%d", &x);
        if(x==0)
        {
            printf("%d\n", pq.empty()?0:pq.top());
            if(pq.empty())
                continue;
            else
                pq.pop();
        }
        else
            pq.push(x);

    }
    return 0;
}