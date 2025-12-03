#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjMatrix;
    vector<vector<pair<int,int>>> adjList;
public:
    Graph(int v) {
        V = v;
        adjMatrix.assign(V, vector<int>(V, 0));
        adjList.assign(V, {});
    }

    void addEdge(int u, int v, int w=1) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    void printAdjMatrix() {
        for (int i=0;i<V;i++) {
            for (int j=0;j<V;j++) cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void printAdjList() {
        for (int i=0;i<V;i++) {
            cout << i << ": ";
            for (auto &p : adjList[i]) cout << "(" << p.first << "," << p.second << ") ";
            cout << endl;
        }
    }

    void degrees(int x) {
        int out = adjList[x].size();
        int in = 0;
        for (int i=0;i<V;i++)
            for (auto &p : adjList[i])
                if (p.first == x) in++;
        cout << "Out-degree: " << out << endl;
        cout << "In-degree: " << in << endl;
    }

    void adjacentVertices(int x) {
        for (auto &p : adjList[x]) cout << p.first << " ";
        cout << endl;
    }

    void numberOfEdges() {
        int cnt = 0;
        for (int i=0;i<V;i++) cnt += adjList[i].size();
        cout << cnt/2 << endl;
    }

    void BFS(int s) {
        vector<int> vis(V,0);
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (auto &p : adjList[u])
                if (!vis[p.first]) {
                    vis[p.first] = 1;
                    q.push(p.first);
                }
        }
        cout << endl;
    }

    void DFSUtil(int u, vector<int>&vis) {
        vis[u]=1;
        cout << u << " ";
        for (auto &p : adjList[u])
            if (!vis[p.first]) DFSUtil(p.first, vis);
    }

    void DFS(int s) {
        vector<int> vis(V,0);
        DFSUtil(s, vis);
        cout << endl;
    }

    int findSet(int x, vector<int>&parent) {
        if (parent[x] == x) return x;
        return parent[x] = findSet(parent[x], parent);
    }

    void unionSet(int x, int y, vector<int>&parent, vector<int>&rank) {
        x = findSet(x,parent);
        y = findSet(y,parent);
        if (x != y) {
            if (rank[x] < rank[y]) swap(x,y);
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    void kruskal() {
        vector<tuple<int,int,int>> edges;
        for (int i=0;i<V;i++)
            for (auto &p : adjList[i])
                if (i < p.first)
                    edges.push_back({p.second,i,p.first});

        sort(edges.begin(), edges.end());

        vector<int> parent(V), rank(V,0);
        for (int i=0;i<V;i++) parent[i]=i;

        int total=0;
        for (auto &e : edges) {
            int w,u,v;
            tie(w,u,v)=e;
            if (findSet(u,parent)!=findSet(v,parent)) {
                unionSet(u,v,parent,rank);
                cout << u << " - " << v << " (" << w << ")" << endl;
                total+=w;
            }
        }
        cout << "Total Weight: " << total << endl;
    }

    void prim() {
        vector<int> key(V, INT_MAX), parent(V, -1), inMST(V,0);
        key[0] = 0;
        for (int c=0;c<V;c++) {
            int u=-1;
            for (int i=0;i<V;i++)
                if (!inMST[i] && (u==-1 || key[i]<key[u])) u=i;
            inMST[u]=1;
            for (auto &p : adjList[u]) {
                int v=p.first, w=p.second;
                if (!inMST[v] && w<key[v]) {
                    key[v]=w;
                    parent[v]=u;
                }
            }
        }
        int total=0;
        for (int i=1;i<V;i++) {
            cout << parent[i] << " - " << i << " (" << key[i] << ")" << endl;
            total+=key[i];
        }
        cout << "Total Weight: " << total << endl;
    }

    void dijkstra(int s) {
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        pair<int,int> top = pq.top(); pq.pop();
        int d = top.first;
        int u = top.second;
        if (d != dist[u]) continue;
        for (auto &p : adjList[u]) {
            int v = p.first, w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < V; ++i) cout << "Distance to " << i << ": " << dist[i] << endl;
}

};

int main() {
    int V, choice;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    while (true) {
        cout << "\n1 Add Edge\n2 Print Adjacency Matrix\n3 Print Adjacency List\n4 Degree of vertex\n5 Adjacent vertices\n6 Number of edges\n7 BFS\n8 DFS\n9 Kruskal\n10 Prim\n11 Dijkstra\n12 Exit\n";
        cin >> choice;

        if (choice == 1) {
            int u, v, w;
            cin >> u >> v >> w;
            g.addEdge(u,v,w);
        }
        else if (choice == 2) g.printAdjMatrix();
        else if (choice == 3) g.printAdjList();
        else if (choice == 4) {
            int x; cin >> x; g.degrees(x);
        }
        else if (choice == 5) {
            int x; cin >> x; g.adjacentVertices(x);
        }
        else if (choice == 6) g.numberOfEdges();
        else if (choice == 7) {
            int s; cin >> s; g.BFS(s);
        }
        else if (choice == 8) {
            int s; cin >> s; g.DFS(s);
        }
        else if (choice == 9) g.kruskal();
        else if (choice == 10) g.prim();
        else if (choice == 11) {
            int s; cin >> s; g.dijkstra(s);
        }
        else if (choice == 12) break;
    }
}
