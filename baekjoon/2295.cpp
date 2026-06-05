#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    vector<int> vec1(n);
    for(int i=0; i<n; i++)
        cin>>vec1[i];
    vector<int> vec2;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            vec2.push_back(vec1[i]+vec1[j]);
    sort(vec2.begin(), vec2.end());
    int max=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(binary_search(vec2.begin(), vec2.end(), vec1[j]-vec1[i]))
            {
                if(vec1[j]>max)
                    max=vec1[j];
            }
        }
    }
    cout<<max;
    return 0;
}