// #include <iostream>

// using namespace std;

// int n, s;
// int arr[20];
// int total=0; // 총 개수
// int cNum=0; // 현재까지의 누적 합

// void req(int t, int count) // 배열에서 현재 탐색하는 위치
// {
//     if(t>=n) // base condition
//         return;

//     if(cNum==s && count!=0)
//     {
//         total++;
//         //cout<<total<<"\n\n";
//     }
    
//     for(int i=t; i<n; i++)
//     {
//         cNum+=arr[i];
//         // cout<<arr[i]<<" 담음, 누적 수: "<<cNum<<"\n";
//         count++;
//         req(i+1);
//         cNum-=arr[i];
//         count--;
//         // cout<<arr[i]<<" 뺌, 누적 수: "<<cNum<<"\n";
//     }
// }

// int main(void)
// {
//     cin>>n>>s; // n개를 입력받아 합이 s가 되는 수열의 개수
//     for(int i=0; i<n; i++)
//         cin>>arr[i];

//     req(0);
//     cout<<total;

//     return 0;
// }