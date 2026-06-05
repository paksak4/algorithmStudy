#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin>>n;

    vector<int> vec(n); 
    for(int i=0; i<n; i++)
        cin>>vec[i];

    vector<int> cpy = vec;

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for(int i=0; i<n; i++)
        cout<<lower_bound(vec.begin(), vec.end(), cpy[i])-vec.begin()<<" ";
    
    return 0;
}