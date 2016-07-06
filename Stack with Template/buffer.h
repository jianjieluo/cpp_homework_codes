template <typename ElementType>
class Stack {
    public:
        Stack() ;
        Stack(const Stack &oth);
        ~Stack();
        bool empty();
        int size() const;
        //size_t size() const;
        ElementType top() const;
        void push(ElementType element);
        void pop();
        void swap(Stack& oth);
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
        //size_t node_num;
};
