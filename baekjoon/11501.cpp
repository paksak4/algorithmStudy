#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        //cout<<"입력\n";
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0; i<n; i++)
            cin>>vec[i];
        int k=vec[n-1]; // 파는 가격
        long long total=0;
        for(int i=n-1; i>=0; i--)
        {
            if(vec[i]<=k)
                total+=(k-vec[i]);
            else
                k=vec[i];
        }
        cout<<total<<"\n";
    }
    return 0;
}