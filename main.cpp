#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int v) : value(v) {}

    void insert(int);

    Node *find(int);
};

void Node::insert(int x) {
    if (value == x)
        return;
    if (x < value) {
        if (left)
            left->insert(x);
        else
            left = new Node(x);
    } else {
        if (right)
            right->insert(x);
        else
            right = new Node(x);
    }
}

Node *Node::find(int x) {
    if (value == x)
        return this;
    else if (x < value) {
        if (nullptr == left)
            return nullptr;
        return left->find(x);
    } else {
        if (nullptr == right)
            return nullptr;
        return right->find(x);
    }
}

void create(Node *node, int n) {
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        node->insert(temp);
    }
}

int main() {
    int temp;
    cout << "Enter the number of root:";
    cin >> temp;
    Node root(temp);
//    cout << "Enter the sum of number:";
//    cin >> temp;
//    create(&root, temp);

    while (true) {
        int target;
        cout << "Enter the number you searched for(Enter -1 for quit):" << endl;
        cin >> target;
        if (target == -1)
            break;
        if (root.find(target))
            cout << "Find " << target << endl;
        else {
            root.insert(target);
            cout << "Insert " << target << endl;
        }
    }
    return 0;
}