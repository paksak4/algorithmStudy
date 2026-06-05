#include <iostream>
#include <algorithm>

using namespace std;

char alpha[15];
int l, c;

char ans[15];

bool check()
{
    int a = 0; // 모음

    for(int i=0; i<l; i++)
    {
        for(char c:{'a', 'e', 'i', 'o', 'u'})
        {
            if(ans[i]==c) // 모음
            {    
                a++;
                break;
            }
        }
    }

    if(a>=1 && l-a>=2)
        return true;
    else
        return false;
}

void rec(int n, int p) // 현재 포함한 수의 갯수, 현재위치
{
    if(n==l) // base condition
    {
        if(check())
        {   
            for(int i=0; i<l; i++)
            cout<<ans[i];
            cout<<"\n";
        }
        return;
    }

    for(int i=p; i<c; i++)
    {
        ans[n] = alpha[i];
        rec(n+1, i+1);
    }
    return;
}

int main(void)
{
    cin>>l>>c;

    for(int i=0; i<c; i++)
        cin>>alpha[i];

    sort(alpha, alpha+c);

    rec(0, 0);

    return 0;
}