#include <iostream>
using namespace std;

struct node {
   int val;
   node* left;
   node* right;
};

// Função para criar um novo nó
node* createNewNode(int x) {
    node* nn = new node;
    nn->val = x;
    nn->left  = nullptr;
    nn->right = nullptr;
    return nn;
}

// Inserção na Árvore de Busca Binária (BST)
void bstInsert(node* &root, int x) {
    if (root == nullptr) {
        root = createNewNode(x);
        return;
    }
    if (x < root->val) {
        bstInsert(root->left, x);
    } else if (x > root->val) {
        bstInsert(root->right, x);
    }
}

// Função para liberar a memória da árvore
void deleteTree(node* &root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

// Função para percorrer a árvore em ordem (para testar se está inserindo corretamente)
void inorderTraversal(node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    node* root = nullptr;
    int x;

    cout << "Digite números para inserir na BST (Ctrl+D para terminar):" << endl;
    while (cin >> x) {
        bstInsert(root, x);
    }

    cout << "Árvore em ordem: ";
    inorderTraversal(root);
    cout << endl;

    // Liberar memória no final
    deleteTree(root);

    return 0;
}