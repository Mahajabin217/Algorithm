#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; // adjacency matrix list
bool vis[N];
vector<int> adj[N]; // adjacency matrix
int parentArray[N]; // parent ke track rakhlm
bool cycle;
void bfs(int s) // bfs implement
{
    queue<int> q;  // qeueu input nilm
    q.push(s);     // source ke q te push korlm
    vis[s] = true; // souce ke visit korlm
    while (!q.empty())
    {
        int parent = q.front();       // q khali na hoya prjntw parent ber krbo
        cout << parent << endl;       // parent gulo print krbo (0-6) prjntw
        q.pop();                      // q thke parent br krbo
        for (int child : adj[parent]) // adj list r pareent thke child ber kore anbo
        {
            if (vis[child] == true && parentArray[parent] != child) // vis child hobe & parent r parent child jate na hoy thlei cyle hbe
            {
                cycle = true; // cycle ache
            }
            if (!vis[child]) // check krbo child gulo visited ki na
            {
                vis[child] = true;           // child visited na thkle visit kore dao
                parentArray[child] = parent; // child r parent hocche parentArray
                q.push(child);               // child gulo ke q te push kore dibo
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
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
            bfs(i);
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