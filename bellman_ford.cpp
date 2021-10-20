#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N,m;
    cout << "Enter no. of nodes: ";
    cin >> N;
    cout << "Enter no. of edges: ";
    cin >> m;
    vector<node> edges;
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;


    int inf = 10000000;
    vector<int> dist(N, inf);

    dist[src] = 0;

    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int fl = 0;
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle";
            fl = 1;
            break;
        }
    }

    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }


    return 0;
}

/*

Enter no. of nodes: 6
Enter no. of edges: 7
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3
Enter source node: 0
0 0
1 5
2 3
3 3
4 1
5 2


*/

/*

Enter no. of nodes: 4
Enter no. of edges: 4
0 1 1
1 2 -1
2 3 -1
3 0 -1
Enter source node: 0
Negative Cycle


*/
