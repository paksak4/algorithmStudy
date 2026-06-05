#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n;
    std::cin>>n;
    std::vector<int> vec(n);
    for(int i=0; i<n; i++)
        std::cin>>vec[i];
    std::vector<int> ans;
    ans.push_back(vec[0]);
    for(int i=1; i<n; i++)
    {
        if(vec[i]>ans.back())
            ans.push_back(vec[i]);
        else if(vec[i]<ans.back())
        {
            std::vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), vec[i]);
            *it = vec[i];
        }
    }
    std::cout<<ans.size();
    return 0;
}