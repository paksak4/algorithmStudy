#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n; // 도시 개수
    cin>>n;

    long long total = 0; // 총 필요한 기름의 가격
    //int dis = 0; // 더해진 거리

    vector<pair<long long, long long>> vec(n);
    for(int i=0; i<n-1; i++)
        cin>>vec.at(i).second; // 거리 입력받음
    vec.at(n-1).second=0;
    
    for(int i=0; i<n; i++)
        cin>>vec.at(i).first; // 리터당 가격 입력 받음

    long long price = vec.at(0).first; // 현재 가장 싼 가격

    for(int i=0; i<n; i++)
    {
        if(vec.at(i).first>=price)
        {
            total+=price*vec.at(i).second;
        }
        else
        {
            price=vec.at(i).first;
            total+=price*vec.at(i).second;
        }
    }

    cout<<total;

    return 0;
}