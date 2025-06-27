#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;             // 顶点个数
    list<int>* adj;    // 邻接表
    int* indegree;     // 记录每个顶点的入度

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        indegree = new int[V];
        for (int i = 0; i < V; ++i)
            indegree[i] = 0;
    }

    ~Graph() {
        delete[] adj;
        delete[] indegree;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        ++indegree[w];
    }

    bool topologicalSort() {
        queue<int> q;
        // 初始化队列
        for (int i = 0; i < V; ++i)
            if (indegree[i] == 0)
                q.push(i);

        int count = 0;
        vector<int> topOrder;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topOrder.push_back(u);
            ++count;

            // 更新邻接顶点的入度
            for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
                if (--indegree[*it] == 0)
                    q.push(*it);
        }

        // 输出结果
        if (count != V) {
            cout << "图中存在环，无法完成拓扑排序" << endl;
            return false;
        }

        cout << "拓扑排序结果: ";
        for (int i : topOrder)
            cout << i << " ";
        cout << endl;

        return true;
    }
};

int main() {
    int num_node, num_edge;
    cout << "请输入顶点个数和边数: ";
    cin >> num_node >> num_edge;

    Graph g(num_node);

    cout << "请输入" << num_edge << "条边(起点 终点):" << endl;
    for (int i = 0; i < num_edge; ++i) {
        int m, n;
        cin >> m >> n;
        g.addEdge(m, n);
    }

    g.topologicalSort();
    return 0;
}