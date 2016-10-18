#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef pair<ll,ll> llll;

#define pb push_back
#define fi first
#define se second
#define DEBUG if(0)
#define VISITED 2
#define EXPLORED 1
#define UNVISITED 0
#define MAX 1000
#define pb push_back
#define EPS 1e-9
#define INF 1<<20
#define inf 0x3f3f3f3f
#define DEG_to_RAD(x) (x/180.0)*M_PI
#define RAD_to_DEG(x) (x*180.0)/M_PI
#define MIN_to_DEG(x) x/60.0
#define in( l1, x, l2 ) l1 <= x && x <= l2 ? true : false
#define EQUAL(a,b) fabs(a-b) < EPS

vvi AdjMatrix;
vvi AdjList;
int max_flow, flow;
vi parent;

void init(int v)
{
    AdjMatrix.resize(v);
    AdjList.resize(v);
    parent.resize(v,-1);
    for (int i = 0; i < v; ++i)
        AdjMatrix[i].resize(v);
}

void augment(int v, int minEdge, int saida, int entrada) {
    if(v == saida) 
    {
        flow = minEdge; 
        return;
    }
    else if(parent[v] != -1)
    {
        augment(parent[v], min(minEdge, AdjMatrix[parent[v]][v]),saida,entrada);
        AdjMatrix[parent[v]][v] -= flow;
        AdjMatrix[v][parent[v]] += flow;
    }
}

int maxflow(int saida, int entrada)
{
    max_flow = 0;
    while(1)
    {
        flow = 0;
        bitset<MAX> vis; vis[saida] = true;
        queue<int>q; q.push(saida);
        parent.assign(MAX, -1);
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            if(u == entrada) 
                break;
            for(auto v : AdjList[u])
            {
                if(AdjMatrix[u][v] > 0 && !vis[v])
                {
                    vis[v] = true, q.push(v), parent[v] = u;
                }
            }
        }
        augment(entrada, INF,saida,entrada);
        if(flow == 0)break;
        max_flow+=flow;
    }
    return max_flow;
}

int main()
{
    int vertices, arestas;
    cin >> vertices >> arestas;
    init(vertices);
    for(int i = 0; i < arestas; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].pb(v);
        AdjList[v].pb(u);
        AdjMatrix[u][v] = w;
    }
    int entrada, saida;
    cout << maxflow( entrada,  saida) << endl;
}
