#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{   
    int n;
    cin>>n;
    vector<int> vecN(n);
    for(int i=0; i<n; i++)
        cin>>vecN[i];

    int m;
    cin>>m;
    vector<int> vecM(m);
    for(int i=0; i<m; i++)
        cin>>vecM[i];

    sort(vecN.begin(), vecN.end());

    for(int i:vecM)
    {   
        if(binary_search(vecN.begin(), vecN.end(), i))
            cout<<"1\n";
        else
            cout<<"0\n";
    }

    return 0;
}