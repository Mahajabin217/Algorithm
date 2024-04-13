#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int weight[], int value[], int w)
{
    // base case 
    if (n < 0 || w == 0) //n 0 thke chtw ba bag r weight 0 hte prbe na
        return 0;
    if (weight[n] <= w)
    {
        // option 2 ta
        //  niye dekhbo, na niye dekhbo
        int op1 = knapsack(n - 1, weight, value, w - weight[n]) + value[n]; // choose kore disi tai value add krte hbe
        int op2 = knapsack(n - 1, weight, value, w);                        // choose kori ni
        return max(op1, op2);
    }
    else
    {
        // option 1 ta
        // na niyei dekhtye hbe
        int op2 = knapsack(n - 1, weight, value, w); // r jayga nai bag a tai choose korte pari ni
        return op2;
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
    cout << knapsack(n, weight, value, w) << endl;
    return 0;
}