#include <iostream>

template <class T>
class ContainerNode{
public:
    T* next;
    T* prev;
    T* head;
    T* tail;
    T* node;
    ContainerNode(const T* node, const T* prev, const T* head, const T* tail){
        this->node = new T(node);
        prev->next = this->node;
        this->prev = prev;
        this->head = head;
        this->tail = tail;
    }
    ContainerNode(const T* prev, const T* next, const T* head, const T* tail){
        this->prev = new T(prev);
        this->next = new T(next);
        this->head = new T(head);
        this->tail = new T(tail);
    }
};
template <class T>
class Container{
private:
    T* next;
    T* prev;
    T* head;
    T* tail;
public:
    Container(){};
    void pop(T a);
    void push(T a);
};
template <class T>
void Container<T>::pop(T a){

}
template <class T>
void Container<T>::push(T a){

}

int main(){
    Container<int> a;
}
