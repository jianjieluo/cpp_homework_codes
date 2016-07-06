#ifndef STACK_H_
#define STACK_H_
template <typename ElementType>
class Stack<ElementType> {
    public:
        Stack<ElementType>();
        size_type size(void) {return size_;}
        void push(ElementType val);
        void pop(void);
        ElementType top(void) {return *head;}
        
        

#endif
