#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a<b;
}

int main(void)
{
    int n;
    cin>>n;

    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec.at(i);

    sort(vec.begin(), vec.end(), compare);

    // for(int i=0; i<n; i++)
    //     cout<<vec.at(i)<<" ";
    
    int total=0;
    int wait=0;

    //cout<<"\n";

    for(int i=0; i<n; i++)
    {
        //cout<<vec.at(i)+total<<endl;
        wait+=vec.at(i);
        total+=wait;
        //cout<<"합: "<<total<<endl;
    }

    cout<<total;

    return 0;
}
