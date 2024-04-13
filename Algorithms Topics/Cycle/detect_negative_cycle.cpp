#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1e5 + 5;
int dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList; // input gulo akta Edgelist a rakhlm
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
        EdgeList.push_back(Edge(v, u, c)); // undirected graph hoile ai line ta add hobe
    }
    // for(Edge ed : EdgeList) // input a nisi seta check korbo
    //{
    //    cout << ed.u << " " << ed.v << " " << ed.c << endl;
    //}
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX; // distance array sb gulo infinity kore dilam
    }
    dis[0] = 0;
    for (int i = 1; i <= n; i++) // O(N) // ai loop ta hocche n-1 ber chalanor jnw
    {
        for (Edge ed : EdgeList) // O(E)
        {
            int u, v, c; //  TOTAL TIME COMPLEXITY = O(V*E)
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool cycle = false; // akhan thke check korlm arek br cycle ase ki na
    for (Edge ed : EdgeList) // O(E)
    {
        int u, v, c; //  TOTAL TIME COMPLEXITY = O(V*E)
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "cycle found, no answer" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "->" << dis[i] << endl; // 0 7 5 10 output asbe
        }
    }
    return 0;
}