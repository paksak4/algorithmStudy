#include <iostream>
#include <algorithm>


int n;
int total=0;
bool visit1[15]={false,}; // 세로
bool visit2[30]={false,}; // 좌하-우상 대각선
bool visit3[30]={false,}; // 좌상-우하 대각선

void req(int t) // 현재 x좌표
{
    if(t==n)
    {    
        total++;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(!visit1[i] && !visit2[t+i] && !visit3[t-i+n-1])
        {
            visit1[i]=visit2[t+i]=visit3[t-i+n-1]=true;
            req(t+1);
            visit1[i]=visit2[t+i]=visit3[t-i+n-1]=false;
        }
    }
    return;
}

int main(void)
{
    std::cin>>n;

    int board[15][15]={0, };
    req(0);
    std::cout<<total;

    return 0;
}