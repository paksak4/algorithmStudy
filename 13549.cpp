#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    int n, k;
    cin>>n>>k;
    vector<int> board(100001, -1); 
    // index에는 몇 초에 도착했는지 정보 담음, -1은 아직 방문x
    deque<int> deq; 
    // t초와 t+1초만 존재하므로 앞은 t초 삽입, 뒤에는 t+1초 삽입하는 데큐
    deq.push_front(n);
    board[n]=0;
    while(!deq.empty())
    {
        int index = deq.front();
        if(index==k)
            break;
        deq.pop_front();
        if(index*2>=0 && index*2<=100000 && board[index*2]==-1)
        //  범위 안에 있고 방문하지 않았다면
        {   
            board[index*2]=board[index];
            deq.push_front(index*2);
        }
        for(int i:{index-1, index+1})
        {
            if(i<0 || i>100000 || board[i]!=-1)
                continue;
            board[i]=board[index]+1;
            deq.push_back(i);
        }
    }
    cout<<board[k];
    return 0;
}