#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(void)
{
    unordered_set<string> uset;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string name, record;
        cin>>name>>record;
        if(record=="enter")
            uset.insert(name);
        else if(record=="leave")
            uset.erase(name);
    }
    vector<string> ans(uset.begin(), uset.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(string s : ans)
        cout<<s<<"\n";
    return 0;
}