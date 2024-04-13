#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> v[N];
int dis[N];
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    // queue<pair<int,int>> q; // dijkstra optimized version a ai line ta hobe na
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // queue bad diye priority queue imput nilm
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first; // A = parent/cost
        int cost = parent.second;
        // for(int i = 0; i< v[node].size(); i++)
        //{
        //   pair<int,int> child = v[node][i];
        //}
        for (pair<int, int> child : v[node])
        {
            int childnode = child.first; // B = children
            int childcost = child.second;
            if (cost + childcost < dis[childnode])
            {
                // path relax hobe
                dis[childnode] = cost + childnode;    // distance ta update krlm
                pq.push({childnode, dis[childnode]}); // update distance ke push krlm
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
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    // memset(dis, INT_MAX, sizeof(dis)); ata likhle jhamela krbe
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << dis[i] << endl; // ans = 0 6 5 4 9 asbe
    }
    return 0;
}
