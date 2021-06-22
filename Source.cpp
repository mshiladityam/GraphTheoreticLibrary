#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <assert.h>
#include <stack>
#include <string>
#include <numeric>
#include <ctime>
#include <chrono>
#include <random>
#define int long long int
using namespace std;

/*
author: mshiladityam
Object Oriented Programming Graph Theoretic Library for Competitive Programming including major algorithms such as:
1) Prim's Algorithm
2) DSU
3) Djikstra
4) Floyd-Warshall
5) Multi Source BFS
*/

const int INF=1e18;

struct Edge 
{
    int wt = INF, to = -1;
    bool operator<(Edge const& other) const  //comparator function for edge
	{
        return make_pair(wt, to) < make_pair(other.wt, other.to);
    }
};

class Graph
{
public:
	int n;
	vector<vector<pair<int, int>>> adj;
	vector<int> dist;
	Graph(int sz)
	{
		n=sz;
		adj.resize(n+1);
		dist.resize(n+1, INF);
	}
	void add_edge_directed(int u, int v, int w)
	{
		adj[u].push_back(make_pair(v, w));		
	}
	void add_edge_undirected(int u, int v, int w)
	{
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
};

class Djikstra
{
	private:
		vector<int> par; //for retracing Djikstra

	public:	
		Djikstra(Graph G, int source)
		{
			par.resize(G.n+1);
			par[source]=-1;
			G.dist[source]=0;
			set<pair<int, int>> q;
			q.insert(make_pair(0, source));
			while (!q.empty())
			{
				int v=q.begin()->second;
				q.erase(q.begin());
				
				for (auto edge: G.adj[v])
				{
					int to=edge.first;
					int len = edge.second;

					if (G.dist[v] + len < G.dist[to]) 
					{
						q.erase({G.dist[to], to});
						G.dist[to] = G.dist[v] + len;
						par[to] = v;
						q.insert({G.dist[to], to});
					}
				}
			}
		}
		int find_par(int v)
		{
			return par[v];
		}
};

class FloydWarshall
{
	private:
		vector<vector<int>> g;
	public:
		vector<vector<int>> d;
		
		FloydWarshall(Graph G)
		{
			g.resize(G.n+1, vector<int>(G.n+1, INF));	
			int n = G.n;
			for (int j=1; j<=n; j++)
			{
				for (auto edge: G.adj[j])
				{
					g[j][edge.first]=edge.second;
					g[edge.first][j]=edge.second;
				}				
			}
			d=g;
			for (int k = 1; k <= n; k++) 
			{
				for (int i = 1; i <= n; i++) 
				{
					for (int j = 1; j <= n; j++) 
					{
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
		}
};

class DSU 
{
public:
	vector<int> p;
	int n; 
	DSU(int _n) : n(_n) 
	{
		p.resize(n);
		iota(p.begin(), p.end(), 0);
	} 
	int get(int x) 
	{
		return (x == p[x] ? x : (p[x] = get(p[x])));
	} 
	bool unite(int x, int y) 
	{
		x = get(x);
		y = get(y);
		if (x != y) {
		  p[x] = y;
		  return true;
		}
		return false;
	}
};

class Prim
{
private:
	int w;
	vector<pair<int, int>> tree; 
public:

	Prim(Graph G)
	{
		w = 0;
		int n = G.n;
		vector<Edge> min_e(n + 1);
		min_e[1].wt = 0;
		set<Edge> q;
		q.insert({ 1, 0 });
		vector<bool> selected(n + 1, false);
		for (int i = 0; i < n; ++i)
		{
			if (q.empty())
			{
				cout << "No MST exists for the input Graph\n";
				return;
			}

			int v = q.begin()->to;
			selected[v] = true;
			w += q.begin()->wt;
			q.erase(q.begin());

			if (min_e[v].to != -1)	tree.push_back(make_pair(v, min_e[v].to));

			for (auto f : G.adj[v])
			{
				Edge e = { f.first, f.second };
				if ((!selected[e.to]) && e.wt < min_e[e.to].wt)
				{
					q.erase({ min_e[e.to].wt, e.to });
					min_e[e.to] = { e.wt, v };
					q.insert({ e.wt, e.to });
				}
			}
		}
	}
	vector<pair<int, int>> get_edges()
	{
		vector<pair<int, int>> v;
		for (auto e: tree)	v.push_back(e);
	}
	int get_wt()
	{
		return w;
	}
};

class MultisourceBFS //for undirected graphs
{
public:
	MultisourceBFS(Graph G, vector<int> source_vector)
	{
		int n=G.n;
		vector<bool> vis(n+1, false);
		queue<int> q;
		for (auto u: source_vector)
		{
			q.push(u);
			G.dist[u]=0;
		}
		while (!q.empty())
		{
			auto u=q.front();
			q.pop();
			for (auto e: G.adj[u])
			{
				int v=e.first;
				if (!vis[v])
				{
					G.dist[v]=G.dist[u]+1;
					q.push(v);
				}
			}
		}
	}
};

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);	
	return 0;
}
