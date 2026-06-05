#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int n, m;
    cin>>n>>m;
    string str;
    cin>>str;
    vector<int> vec(m);
    if(str[0]=='I'&&str[1]=='O'&&str[2]=='I')
        vec[0]=1;
    if(m==3)
    {
        cout<<vec[0];
        return 0;
    }
    if(str[1]=='I'&&str[2]=='O'&&str[3]=='I')
        vec[1]=1;
    for(int i=2; i<m-2; i++)
    {
        if(str[i]=='I'&&str[i+1]=='O'&&str[i+2]=='I')
            vec[i]=vec[i-2]+1;
        else
            vec[i]=0;
    }
    int total=0;
    for(int i=0; i<m-2; i++)
        if(vec[i]>=n)
            total++;
    cout<<total;
    return 0;
}