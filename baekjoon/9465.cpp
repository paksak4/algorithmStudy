#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> v(3, vector<int>(n,0));
        for(int i=0; i<2; i++)
            for(int j=0; j<v[i].size(); j++)
                cin>>v[i][j];

        for(int i=1; i<n; i++)
        {
            v[0][i]=max(v[1][i-1],v[2][i-1])+v[0][i];
            v[1][i]=max(v[0][i-1],v[2][i-1])+v[1][i];
            v[2][i]=max(v[0][i-1],v[1][i-1]);
        }

        cout<<max(v[0][n-1], max(v[1][n-1], v[2][n-1]))<<"\n";
    }
    
    return 0;
}