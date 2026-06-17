#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int n;
    cin>>n;

    vector<long long> vec(n+2, 0);
    for(int i=1; i<n+1; i++){
        cin>>vec[i];
    }

    vector<long long> result(n+2, (long long)0);
    long long sum=0;
    for(int i=2; i<n; i++){
        long long a = vec[i-1]+vec[i]*vec[i]+vec[i+1];
        result[i]=a*a;
        //cout<<result[i]<<" ";
        //cout<<a<<" "<<result[i]<<"\n";
        sum+=result[i];
    }
    cout<<"\n"<<sum<<"\n";

    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        long long x, y;
        cin>>x>>y;
        vec[x]=y;

        if(x>1&&x<n) {
            long long temp=(vec[x-1]+vec[x]*vec[x]+vec[x+1])*(vec[x-1]+vec[x]*vec[x]+vec[x+1]);
            //cout<<x<<": "<<temp<<"\n";
            sum-=result[x];
            sum+=temp;
            result[x]=temp;
        }
        if(x>2) {
            long long temp=(vec[x-2]+vec[x-1]*vec[x-1]+vec[x])*(vec[x-2]+vec[x-1]*vec[x-1]+vec[x]);
            //cout<<x-1<<": "<<temp<<"\n";
            sum-=result[x-1];
            sum+=temp;
            result[x-1]=temp;
        }
        if(x<n-1) {
            long long temp=(vec[x]+vec[x+1]*vec[x+1]+vec[x+2])*(vec[x]+vec[x+1]*vec[x+1]+vec[x+2]);
            //cout<<x+1<<": "<<temp<<"\n";
            sum-=result[x+1];
            sum+=temp;
            result[x+1]=temp;
        }
        
        cout<<sum<<"\n";
    }

    return 0;
}