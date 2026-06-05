#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool compare(std::pair<int, std::string> a, std::pair<int, std::string> b)
{
    return a.first<b.first;
}

int main(void)
{
    int n;
    std::cin>>n;

    std::vector<std::pair<int, std::string>> v(n);
    for(int i=0; i<n; i++)
        std::cin>>v[i].first>>v[i].second;
    
    std::stable_sort(v.begin(), v.end(), compare);

    for(std::pair<int, std::string> p : v)
        std::cout<<p.first<<" "<<p.second<<"\n";

    return 0;
}