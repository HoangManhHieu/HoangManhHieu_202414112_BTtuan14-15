#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
void treetoArray(Node* root, int* arr, int* index) {
    if (root == NULL) return;
    arr[(*index)++] = root->data;
    treetoArray(root->left, arr, index);
    treetoArray(root->right, arr, index);
}
int tongNode(Node* root) {
    if (root == NULL) return 0;
    return 1 + tongNode(root->left) + tongNode(root->right);
}
void sapxepMang(int* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        sapxepMang(arr, n, largest);
    }
}
void mangTotree(Node* root, int* arr, int n) {
    if (root == NULL) return;
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    int i = 0;
    queue[rear++] = root;
    while(front < rear && i < n) {
        Node* current = queue[front++];
        current->data = arr[i++];
        if(current->left) queue[rear++] = current->left;
        if(current->right) queue[rear++] = current->right;
    }
    free(queue);
}
void vundong(Node* root) {
    int n = tongNode(root);
    int* arr = (int*)malloc(n * sizeof(int));
    int index = 0;
    treetoArray(root, arr, &index);
    for (int i = n / 2 - 1; i >= 0; i--) {
        sapxepMang(arr, n, i);
    }
    mangTotree(root, arr, n);
    free(arr);
}

int main() {
    Node* root = createNode(4);
    root->left = createNode(1);
    root->right = createNode(3);
    root->left->left = createNode(2);
    root->left->right = createNode(16);
    root->right->left = createNode(9);
    root->right->right = createNode(10);
    root->left->left->left = createNode(14);
    root->left->left->right = createNode(8);
    root->left->right->left = createNode(7);
    printf("Duyet Truoc (Pre-order): "); preOrder(root); printf("\n");
    printf("Duyet Giua (In-order):   "); inOrder(root); printf("\n");
    printf("Duyet Sau (Post-order):  "); postOrder(root); printf("\n");
    vundong(root);
    printf("Gia tri cay sau khi vun dong (Pre-order): ");
    preOrder(root);
    printf("\n");
    return 0;
}
