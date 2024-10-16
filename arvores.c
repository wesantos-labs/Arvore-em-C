#include <stdio.h>
#include <stdlib.h>

//Definindo a estrutura do nó
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir nó
struct Node* insert(struct Node* root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}


//Funções de Percurso

//percurso em ordem (in-order)
void inOrder(struct Node* root) {
    if(root != NULL) {
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}

//Percurso pré-ordem (pre-order)
void preOrder(struct Node* root) {
    if(root != NULL) {
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Percurso pós-ordem (post-ORder)
void postOrder(struct Node* root) {
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}

//Função para liberar memória
void freeTree(struct Node* root) {
    if(root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

//Função MAIN
int main(){
    struct Node* root = NULL;

    //Inserindo valores na arvore
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Percorrendo a árvore
    printf("In-Ordewr: ");
    inOrder(root);
    printf("\n");

    printf("Pre-Order: ");
    preOrder(root);
    printf("\n");


    printf("Post-Order: ");
    postOrder(root);
    printf("\n");

        //Libera memoria
    freeTree(root);

    return 0;
}


