// Program for Factorial of a NUmber 


#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if(n==0 || n==1) // base case 
    {
        return n;
    }
    int ans = fibo(n-1) + fibo(n-2); //agr & porer value // 2^N time complexity
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}