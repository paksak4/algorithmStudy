#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, k;
    cin>>n>>k;

    vector<int> vec(k+1); // 현재 칸
    vector<int> tmp(k+1); // 전 칸

    for(int i=0; i<n; i++)
    {
        int w,v; // 무게와 가치
        cin>>w>>v;
        
        for(int j=0; j<k+1; j++) // j는 현재 탐색하는 무게
        {
            vec[j]=tmp[j];
            if(j>=w)
                vec[j]=max(tmp[j-w]+v, vec[j]);
            //cout<<vec[j]<<" ";
        }
        tmp=vec;
        //cout<<"\n";
    }
    cout<<vec[k];

    return 0;
}