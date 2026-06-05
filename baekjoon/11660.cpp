#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> map(n+1, vector<int>(n+1));
    for(int i=1; i<n+1; i++)
    {
        int total=0;
        for(int j=1; j<n+1; j++)
        {
            scanf("%d", &map[i][j]);
            total+=map[i][j];
            map[i][j]=total;
        }
    }
    while(m--)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int sum=0;
        for(int i=x1; i<=x2; i++)
            sum+=(map[i][y2]-map[i][y1-1]);
        printf("%d\n", sum);
    }
    return 0;
}