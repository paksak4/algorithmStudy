#include <iostream>

using namespace std;

int main(void)
{
    unsigned long long n, m;
    cin>>n>>m;
    cout<<(n%(m+1)==0?"Can win":"Can't win");
    return 0;
}