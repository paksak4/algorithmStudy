#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    long long n;
    cin>>n;
    deque<long long> que;
    que.push_front(1);
    que.push_front(0);
    
    cout<<que.back();
    return 0;
}