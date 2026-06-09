#include <iostream>

using namespace std;

int main(void){

    char qr[7][7];

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            cin>>qr[i][j];
        }
    }

    int a=0;
    if(qr[0][0]=='.'){
        for(int i=5; i>0; i--){
            for(int j=5; j>0; j--){
                a<<=1;
                if(qr[i][j]=='#'){
                    a=a|1;
                    //cout<<a<<"\n";
                }
            }
        }
    } else if(qr[0][6]=='.'){
        for(int j=1; j<6; j++){      // 외부: 열
            for(int i=5; i>0; i--){  // 내부: 행
                a<<=1;
                if(qr[i][j]=='#') 
                    a=a|1;
            }
    }
    } else if(qr[6][0]=='.'){
        for(int j=5; j>0; j--){     // 외부: 열
            for(int i=1; i<6; i++){  // 내부: 행
                a<<=1;
                if(qr[i][j]=='#') 
                    a=a|1;
            }
    }
    } else if(qr[6][6]=='.'){
        for(int i=1; i<6; i++){
            for(int j=1; j<6; j++){
                a<<=1;
                if(qr[i][j]=='#'){
                    a=a|1;
                    //cout<<a<<"\n";
                }
            }
        }
    }
    
    cout<<a;

    return 0;
}