#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int subset_sum(int n, int a[], int sum)
{
    // base case
    if (n == 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    // Memoization
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (a[n - 1] <= sum)
    {
        // option 2 ta
        // niye dekhbo, na niye dekhbo
        int op1 = subset_sum(n - 1, a, sum - a[n - 1]);
        int op2 = subset_sum(n - 1, a, sum);
        return dp[n][sum] = op1 + op2;
    }
    else
    {
        // option 1 ta
        // na niyei dekhbo
        return dp[n][sum] = subset_sum(n - 1, a, sum);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s;
    cin >> s;
    //int dp[n + 1][s + 1];
    dp[0][0] = true;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}