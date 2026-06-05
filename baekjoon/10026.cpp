//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(void)
{
    int n; // n;
    cin>>n;

    char array[100][100]; // 색 정보 담아놓을 배열
    int visit[100][100] = {0,}; // 방문 여부 담을 배열
    
    for(int i=0; i<n; i++)
    {
        string str;
        cin>>str;
        for(int j=0; j<n; j++)
        {
            array[i][j] = str[j];
        }
    }

    queue<pair<int, int>> que;
    int total=0;

    for(int x=0; x<n; x++)
    {
        for(int y=0; y<n; y++)
        {
            if(visit[x][y]==0)
            {
                que.push({x,y});
                total++;

                //cout<<x<<", "<<y<<"넣고 "<<total<<endl;

                while(!que.empty())
                {        
                    int cx = que.front().first;
                    int cy = que.front().second;
                    char cc = array[cx][cy]; 
                    visit[cx][cy]=1;

                    for(int i=0; i<4; i++)
                    {
                        int mcx = cx+dx[i];
                        int mcy = cy+dy[i];
                        if((mcx >= 0 && mcx < n) && (mcy>=0 && mcy<n) && array[mcx][mcy]==cc && visit[mcx][mcy]==0)
                        {
                            visit[mcx][mcy]=1;
                            que.push({mcx, mcy});
                            //cout<<cx<<", "<<cy<<"에서 "<<mcx<<", "<<mcy<<"담음"<<endl;
                        }
                    }
                    que.pop();
                }   
            }
        }
    }
    
    cout<<total<<" ";

    //cout<<"================================\n";
    //cout<<que.empty()<<endl;

    total=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(array[i][j]=='G')
                array[i][j] = 'R';
        }
    }

    for(int x=0; x<n; x++)
    {
        for(int y=0; y<n; y++)
        {
            if(visit[x][y]==1)
            {
                que.push({x,y});
                total++;

                //cout<<x<<", "<<y<<"넣고 "<<total<<endl;

                while(!que.empty())
                {        
                    int cx = que.front().first;
                    int cy = que.front().second;
                    char cc = array[cx][cy]; 
                    visit[cx][cy]=2;

                    for(int i=0; i<4; i++)
                    {
                        int mcx = cx+dx[i];
                        int mcy = cy+dy[i];
                        if((mcx >= 0 && mcx < n) && (mcy>=0 && mcy<n) && array[mcx][mcy]==cc && visit[mcx][mcy]==1)
                        {
                            visit[mcx][mcy]=2;
                            que.push({mcx, mcy});
                            //cout<<cx<<", "<<cy<<"에서 "<<mcx<<", "<<mcy<<"담음"<<endl;
                        }
                    }
                    que.pop();
                }   
            }
        }
    }
    
    cout<<total;

    return 0;
}