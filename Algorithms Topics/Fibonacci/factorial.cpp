#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{
    // base case
    if (n == 0)    //O(N)
    {
        return 1;
    }
    int chotw_fact = fact(n - 1); //recursive hoyeche dp hoy ni
    return chotw_fact * n;
}
int main()
{
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++)  //O(N)
    {
        ans *= i;
    }
    // cout << fact << endl;
    cout << ans << endl;
    return 0;
}