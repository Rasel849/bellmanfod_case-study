#include<bits/stdc++.h>
using namespace std;
bool neg_cycle = false;
bool bellman(int node,int edge,int start_vertex[],int connect_vertex[],int wt[],int dis[])
{
    for(int j=1; j<=node; j++)
    {
        bool update = false;
        for(int i=1; i<=edge; i++)
        {
            int u = start_vertex[i];
            int v = connect_vertex[i];
            int w = wt[i];
            if(dis[u] + wt[i] < dis[v])
            {
                update = true;
                if(j==node)
                    neg_cycle = true;
                dis[v] = dis[u] + wt[i];
            }
        }
        if(update == false)
            break;
    }
    }
int main()
{
    int node, edge;
    cin >> node >> edge;
    int start_vertex[edge], connect_vertex[edge], edge_wt[edge];
    for(int i=1; i<=edge; i++)
    {
         cin >> start_vertex[i] >> connect_vertex[i] >> edge_wt[i];
    }
    int source;
    cin>> source;
     int dis[node];
    for(int i=1; i<=node; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[source] = 0;
    bellman( node, edge,start_vertex,connect_vertex, edge_wt, dis);
    if(neg_cycle == false)
    {
        cout << "Distance of node: " << '\n';
        for(int i=1; i<=node; i++)
            cout << i << " -> " << dis[i] << '\n';
    }
    else 
        cout << "\nNegative Cycle detected" << '\n';
    return 0;
}
