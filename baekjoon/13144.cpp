#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    vector<int> vec(n);
    vector<bool> check(100001);
    for(int i=0; i<n; i++)
        cin>>vec[i];
    long long total=0;
    int end=0;
    for(int start=0; start<n; start++)
    {
        while(end<n&&!check[vec[end]])
        {
            check[vec[end]]=true;
            end++;
        }
        total+=(end-start);
        check[vec[start]]=false;
    }
    cout<<total;
    return 0;
}