#include <iostream>
#include <stack>

//int k = 0;

void rec(int a, int b, int n) 
// 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수
{
    if(n==1)
    {   
        //k++;
        std::cout<<a<<" "<<b<<"\n";
        return;
    }

    rec(a, 6-a-b, n-1);
    //k++;
    rec(a, b, 1);
    rec(6-a-b, b, n-1);

    return;
}

int main(void)
{
    int n;
    std::cin>>n;

    std::cout<<(1<<n)-1<<"\n";
    rec(1, 3, n);

    return 0;
}