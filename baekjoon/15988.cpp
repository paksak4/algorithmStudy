#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        
        vector<long long> vec(n);
        vec[0]=1;
        vec[1]=2;
        vec[2]=4;

        for(int i=3; i<n; i++)
            vec[i] = (vec[i-1]+ vec[i-2] + vec[i-3])%1000000009;

        cout<<vec[n-1]<<"\n";
    }
    return 0;
}