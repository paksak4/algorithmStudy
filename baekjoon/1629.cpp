#include <iostream>

long long mul(long a, long b, long c)
{
    if(b==1)
        return a%c;
    
    if(b%2==1)
        return mul(a, 1, c)*mul(a, b-1, c) % c;
    else
    {
        long long r = mul(a, b/2, c) % c;
        return (r*r)%c;
    }
}

int main(void)
{
    long long a,b,c;
    std::cin>>a>>b>>c;

    std::cout<<mul(a, b, c);

    return 0;
}