#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    vector<int> alpha1(26);
    vector<int> alpha2(26);
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;
    for(char c : str1)
        alpha1[c-'a']++;
    for(char c : str2)
        alpha2[c-'a']++;
    int total=0;
    for(int i=0; i<26; i++)
        total+=(alpha1[i]>alpha2[i]?alpha1[i]-alpha2[i]:alpha2[i]-alpha1[i]);
    cout<<total;

    return 0;
}