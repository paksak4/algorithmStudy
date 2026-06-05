#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    int n;
    cin>>n;

    vector<pair<int, int>> vec(n+1);
    vec[1]={0,0};
    
    for(int i=2; i<=n; i++)
    {
        pair<int, int> min = {vec[i-1].first, i-1}; // 최소값과 어디서 왔는지
        if(i%3==0 && vec[i/3].first<min.first)
            min = {vec[i/3].first,i/3};
        if(i%2==0 && vec[i/2].first<min.first)
            min = {vec[i/2].first,i/2};
        
        vec[i]=min;
        vec[i].first++;
    }

    cout<<vec[n].first<<"\n";
    while(n)
    {
        cout<<n<<" ";
        n=vec[n].second;
    }

    return 0;
}