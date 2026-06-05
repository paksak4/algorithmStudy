#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int a, int b)
{
    return a>b;
}

int main(void)
{
    int n;
    std::cin>>n;

    std::vector<int> v(n);
    for(int i=0; i<n; i++)
        std::cin>>v[i];

    sort(v.begin(), v.end(), compare);

    for(int i:v)
        std::cout<<i<<"\n";

    return 0;
}