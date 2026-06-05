#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n, m;
    cin>>n>>m;
    vector<int> vec(n+1);
    vec[0]=0;
    for(int i=1; i<n+1; i++)
    {    
        cin>>vec[i];
        vec[i]+=vec[i-1];
    }

    
    int total=0;
    int end=0;
    for(int start=0; start<n+1; start++)
    {
        while(vec[end]-vec[start]<m && end<n+1)
        {
            end++;
        }
        if(vec[end]-vec[start]==m)
            total++;
        
    }
    
    cout<<total;
    return 0;
}