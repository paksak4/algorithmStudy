#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin>>n;

    vector<int> vec(n+1);
    vec[1] = 0;
    for(int i=2; i<=n; i++)
    {
        int min = vec[i-1];
        if((i%2==0) && (vec[i/2]<=min))
            min=vec[i/2];
        if((i%3==0) && (vec[i/3]<=min))
            min=vec[i/3];
        vec[i]=min+1;
    } 

    // for(int i=1; i<=n; i++)
    //     cout<<vec[i]<<" ";

    cout<<vec[n];

    return 0;
}