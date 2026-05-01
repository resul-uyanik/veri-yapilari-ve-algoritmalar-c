#include <stdio.h>
#include <stdlib.h>

// Bir düğüm yapısı
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Yeni bir düğüm oluşturma fonksiyonu
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// İkili ağaca düğüm ekleme fonksiyonu
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        // Eğer ağaç boşsa yeni bir düğüm oluştur ve kök olarak ata
        return createNode(data);
    }

    if (data < root->data) {
        // Sol alt ağaca ekle
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        // Sağ alt ağaca ekle
        root->right = insertNode(root->right, data);
    }

    return root; // Kök düğüm değişmeden döndürülür
}

// Ağacı sıralı (in-order) gezme
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Ağaç düğümleri ekleniyor
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    //printf("\nhangi: %d\n",root->data);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("In-order traversal sonucu: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
