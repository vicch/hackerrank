// Problem:
// 

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
protected:
    int size;
    int* map;

    void mark_distance(vector<int>& dists, int node, int dist)
    {
        int i;

        for (i = 0; i < size; i++) {
            if (map[node * size + i] == 1 && (dists[i] == -1 || dists[i] > dist)) {
                dists[i] = dist;
                mark_distance(dists, i, dist + 6);
            }
        }

        return;
    }

public:
    Graph(int vsize)
    {
        size = vsize;
        map = new int[size * size];
    }

    void add_edge(int node1, int node2)
    {
        map[node1 * size + node2] = 1;
        map[node2 * size + node1] = 1;
        return;
    }

    vector<int> shortest_path(int node)
    {
        vector<int> dists(size, -1);

        // Differentiate the node itself from unvisited nodes
        dists[node] = 0;

        mark_distance(dists, node, 6);

        return dists;
    }
};

int main()
{
    int time, size, edge, node1, node2, start, i;

    cin >> time;

    for (; time > 0; time--) {
        cin >> size >> edge;
        Graph graph(size);

        for (; edge > 0; edge--) {
            cin >> node1 >> node2;
            graph.add_edge(node1 - 1, node2 - 1);
        }

        cin >> start;
        vector<int> dists = graph.shortest_path(start - 1);

        for (i = 0; i < size; i++)
            if (i != start - 1)
                cout << dists[i] << " ";
        cout << endl;
    }

    return 0;
}