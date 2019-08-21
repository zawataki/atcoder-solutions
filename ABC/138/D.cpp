#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    unsigned int id;
    long counter = 0;
    Node *parent = nullptr;
    vector<Node *> links;

    Node() {
        this->id = 0;
    }

    explicit Node(unsigned int id) {
        this->id = id;
    }
};

void count(Node *node) {
    node->counter += node->parent->counter;

    for (Node *linkedNode : node->links) {
        if (linkedNode->id == node->parent->id) {
            continue;
        }
        linkedNode->parent = node;
        count(linkedNode);
    }
}

int main() {
    int numberOfNodes, numberOfOperations;
    cin >> numberOfNodes >> numberOfOperations;

    Node nodes[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++) {
        nodes[i].id = i + 1;
    }

    for (unsigned int i = 0; i < numberOfNodes - 1; i++) {
        int idOfNodeA, idOfNodeB;
        cin >> idOfNodeA >> idOfNodeB;

        Node &nodeA = nodes[idOfNodeA - 1];
        Node &nodeB = nodes[idOfNodeB - 1];

        nodeA.links.push_back(&nodeB);
        nodeB.links.push_back(&nodeA);
    }

    for (int i = 0; i < numberOfOperations; i++) {
        int rootNodeIdOfTargetSubtree, numberToBeAdded;
        cin >> rootNodeIdOfTargetSubtree >> numberToBeAdded;

        nodes[rootNodeIdOfTargetSubtree - 1].counter += numberToBeAdded;
    }

    for (Node *linkedNode : nodes[0].links) {
        linkedNode->parent = &nodes[0];
        count(linkedNode);
    }

    for (const Node &node : nodes) {
        if (node.id != 1) {
            cout << " ";
        }
        cout << node.counter;
    }
    cout << endl;
}
