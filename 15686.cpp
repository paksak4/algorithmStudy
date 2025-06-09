#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int n, m;
int total=INT_MAX;
vector<pair<int, int>> srcChknList;
vector<pair<int, int>> house; // 집 위치 좌표 저장
vector<pair<int, int>> chkn; // 치킨 집 위치 좌표 저장

void srcChkn(int s, int index)
{
    if(index==m) // base condition
    {
        //for(int i=0; i<m; i++)
        //    cout<<srcChknList[i].first<<", "<<srcChknList[i].second<<"\n";

        int sum=0;
        for(int i=0; i<house.size(); i++)
        {
            int result = INT_MAX;
            for(int j=0; j<srcChknList.size(); j++)
            {
                int d = abs(house[i].first-srcChknList[j].first)+abs(house[i].second-srcChknList[j].second);
                result=min(result, d);
            }
            //cout<<house[i].first<<", "<<house[i].second<<"에서\n";
            //cout<<"거리: "<<result<<"\n\n";
            sum+=result;
        }
        total=min(total, sum);
        return ;
    }

    for(int i=s; i<chkn.size(); i++)
    {
        srcChknList[index]=chkn[i];
        srcChkn(i+1, index+1);
    }
}

int main(void)
{
    cin>>n>>m;
    srcChknList.resize(m);
    for(int i=0; i<n; i++)
    {    
        for(int j=0; j<n; j++)
        {
            int p;
            cin>>p;
            if(p==1) // 집일 경우
                house.push_back({i, j});
            else if(p==2) // 치킨집일 경우
                chkn.push_back({i, j});
        }
    }
    // for(int i=0; i<chkn.size(); i++)
    //     cout<<chkn[i].first<<", "<<chkn[i].second<<"\n";
    srcChkn(0, 0); 
    cout<<total;
    return 0;
}