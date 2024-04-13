#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; // adjacency matrix list
bool vis[N];
bool pathVis[N];
vector<int> adj[N]; // adjacency matrix
bool cycle;
void dfs(int parent)
{
    vis[parent] = true; // parent ke visit krlm
    pathVis[parent] = true; //path r parent ke visit korlm
    cout << parent << endl;       // pareent asche ki na print kore dekhlm
    for (int child : adj[parent]) // pareent thke child ber korlm
    {
        if (pathVis[child]) // child gulo pathvis a ache ki na check korlm  
        {
            cycle = true; // cycle ache 
        }
        if (!vis[child]) // child gulo visited na hoile 
        {
            dfs(child); // recursion call krbo
        }
    }
    // kaj ses
    pathVis[parent] = false; //kaj ses tai path vis thke o remove kore dibo
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
        // adj[b].push_back(a); // adj matrix b te a ke push korlm ,bt directed graph a ai line hbe na
    }
    memset(vis, false, sizeof(vis));
    memset(pathVis, -1, sizeof(pathVis));
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
    return 0;
}