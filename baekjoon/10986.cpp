#include <iostream>
#include <vector>

int main(void)
{
    int n, m;
    std::cin>>n>>m;
    std::vector<int> vec(n);
    int total=0;
    int count=0;
    for(int i=0; i<n; i++)
    {
        int t;
        std::cin>>t;
        total+=t;
        total%=m;
        if(total==0)
            count++;
        vec[i]=total;
        //std::cout<<vec[i]<<" ";
    }

    //std::cout<<count;
    std::cout<<(1<<count)-1;
    
    return 0;
}