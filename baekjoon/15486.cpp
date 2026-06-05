#include <iostream>
#include <algorithm>

using namespace std;

int dpp[1500000][3];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {   
        //cout<<"<< "<<i<<" >>\n";
        for(int j=0; j<2; j++)
            cin>>dpp[i][j];
        
        if(i==0)
        {
            dpp[dpp[i][0]+i-1][2] = max(dpp[i][1], dpp[dpp[i][0]+i-1][2]);
            continue;
        }

        dpp[i][2] = max(dpp[i][2], dpp[i-1][2]);
        if(i+dpp[i][0]>n)
            continue;
        
        dpp[dpp[i][0]+i-1][2] = max(dpp[i][1]+dpp[i-1][2], dpp[dpp[i][0]+i-1][2]);
        //cout<<i<<": "<< dpp[i][1]+dpp[i-1][2] <<", "<< dpp[dpp[i][0]+i-1][2]<<"\n";
        // for(int i=0; i<n; i++)
        //     cout<<dpp[i][2]<<" ";
        // cout<<"\n";
    }

    // for(int i=0; i<n; i++)
    //     cout<<dpp[i][2]<<" ";

    cout<<dpp[n-1][2];

    return 0;
}