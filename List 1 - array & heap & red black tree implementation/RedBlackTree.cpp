#include "RedBlackTree.h"

void RedBlackTree::initializeLeaf(Node& parent, Node& node) {
    node.value = -1;
    node.parent = &parent;
    node.leftChild = nullptr;
    node.rightChild = nullptr;
    node.color = 0;
}

void RedBlackTree::insertNode(int val) {
    Node* insertedNode = new Node();
    Node* leafL = new Node();
    Node* leafR = new Node();

    /// Adding and initializing null leaf children to inserted node
    initializeLeaf(*insertedNode,*leafL);
    initializeLeaf(*insertedNode, *leafR);

    /// Initializing field of newNode
    insertedNode -> value = val;
    insertedNode -> color = 1;
    insertedNode -> leftChild = leafL;
    insertedNode -> rightChild = leafR;
    insertedNode -> parent = nullptr;

    /// Condition when insertedNode is root - 1st added element to the tree
    if (root == nullptr) {
        /// Create root node and initialize its leafs + set color to black
        root = insertedNode;
        Node* rootLeafL = new Node();
        Node* rootLeafR = new Node();

        initializeLeaf(*root, *rootLeafL);
        initializeLeaf(*root, *rootLeafR);
        insertedNode -> color = 0;
    } else {
        /// Initial value for comparison
        Node* currentNode = root;
        int comparedValue = currentNode -> value;

        /// Tree will only take in positive numbers so loop until leaf with value -1 is reached
        while (comparedValue != -1) {
            /// Traverse left tree
            if (insertedNode->value < comparedValue) {
                currentNode = currentNode ->leftChild;
                /// Update value for looping
                comparedValue = currentNode -> value;
            } else {
                /// Traverse right tree
                currentNode = currentNode -> rightChild;
                /// Update value for looping
                comparedValue = currentNode -> value;
            }
        }

        /// Assign leafs parent to insertedNode
        insertedNode -> parent = currentNode -> parent;

        /// Assign left/right child property to insertedNode based on its and parents value
        if (insertedNode -> value < currentNode -> parent -> value) {
            insertedNode -> parent -> leftChild = insertedNode;
        } else {
            insertedNode -> parent -> rightChild = insertedNode;
        }

        fixInsertion(insertedNode);
    }
}

void RedBlackTree::fixInsertion(Node* inserted) {
    Node* parent = inserted -> parent;

    /// To avoid fixing null pointers
    if (parent == nullptr) {
        return;
    }

    /// Fix until parent of the inserted is black
    while (parent -> color == 1) {
        Node* grandParent = parent -> parent;
        /// Case 1 - parent is right child
        if (parent == grandParent->rightChild) {
            Node* uncle = grandParent->leftChild;
            /// Left child of grandparent (uncle) is red - parent and uncle black and grandParent red
            if (uncle->color == 1) {
                uncle->color = 0;
                parent->color = 0;
                grandParent->color = 1;
                /// Grandparent is the new currentNode - fix tree starting with grandparent
                inserted = grandParent;
            } else {
                /// If inserted node is left child
                if (inserted == parent -> leftChild) {
                    /// Set new inserted node as it's parent
                    inserted = inserted -> parent;
                    rightRotate(inserted);
                }
                parent -> color = 0;
                grandParent -> color = 1;
                leftRotate(grandParent);
            }
        }
        /// Case 2 - parent is left child
        else {
            Node* uncle = grandParent->rightChild;
            if (uncle->color == 1) {
                uncle->color = 0;
                parent->color = 0;
                grandParent->color = 1;
                /// Grandparent is the new currentNode - fix tree starting with grandparent
                inserted = grandParent;
            } else {
                /// If inserted node is right child
                if (inserted == parent -> rightChild) {
                    /// Set new inserted node as it's parent
                    inserted = inserted -> parent;
                    leftRotate(inserted);
                }
                parent -> color = 0;
                grandParent -> color = 1;
                rightRotate(grandParent);
            }
        }

        if (inserted == root) {
            break;
        }
    }

    root->color = 0;
}

void RedBlackTree::leftRotate(Node* toRotate) {
    Node* right = toRotate -> rightChild;
    /// push leftChild as new rightChild of toRotate
    toRotate -> rightChild = right -> leftChild;

    /// If is not a leaf then assign it a new parent
    if (right->leftChild->value != -1) {
        /// link left child with it's new parent - toRotate
        right->leftChild->parent = toRotate;
    }
    /// assign new parent to right that was replaced by it's left child
    right->parent = toRotate->parent;

    /// if toRotate was root assign new root
    if (toRotate->parent == nullptr) {
        this->root = right;
    }
    /// if toRotate is now left child of his parent(toRotate->parent)
    else if(toRotate == toRotate->parent->leftChild) {
        toRotate -> parent -> leftChild = right;
    }
    /// else toRotate has to be right child of his parent
    else {
        toRotate -> parent -> rightChild = right;
    }
    /// new child of the right
    right->leftChild = toRotate;
    /// after rotation right child becomes the parent
    toRotate->parent = right;
}

/// Same code as leftRotate but with right vars switched to left
void RedBlackTree::rightRotate(Node* toRotate) {
    Node* left = toRotate->leftChild;
    toRotate->leftChild = left->rightChild;
    if (left->rightChild->value != -1) {
        left->rightChild->parent = toRotate;
    }
    left->parent = toRotate->parent;
    if (toRotate->parent == nullptr) {
        this->root = left;
    } else if (toRotate == toRotate->parent->rightChild) {
        toRotate->parent->rightChild = left;
    } else {
        toRotate->parent->leftChild = left;
    }
    left->rightChild = toRotate;
    toRotate->parent = left;
}

void RedBlackTree::treePreOrder(Node* startingNode, bool last) {
    if (startingNode == nullptr) {
        return;
    }
    if (startingNode->value != -1) {
        /// print color
        startingNode -> color == 0 ? cout << "B" : cout << "R";
        /// print value
        cout << startingNode -> value;
        if (!last) {
            cout << endl;
        } else {
            cout << " -> ";
        }
    }
    if (root -> leftChild == startingNode) {
        cout << "---------" << endl;
    }
    treePreOrder(startingNode->leftChild, false);
    treePreOrder(startingNode->rightChild, true);
}

void RedBlackTree::treePreOrderNormal(Node* startingNode) {
    if (startingNode == nullptr) {
        return;
    }
    if (startingNode->value != -1) {
        /// print color
        startingNode -> color == 0 ? cout << "B" : cout << "R";
        /// print value
        cout << startingNode -> value << "->";
    }
    treePreOrderNormal(startingNode->leftChild);
    treePreOrderNormal(startingNode->rightChild);
}

void RedBlackTree::printTree() {
    treePreOrderNormal(root);
    cout << endl;
    treePreOrder(root, false);
    cout << endl;
}

RedBlackTree::Node* RedBlackTree::findItem(Node* startingNode, int value) {
    if (startingNode == nullptr || value == startingNode->value) {
        return startingNode;
    }
    if ( value < startingNode->value && startingNode->value != -1) {
        return findItem(startingNode->leftChild, value);
    }

    return findItem(startingNode->rightChild, value);
}

void RedBlackTree::printFound(int searchedValue) {
    Node* found = findItem(this->root, searchedValue);
    if (found != nullptr) {
        cout << "Znaleziono wezel o wartosci " << found->value;
        cout << " i kolorze";
        (found->color == 0) ? cout << " B" << endl: cout <<" R" << endl;
    } else {
        cout << "Wezel o zadanej wartosci nie istnieje w drzewie." << endl;
    }
}


