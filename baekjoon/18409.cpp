#include <iostream>
#include <string>

int main(void)
{
    int n;
    std::cin>>n;
    std::string str;
    std::cin>>str;
    int total=0;
    for(char c:str)
        if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o')
            total++;
    std::cout<<total;
    return 0;
}