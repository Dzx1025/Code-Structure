#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#define MAX 105
using namespace std;

/* 邻接矩阵 */
class MGraph {
public:
    MGraph() {
        int node, side;
        cout << "请输入结点的个数：";
        cin >> node;
        numOfNode = node;
        cout << "请输入边的条数：";
        cin >> side;

        for (int i = 1; i <= node; ++i)
            for (int j = 1; j <= node; ++j)
                map[i][j] = false;

        int st, en;
        for (int i = 0; i < side; ++i) {
            cin >> st >> en;
            if (st == en) continue;     //不存在自环
            map[st][en] = true;     
            map[en][st] = true;     //无向图
        }

    }

    void showMap() {
        cout << "Map:" << endl;
        for (int i = 1; i <= numOfNode; ++i) {
            for (int j = 1; j <= numOfNode; ++j)
                map[i][j] ? cout << "1 " : cout << "0 ";

            cout << endl;
        }

    }

    void Traverse() {
        cout << "Traverse:" << endl;

        stack<int> stk;
        vector<bool> vis(numOfNode + 1, false);
        int start = 1;
        cout << "Enter the start:";
        cin >> start;

        cout << start;
        stk.push(start);
        vis[start] = true;
        dfs(stk, vis);
    }

private:
    bool map[MAX][MAX];
    int numOfNode = 0;

    void dfs(stack<int> &stk, vector<bool> &vis) {
        while (!stk.empty()) {
            bool flag = false;  //标记是否可以继续深入，若无相连则出栈
            int now = stk.top();

            for (int i = 1; i <= numOfNode; ++i) {

                if (map[now][i]) {      //与now相连的点
                    if (!vis[i]) {
                        cout << " " << i;
                        stk.push(i);
                        vis[i] = true;
                        flag = true;
                        break;
                    }
                }

            }
            if (!flag) stk.pop();
        }
    }
};

/* 邻接表 */
class ALGraph {
public:
    ALGraph() {
        int node, side;
        cout << "请输入结点的个数：";
        cin >> node;
        cout << "请输入边的条数：";
        cin >> side;
        numOfNode = node;
        numOfSide = side;

        map = vector<vector<int>>(2 * node);

        for (int i = 0; i < side; ++i) {
            int a, b;
            cin >> a >> b;
            if (a == b) continue;
            map[a].push_back(b);
        }

    }

    void showMap() {
        cout << "Map:" << endl;
        for (int i = 1; i <= numOfNode; ++i) {
            cout << i << ": ";

            for (auto m : map[i])
                cout << m << " ";

            cout << endl;
        }

    }

    void Traverse() {
        cout << "Traverse:" << endl;
        queue<int> que;
        vector<bool> vis(numOfNode + 1, false);

        int start = 1;
        cout << "Enter the start:";
        cin >> start;

        que.push(start);
        cout << start;
        bfs(que, vis);
    }

private:
    vector<vector<int>> map;
    int numOfNode = 0, numOfSide = 0;

    void bfs(queue<int> &que, vector<bool> &vis) {
        while (!que.empty()) {
            int now = que.front();
            que.pop();

            for (auto i : map[now]) {
                if (!vis[i]) {
                    cout << " " << i;
                    que.push(i);
                    vis[i] = true;
                }
            }
        }
    }
};

int main(int argc, char *argv[]) {
    int cas;
    cout << "选择图的类型：\n1 邻接矩阵\n2 邻接表\n请输入：";
    cin >> cas;
    
    switch (cas) {
        case 1: {
            MGraph m1 = MGraph();
            m1.showMap();
            m1.Traverse();
            break;
        }
        case 2: {
            ALGraph m2 = ALGraph();
            m2.showMap();
            m2.Traverse();
            break;
        }
        default:
            break;
    }
    return 0;
}
