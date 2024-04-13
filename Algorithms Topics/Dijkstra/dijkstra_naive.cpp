#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int,int>> v[N];
int dis[N];
void dijkstra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;
    while(!q.empty())
    {
        pair<int,int> parent = q.front();
        q.pop();
        int node = parent.first; // A = parent/cost 
        int cost = parent.second;
        //for(int i = 0; i< v[node].size(); i++)
        //{
          //  pair<int,int> child = v[node][i];
        //}
        for(pair<int,int> child : v[node])
        {
            int childnode = child.first; // B = children 
            int childcost = child.second;
            if(cost + childcost < dis[childnode])
            {
                // path relax hobe
                dis[childnode] = cost+childnode; // distance ta update krlm 
                q.push({childnode,dis[childnode]}); // update distance ke push krlm
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
        int a, b , c;
        cin >> a >> b >> c;
        v[a].push_back({b,c}); 
        v[b].push_back({a,c}); 
    }
    //memset(dis, INT_MAX, sizeof(dis)); ata likhle jhamela krbe 
    for(int i = 0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for(int i = 0; i<n; i++)
    {
        cout << i << "->" << dis[i] << endl; // ans = 0 6 5 4 9 asbe
    }
    return 0;
}
