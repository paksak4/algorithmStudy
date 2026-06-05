#include <iostream>
#include <string>
#include <queue>

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

using namespace std;

typedef struct 
{
    int z,x,y,time;
} cord;


int main(void)
{
    while(true)
    {
        int l,r,c;
        cin>>l>>r>>c;

        if(l==0&&r==0&&c==0)
            break;

        char board[30][30][30] = {'.'};
        queue<cord> que;
        cord end;

        for(int i=0; i<l; i++)
        {    
            //string s;
            for(int j=0; j<r; j++)
            {
                string str;
                cin>>str;
                for(int k=0; k<c; k++)
                {    
                    board[i][j][k] = str[k];
                    if(board[i][j][k]=='S')
                    {
                        que.push({i,j,k,0});
                        board[i][j][j]='V';
                    }
                }
            }
            //cin>>s;
        }

        bool check=true;

        while(!que.empty() && check)
        {
            cord cp = que.front(); // 현재 탐색하는 위치
            que.pop();

            for(int i=0; i<6; i++)
            {
                if(cp.z+dz[i]<0||cp.z+dz[i]>l-1||cp.x+dx[i]<0||cp.x+dx[i]>r-1||cp.y+dy[i]<0||cp.y+dy[i]>c-1)
                    continue;
                if(board[cp.z+dz[i]][cp.x+dx[i]][cp.y+dy[i]]!='.'&&board[cp.z+dz[i]][cp.x+dx[i]][cp.y+dy[i]]!='E')
                    continue;
                if(board[cp.z+dz[i]][cp.x+dx[i]][cp.y+dy[i]]=='E')
                {
                    end={cp.z+dz[i],cp.x+dx[i],cp.y+dy[i],cp.time+1};
                    check=false;
                    break;
                }
                board[cp.z+dz[i]][cp.x+dx[i]][cp.y+dy[i]]='V';
                que.push({cp.z+dz[i],cp.x+dx[i],cp.y+dy[i],cp.time+1});
            }
        }
        if(!check)
            printf("Escaped in %d minute(s).\n", end.time);
        else
            cout<<"Trapped!\n";
    }
    return 0;
}