#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;             // �������
    list<int>* adj;    // �ڽӱ�
    int* indegree;     // ��¼ÿ����������

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
        // ��ʼ������
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

            // �����ڽӶ�������
            for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
                if (--indegree[*it] == 0)
                    q.push(*it);
        }

        // ������
        if (count != V) {
            cout << "ͼ�д��ڻ����޷������������" << endl;
            return false;
        }

        cout << "����������: ";
        for (int i : topOrder)
            cout << i << " ";
        cout << endl;

        return true;
    }
};
//my english
int main() {
    int num_node, num_edge;
    cout << "�����붥������ͱ���: ";
    cin >> num_node >> num_edge;

    Graph g(num_node);

    cout << "������" << num_edge << "����(�� �յ�):" << endl;
    for (int i = 0; i < num_edge; ++i) {
        int m, n;
        cin >> m >> n;
        g.addEdge(m, n);
    }

    g.topologicalSort();
    return 0;
}