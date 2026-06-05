#include <iostream>

int rec(int n, int r, int c)
{
    if(n==1)
    {
        if(r==0 && c==0)
            return 0;
        else if(r==0 && c==1)
            return 1;
        else if(r==1 && c==0)
            return 2;  
        else if(r==1 && c==1)
            return 3;      
    }

    if(r<(1<<(n-1)) && c<(1<<(n-1)))
        return rec(n-1, r, c);
    else if(r<(1<<(n-1)) && c>=(1<<(n-1)))
        return (1<<(2*n-2)) + rec(n-1, r, c-(1<<(n-1)));
    else if(r>=(1<<(n-1)) && c<(1<<(n-1)))
        return (1<<(2*n-1)) + rec(n-1, r-(1<<(n-1)), c);
    else 
        return (1<<(2*n-2))*3 + rec(n-1, r-(1<<(n-1)), c-(1<<(n-1)));
    
}

int main(void)
{
    int n, r, c;
    std::cin>>n>>r>>c;
    std::cout<<rec(n, r, c);
    return 0;
}