#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           // mat[i][j] = 0;
            mat[i][j] = -1; // weighted graph r jnw
            if (i == j)
               // mat[i][j] = 1;
            mat[i][j] = 0; // weighted graph r jnw
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        //mat[a][b] = 1;
        //mat[a][b] = 1;
        mat[a][b] = c; // weighted graph r jnw
        mat[b][a] = c; // weighted graph r jnw
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}