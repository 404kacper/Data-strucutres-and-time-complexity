#include <iostream>
using namespace std;

class RedBlackTree {
private:
    struct Node {
        int value;
        Node *parent;
        Node *leftChild;
        Node *rightChild;
        /// color 0 - black | 1 - red
        int color;
    };
public:
    Node* root;
    RedBlackTree() {
        root = nullptr;
    }
    void initializeLeaf(Node& parent, Node& node);
    void insertNode(int val);
    void fixInsertion(Node* inserted);
    void treePreOrderNormal(Node* startingNode);
    void treePreOrder(Node* startingNode, bool last);
    void printTree();
    void leftRotate(Node* toRotate);
    void rightRotate(Node* toRotate);
    void printFound(int searchedValue);
    Node* findItem(Node* startingNode, int value);
};
