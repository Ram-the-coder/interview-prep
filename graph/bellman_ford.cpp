#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

vector<int> bellman_ford(vector<Edge> &edges, int num_vertices, int source) {
    vector<int> distance(num_vertices, INT_MAX);
    distance[source] = 0;
    for(int i=0; i<num_vertices-1; ++i) {
        for(Edge e : edges) {
            if(distance[e.from] < INT_MAX && distance[e.to] > distance[e.from] + e.weight)
                distance[e.to] = distance[e.from] + e.weight;
        }
    }

    bool negative_cycle_exists = false;
    for(Edge e : edges) {
        if(distance[e.from] < INT_MAX && distance[e.to] > distance[e.from] + e.weight) {
            negative_cycle_exists = true;
            break;
        }
    }

    if(negative_cycle_exists) cout << "Negative cycle exists\n";

    return distance;

}

int main() {
    int v, e, from, to, weight, source;
    cin >> v >> e;
    vector<Edge> g;
    for(int i=0; i<e; ++i) {
        cin >> from >> to >> weight;
        g.push_back(Edge(from, to, weight));
    }
    cin >> source;
    vector<int> d = bellman_ford(g, v, source);
    for(int i=0; i<d.size(); ++i) cout << d[i] << " ";
    cout << '\n';
}