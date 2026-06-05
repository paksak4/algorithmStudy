// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main(void)
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int n, m;
//     cin>>n>>m;
//     vector<pair<int, int>> item(n); // 메모리와 비용

//     int totalM = 0;
//     int totalC = 0;
//     for(int i=0; i<n; i++)
//     {
//         cin>>item[i].first;
//         totalM+=item[i].first;
//     }
//     for(int i=0; i<n; i++)
//     {
//         cin>>item[i].second;
//         totalC+=item[i].second;
//     }

//     vector<int> vec(totalM+1);
//     vector<int> tmp(totalM+1);

//     for(pair<int, int> p : item)
//     {
//         for(int i=0; i<=totalM; i++)
//         {
//             vec[i]=tmp[i];
//             if(i>=p.first)
//                 vec[i]=min(vec[i], vec[i-p.first]+p.second);
//             cout<<vec[i]<<" ";
//         }
//         cout<<"\n";
//         tmp=vec;
//     }
    
    
//     return 0;
// }