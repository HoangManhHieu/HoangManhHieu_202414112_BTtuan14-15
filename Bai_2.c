#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int areIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}
Node* generateLargeTree(int n) {
    if (n <= 0) return NULL;

    // Tạo node gốc
    Node* root = createNode(rand() % 100);
    int nLeft = n / 2;
    int nRight = n - 1 - nLeft;
    root->left = generateLargeTree(nLeft);
    root->right = generateLargeTree(nRight);
    return root;
}
int main() {
    Node* rootA = createNode(1);
    rootA->left = createNode(2);
    rootA->right = createNode(3);
    Node* rootB = createNode(1);
    rootB->left = createNode(2);
    rootB->right = createNode(3);
    Node* rootC = createNode(1);
    rootC->left = createNode(2);
    rootC->right = createNode(4);
    if (areIdentical(rootA, rootB))
        printf("Cay A va Cay B: Giong nhau (Dung)\n");
    else
        printf("Cay A va Cay B: Khac nhau (Sai)\n");

    if (areIdentical(rootA, rootC))
        printf("Cay A va Cay C: Giong nhau (Sai)\n");
    else
        printf("Cay A va Cay C: Khac nhau (Dung)\n");
    return 0;

}
