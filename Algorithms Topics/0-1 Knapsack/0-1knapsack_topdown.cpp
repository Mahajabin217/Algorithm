#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000;
const int maxW = 1000;
int dp[maxN][maxW];
int knapsack(int n, int weight[], int value[], int w) // O(n*w) time complexity
{
    // base case
    if (n == 0 || w == 0) // n 0 thke chtw ba bag r weight 0 hte prbe na
        return 0;
    if (dp[n][w] != -1) // Memoization korechi
    {
        return dp[n][w];
    }
    if (weight[n - 1] <= w)
    {
        // option 2 ta
        //  niye dekhbo, na niye dekhbo
        int op1 = knapsack(n - 1, weight, value, w - weight[n-1]) + value[n - 1]; // choose kore disi tai value add krte hbe
        int op2 = knapsack(n - 1, weight, value, w);                            // choose kori ni
        return dp[n][w] = max(op1, op2);                                        // ans ta save kore tr pr max return krbe
    }
    else
    {
        // option 1 ta
        // na niyei dekhtye hbe
        int op2 = knapsack(n - 1, weight, value, w); // r jayga nai bag a tai choose korte pari ni
        return dp[n][w] = op2;                       // ans ta save kore tr pr return krbe
    }
}
int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int w;
    cin >> w;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, weight, value, w) << endl;
    return 0;
}