#ifndef STACK_H_
#define STACK_H_
#include <iostream>
using namespace std;

template <typename ElementType>
class Stack {
    public:
        Stack();
        Stack(const Stack<ElementType> &oth);
        ~Stack();
        bool empty();
        int size() const;
        // size_t size() const;
        ElementType top() const;
        void push(ElementType element);
        void pop();
        void swap(Stack<ElementType> &oth);
        void reverse();   /*reverse the elements' order in the stack*/
        void clear();
    private:
        struct Node {
            ElementType element;
            Node* next;
            Node(ElementType ele, Node *n = NULL) {
                element = ele;
                next = n;
            }
        };
        Node *top_node;
        int node_num;
        // size_t node_num;
};

template <typename ElementType>
Stack<ElementType>::Stack() {
    top_node = NULL;
    node_num = 0;
}

template <typename ElementType>
Stack<ElementType>::Stack(const Stack<ElementType> &oth) {
    top_node = NULL;
    node_num = 0;
    if (oth.node_num != 0) {
        Node* ptr = oth.top_node;
        while (ptr != NULL) {
            push(ptr -> element);
            ptr = ptr -> next;
        }
        node_num = oth.node_num;
    }
    this -> reverse();
}

template <typename ElementType>
Stack<ElementType>::~Stack() {
    clear();
}

template <typename ElementType>
bool Stack<ElementType>::empty() {
    return (node_num == 0);
}

template <typename ElementType>
int Stack<ElementType>::size() const {
    return node_num;
}

template <typename ElementType>
ElementType Stack<ElementType>::top() const {
    return (top_node -> element);
}

template <typename ElementType>
void Stack<ElementType>::push(ElementType element) {
    if (empty()) {
        top_node = new Node(element);
        node_num = 1;
    } else {
        top_node = new Node(element, top_node);
        ++node_num;
    }
}

template <typename ElementType>
void Stack<ElementType>::pop() {
    if (empty()) {
        top_node = NULL;
    } else {
        Node* temp = top_node;
        top_node = top_node -> next;
        delete temp;
        --node_num;
    }
}

template <typename ElementType>
void Stack<ElementType>::swap(Stack<ElementType> &oth) {
    ElementType* a = new ElementType[size()];
    ElementType* b = new ElementType[oth.size()];
    int n1 = size();
    int n2 = oth.size();
    int i = 0;
    while (!empty()) {
        a[i++] = top();
        pop();
    }
    i = 0;
    while (!oth.empty()) {
        b[i++] = oth.top();
        oth.pop();
    }
    i = n2 - 1;
    while (size() != n2)
        push(b[i--]);
    i = n1 - 1;
    while (oth.size() != n1)
        oth.push(a[i--]);
    delete []a;
    delete []b;
}

template <typename ElementType>
void Stack<ElementType>::clear() {
    while (top_node != NULL)
        pop();
}

template <typename ElementType>
void Stack<ElementType>::reverse() {
    int n = size();
    ElementType* a = new ElementType[n];
    int i = 0;
    while (!empty()) {
        a[i++] = top();
        pop();
    }
    i = 0;
    while (size() != n) {
        push(a[i++]);
    }
    delete []a;
}
#endif

