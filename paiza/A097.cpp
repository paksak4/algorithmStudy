#include <iostream>
#include <vector>

using namespace std;

struct RGB{
    int r, g, b;
};

RGB goal;
int n;
vector<RGB> vec(15);

void src(RGB now, int cnt, int sel){
    //cout<<"\n"<<now.r<<" "<<now.g<<" "<<now.b<<" "<<"\n";
    if(cnt==n){
        if(sel==0){
            return;
        }
        RGB result;
        result.r=now.r/sel;
        result.g=now.g/sel;
        result.b=now.b/sel;
        if(result.r==goal.r && result.g==goal.g && result.b==goal.b) {
            cout<<"Yes";
            exit(0);
        }
        return;
    }

    src(now, cnt+1, sel);
    src({now.r+vec[cnt].r, now.g+vec[cnt].g, now.b+vec[cnt].b}, cnt+1, sel+1);
}

int main(void){

    cin>>goal.r>>goal.g>>goal.b;
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>vec[i].r>>vec[i].g>>vec[i].b;  
    }

    src({0,0,0}, 0, 0);

    cout<<"No";

    return 0;
}