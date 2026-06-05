#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int S = 0; // 비트마스킹으로

    int m;
    cin>>m;

    while(m--)
    {
        string str;
        cin>>str;
        int s;

        if(str=="add")
        {
            cin>>s;
            S|=(1<<(s-1));
        }
        else if(str=="remove")
        {
            cin>>s;
            S&=~(1<<(s-1));
        }
        else if(str=="check")
        {
            cin>>s;
            if(S&(1<<(s-1)))
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        else if(str=="toggle")
        {
            cin>>s;
            S^=(1<<(s-1));
        }
        else if(str=="all")
        {
            S=(1<<20)-1;
        }
        else if(str=="empty")
        {
            S=0;
        }
    }

    return 0;
}