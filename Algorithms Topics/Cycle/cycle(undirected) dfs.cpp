#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; // adjacency matrix list
bool vis[N];
vector<int> adj[N]; // adjacency matrix
int parentArray[N]; // parent ke track rakhlm
bool cycle;
void dfs(int parent) // dfs implement korlm
{
    vis[parent] = true; // parent ke visit krlm 
    cout << parent << endl; // pareent asche ki na print kore dekhlm 
    for(int child : adj[parent]) // pareent thke child ber korlm
    {
        if(vis[child] == true && child != parentArray[parent]) // child gulo visit koreche & parentArray r parent jate child na hoy check korlm
        {
            cycle = true; // cycle ache 
        }
        if(vis[child] == false) //child gulo jdi visit koreche ki na check korlm
        {
            parentArray[child] = parent; // parent ke update korlm 
            dfs(child); // recursion call hoise 
        }
    }
}
int main()
{
    int n, e; // node & edge input nilam
    cin >> n >> e;
    while (e--)
    {
        int a, b; // edge r value input nilm 
        cin >> a >> b;
        adj[a].push_back(b); // adj matrix a te b ke push korlm
        adj[b].push_back(a); // adj matrix b te a ke push korlm
    }
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (cycle) // cycle ache ki na check krlm
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    // ai loop ta parent gulo dekhr jnw ... oporer if condition bd diye dite hobe ata check krle

    for(int i = 0; i<n; i++)
    {
        cout << parentArray[i] << " ";  // output :(-1 0 1 -1 3 4 5) parent gulo thik motw asche ki na check korlm
    }
    return 0;
}