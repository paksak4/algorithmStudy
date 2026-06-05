#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int n, m;
    cin>>n>>m;

    vector<int> num(n, 1);
    int max=0;

    for(int i=0; i<m; i++){
        int win, lose;
        cin>>win>>lose;
        num[win-1]+=num[lose-1];
        if(num[win-1]>max)
            max=num[win-1];
    }

    for(int i=0; i<n; i++){
        if(num[i]>=max){
            cout<<i+1<<"\n";
        }
    }

    return 0;
}

