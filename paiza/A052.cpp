#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int n, a, b;
    cin>>n>>a>>b;
    vector<bool> stair(n, false);
    stair[0]=true;
    for(int i=1; i<n; i++){
        if((i-a>=0&&stair[i-a])||(i-b>=0&&stair[i-b]))
            stair[i]=true;
    }

    int count=0;
    for(int i=0; i<n; i++){
        if(!stair[i]){
            //cout<<i<<" ";
            count++;
        }
    }

    cout<<count;

    return 0;
}