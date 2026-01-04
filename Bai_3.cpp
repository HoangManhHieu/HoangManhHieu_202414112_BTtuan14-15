#include <iostream>
using namespace std;
struct Node {
    int value;      
    Node* left;    
    Node* right;    

    // Ham tao
    Node(int v, Node* l = NULL, Node* r = NULL) {
        value = v;
        left = l;
        right = r;
    }
};
class BSTree {
private:
    Node *root;
    void makeEmpty(Node*& t) {
        if (t != NULL) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = NULL;
        }
    }
    void insert(int val1, Node*& t) {
        if (t == NULL) {
            t = new Node(val1, NULL, NULL);
        } else if (val1 < t->value) {
            insert(val1, t->left);
        } else if (val1 > t->value) {
            insert(val1, t->right);
        }
    }
    Node* search(int val2, Node* t) {
        if (t == NULL) {
            return NULL;
        }
        if (val2 < t->value) {
            return search(val2, t->left);
        } else if (val2 > t->value) {
            return search(val2, t->right);
        } else {
            return t;
        }
    }

public:
    BSTree() {
        root = NULL;
    }
    ~BSTree() {
        makeEmpty();
    }
    bool isEmpty() {
        return root == NULL;
    }
    void makeEmpty() {
        makeEmpty(root);
    }
    void insert(int val1) {
        insert(val1, root);
    }
    Node* search(int val2) {
        return search(val2, root);
    }
};
void preOrder(Node* t) {
    if (t != NULL) {
        cout << t->value << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}
void inOrder(Node* t) {
    if (t != NULL) {
        inOrder(t->left);
        cout << t->value << " ";
        inOrder(t->right);
    }
}
void postOrder(Node* t) {
    if (t != NULL) {
        postOrder(t->left);
        postOrder(t->right);
        cout << t->value << " ";
    }
}
int main() {
    BSTree bst;
    bst.insert(5);
    bst.insert(6);
    bst.insert(3);
    bst.insert(8);
    bst.insert(7);
    bst.insert(4);
    bst.insert(2);
    Node *root = bst.search(5); 
    cout << "Duyet cay thu tu truoc (Pre-order):" << endl;
    preOrder(root);
    cout << endl;
    cout << "Duyet cay thu tu giua (In-order - sap xep tang dan):" << endl;
    inOrder(root);
    cout << endl;
    cout << "Duyet cay thu tu sau (Post-order):" << endl;
    postOrder(root);
    cout << endl;
    Node* n1 = bst.search(4);
    Node* n2 = bst.search(9);
    if (n1 != NULL)
        cout << "Node co gia tri = 4 la " << n1->value << endl;
    
    if (n2 == NULL)
        cout << "Khong tim thay node co gia tri 9" << endl;
    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;

    return 0;
}
