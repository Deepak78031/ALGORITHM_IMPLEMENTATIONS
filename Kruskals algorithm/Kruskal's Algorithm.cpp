//Minimum Spanning Tree Using Kruskals Algorithm
#include<bits/stdc++.h>
using namespace std;

struct Graph
{
    int V, E;
    vector< pair<int, pair<int, int> > > edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();
};

struct DisjointSets
{
    int *parent, *rnk;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        for (int i = 0; i <= n; i++)
        {
            //Initially every node is it's own parent and they have a rank of 0 as the size of it's set is 1
            rnk[i] = 0;
            parent[i] = i;
        }
    }

    // Find the parent of a node 'u'
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        // Tree with more depth becomes the parent of the other node
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

int Graph::kruskalMST()
{
    int MST_wt = 0;

    //Sort edges in increasing order on basis of weight
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    DisjointSets ds(V);

    // Iterate through all sorted edges
    vector< pair<int, pair<int, int> > >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // Check if the selected edge is creating a cycle or not
        if (set_u != set_v)
        {
            cout << u << " - " << v << endl;
            MST_wt += it->first;
            ds.merge(set_u, set_v);
        }
    }

    return MST_wt;
}

int main()
{
    int V,E;
    cout<<"Enter number of nodes and number of edges in the graph\n";
    cin>>V>>E;

    Graph g(V, E);

    for(int i=1; i<=E; i++){
        int weight,first,second;
        cout<<" \nEDGE "<<i<<endl;
        cout<<"========"<<endl<<endl;

        cout<<"Enter First Node : ";
        cin>>first;
        cout<<"Enter Second Node : ";
        cin>>second;
        cout<<"Enter Weight Of The Edge : ";
        cin>>weight;

        g.addEdge(first,second,weight);
    }


    cout << "\nEdges Of MST Are : \n\n";
    int mst_wt = g.kruskalMST();

    cout << "\n\nWeight of MST is " << mst_wt;

    return 0;
}
