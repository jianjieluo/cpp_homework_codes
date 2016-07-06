#include <iostream>

typedef struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val); 
} Node;

void buildTree(Node* &ptr, const int val) {
    if (ptr == NULL) {
        ptr = new Node(val);
    } else {
        if (ptr->value < val) {
            buildTree(ptr->right, val);
        } else {
            buildTree(ptr->left, val);
        }
    }
}

void Preorder(Node* ptr) {
    if (ptr != NULL) {
        std::cout << " " << ptr->value;
        Preorder(ptr->left);
        Preorder(ptr->right);
    }
}

void Inorder(Node* ptr) {
    if (ptr != NULL) {
        Inorder(ptr->left);
        std::cout << " " << ptr->value;
        Inorder(ptr->right);
    }
}

void Postorder(Node* ptr) {
    if (ptr != NULL) {
        Postorder(ptr->left);
        Postorder(ptr->right);
        std::cout << " " << ptr->value;
    }
}

void deleteTree(Node* ptr) {
    if(ptr == NULL)
        return;
    deleteTree(ptr->left);
    deleteTree(ptr->right);
    delete ptr;
    ptr = NULL;
}

int main(void) {
    int n;
    std::cin >> n;
    Node* root = NULL;
    while (n--) {
        int temp;
        std::cin >> temp;
        buildTree(root, temp);
    }
    std::cout << "Inorder:";
    Inorder(root);
    std::cout << std::endl;
    std::cout << "Preorder:";
    Preorder(root);
    std::cout << std::endl;
    std::cout << "Postorder:";
    Postorder(root);
    std::cout << std::endl;
    deleteTree(root);
    return 0;
}

