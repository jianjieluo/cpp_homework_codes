#include "BinaryTree.hpp"
using std::vector;
using std::queue;

BinaryTree::Node *rebulidTree(const vector<char> &preOrder,
                              const vector<char> &inOrder, int pleft,
                              int pright, int mleft, int mright) {
  BinaryTree::Node *ptr = new (BinaryTree::Node)(preOrder[pleft]);
  int root_index = mleft;
  while (preOrder[pleft] != inOrder[root_index])
    root_index++;
  int leftlen = root_index - mleft;
  if (root_index > mleft)
    ptr->left = rebulidTree(preOrder, inOrder, pleft + 1, pleft + leftlen,
                            mleft, root_index - 1);
  if (root_index < mright)
    ptr->right = rebulidTree(preOrder, inOrder, pleft + leftlen + 1, pright,
                             root_index + 1, mright);
  return ptr;
}

BinaryTree::Node *BinaryTree::copyNode(BinaryTree::Node *oldNode,
                                       BinaryTree::Node *newNode) {
  if (oldNode == NULL) {
    newNode = NULL;
  } else {
    newNode = new Node(oldNode->val);
    newNode->left = copyNode(oldNode->left, newNode->left);
    newNode->right = copyNode(oldNode->right, newNode->right);
  }
  return (newNode);
}

void DeleteAll(BinaryTree::Node* &ptr) {
  if (ptr == NULL)
    return;
  DeleteAll(ptr->left);
  DeleteAll(ptr->right);
  delete ptr;
  ptr = NULL;
}

BinaryTree::BinaryTree(const BinaryTree &oth) {
  root = NULL;
  if (oth.root != NULL) {
      root = copyNode(oth.root, root);
  }
  /*if (oth.root != NULL) {
    std::queue<Node **> newque;
    std::queue<Node *> oldque;
    newque.push(&root);
    oldque.push(oth.root);
    while (!oldque.empty()) {
      Node **temp = newque.front();
      Node *old = oldque.front();
      (*temp) = copyNode(old, *temp);
      if ((*temp) != 0) {
        newque.push(&((*temp)->left));
        newque.push(&((*temp)->right));
      }
      if (old != 0) {
        oldque.push(old->left);
        oldque.push(old->right);
      }
      newque.pop();
      oldque.pop();
    }
  }*/
}

BinaryTree::BinaryTree(std::vector<char> & arr) {
  root = NULL;
  if (arr.size() != 0) {
    std::queue<Node **> que;
    que.push(&(root));
    for (unsigned int i = 0; i < arr.size(); ++i) {
      Node **temp = que.front();
      que.pop();
      if (arr[0] == EMPTY_ELE) {
        break;
      } else {
        if (arr[i] == EMPTY_ELE) {
          // if (arr[i] == '#') {
          continue;
        } else {
          (*temp) = new Node(arr[i]);
          que.push(&((*temp)->left));
          que.push(&((*temp)->right));
        }
      }
    }
  }
}

BinaryTree::BinaryTree(const std::vector<char> &preOrder,
                       const std::vector<char> &inOrder) {
  root = NULL;
  if (preOrder.size() != 0) {
    root = rebulidTree(preOrder, inOrder, 0, preOrder.size() - 1, 0,
                       inOrder.size() - 1);
  }
}

BinaryTree::~BinaryTree() { clear(); }

BinaryTree::Node *BinaryTree::getRoot() const { return (root); }

void BinaryTree::clear() { DeleteAll(root); }

void BinaryTree::preOrder(void (*visite)(BinaryTree::Node *),
                          BinaryTree::Node *root) {
  if (root != NULL) {
    (*visite)(root);
    preOrder((*visite), root->left);
    preOrder((*visite), root->right);
  }
}

void BinaryTree::inOrder(void (*visite)(BinaryTree::Node *),
                         BinaryTree::Node *root) {
  if (root != NULL) {
    inOrder((*visite), root->left);
    (*visite)(root);
    inOrder((*visite), root->right);
  }
}

void BinaryTree::postOrder(void (*visite)(BinaryTree::Node *),
                           BinaryTree::Node *root) {
  if (root != NULL) {
    postOrder((*visite), root->left);
    postOrder((*visite), root->right);
    (*visite)(root);
  }
}
