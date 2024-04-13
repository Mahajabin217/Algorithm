#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 5;
ll dp[N];
ll fibo(ll n)
{
    if (n == 0 || n == 1) // base case
    {
        return n;
    }
    if (dp[n] != -1) // 1. ans ta save ase ki na check korlm
    {
        return dp[n];
    }
    // 2. ans jodi save na thke thle ans ta ber krlm
    ll ans = fibo(n - 1) + fibo(n - 2); // agr & porer value // O(N) time complexity
    dp[n] = ans;                        // 3. save ans ta tare diye dao
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fibo(n) << endl;
    return 0;
}