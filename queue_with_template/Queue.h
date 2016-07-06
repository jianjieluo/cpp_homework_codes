#ifndef QUEUE_H_
#define QUEUE_H_
#include <cstdio>

template <class ElementType>
class Queue {
  public:
    Queue();
    Queue(const Queue<ElementType> & another);
    ~Queue();
    bool empty();
    int size();
    ElementType front() const;
    ElementType back() const;
    void push(ElementType element);
    void pop();
    void swap(Queue & queue);

  private:
    struct Node {
      ElementType element;
      Node* next;
      Node(ElementType ele, Node* n = NULL) {
        element = ele;
        next = n;
      }
    };
    Node* front_node;
    Node* back_node;
    int node_num;
};

template <class ElementType>
Queue<ElementType>::Queue() {
    front_node = NULL;
    back_node = NULL;
    node_num = 0;
}

template <class ElementType>
Queue<ElementType>::Queue(const Queue<ElementType>& another) {
    front_node = NULL;
    back_node = NULL;
    node_num = 0;
    if (another.node_num != 0) {
        Node* ptr = another.front_node;
        while (ptr != NULL) {
            push(ptr -> element);
            ptr = ptr -> next;
        }
        node_num = another.node_num;
    }
}

template <class ElementType>
Queue<ElementType>::~Queue() {
    while (front_node != NULL)
        pop();
}

template <class ElementType>
bool Queue<ElementType>::empty() {
    if (node_num == 0) return true;
    else return false;
}

template <class ElementType>
int Queue<ElementType>::size() {
    return node_num;
}

template <class ElementType>
ElementType Queue<ElementType>::front() const {
    return front_node -> element;
}

template <class ElementType>
ElementType Queue<ElementType>::back() const {
    return back_node -> element;
}

template <class ElementType>
void Queue<ElementType>::push(ElementType element) {
    if (!empty()) {
        back_node -> next = new struct Node(element);
        back_node = back_node -> next;
    } else {
        back_node = new struct Node(element);
        front_node = back_node;
    }
    ++node_num;
}

template <class ElementType>
void Queue<ElementType>::pop() {
    Node* temp = front_node;
    if (!empty()) {
        front_node = front_node -> next;
        delete temp;
        --node_num;
    }
    if (front_node == NULL) {
        back_node = NULL;
    }
}

template <class ElementType>
void Queue<ElementType>::swap(Queue &queue) {
    ElementType* a = new ElementType[size()];
    ElementType* b = new ElementType[queue.size()];
    int n1 = size();
    int n2 = queue.size();
    int i = 0;
    while (!empty()) {
        a[i++] = front();
        pop();
    }
    i = 0;
    while (!queue.empty()) {
        b[i++] = queue.front();
        queue.pop();
    }
    i = 0;
    while (size() != n2)
        push(b[i++]);
    i = 0;
    while (queue.size() != n1)
        queue.push(a[i++]);
    delete []a;
    delete []b;
}
#endif

