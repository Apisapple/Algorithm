#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001][2];
int d[100001][3];


int main()
{

    int T;
    cin >> T;
    for (int test_case = 0; test_case < T; test_case++)
    {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++)
            cin >> arr[i][0];

        for(int i = 1; i <= n; i++)
            cin >> arr[i][1];

        d[0][0] = d[0][1] = d[0][2] = 0;

        for (int i = 1; i <= n; i++)
        {
            d[i][0] = max(max(d[i-1][0], d[i-1][1]), d[i-1][2]);
            d[i][1] = max(d[i-1][0], d[i-1][2]) + arr[i][0];
            d[i][2] = max(d[i-1][0], d[i-1][1]) + arr[i][1];
        }
        
        cout << max(max(d[n][0], d[n][1]), d[n][2]) << "\n";
    }
}