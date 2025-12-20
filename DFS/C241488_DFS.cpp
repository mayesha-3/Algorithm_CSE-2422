
#include <iostream>
using namespace std;

void dfs(int node, int n, int adj[20][20], bool visited[20]) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int adj[20][20];
    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    bool visited[20] = {false};

    cout << "DFS Traversal: ";
    dfs(start, n, adj, visited);
    cout << endl;

    return 0;
}
