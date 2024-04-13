#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = INT_MAX;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    cout << "BEFORE" << endl; // ai loop ta hocche adj matrix ta kmn sta dekhr jnw
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    for (int k = 0; k < n; k++) // 3 ta loop chaliye check krlm
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // cout << i << " " << k << " " << j << endl;
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    cout << "AFTER" << endl; // 3 ta loop chaliye dekhr por dekhbo ki change hoise
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) //  Negative cycle hoile detect korbe
    {
        if (adj[i][i] < 0)
        {
            cout << "Cycle detected" << endl;
            break;
        }
    }
    return 0;
}