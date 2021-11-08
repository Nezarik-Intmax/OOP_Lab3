#include <iostream>
using namespace std;

template <class T>
class ContainerNode{
public:
    ContainerNode* next;
    ContainerNode* prev;
    ContainerNode* head;
    T node;
    ContainerNode(const T node){
        this->node = node;
        this->prev = nullptr;
        this->next = nullptr;
        this->head = nullptr;
    }
    ContainerNode(const T node, ContainerNode* prev, ContainerNode* head){
        this->node = node;
        this->prev = prev;
        this->head = head;
    }
    ContainerNode(const T* node, const ContainerNode* prev, const ContainerNode* next, const ContainerNode* head){
        this->node = node;
        this->prev = new ContainerNode(prev);
        this->next = new ContainerNode(next);
        this->head = new ContainerNode(head);
    }
};
template <class T>
class Container{
private:
    ContainerNode<T>* head;
    ContainerNode<T>* tail;
public:
    Container(){
        head = nullptr;
        tail = nullptr;
    }
    Container(T* a){
        head = a;
        tail = a;
        //node = new ContainerNode<T>(a, head, head);
    };
    void push(T a);
    void pop(T a);
    T show(int a);
};
template <class T>
void Container<T>::push(T a){
    if(tail == nullptr){
        head = new ContainerNode<T>(a);
        head->head = head;
        tail = head;
        //tail->prev = head;
    } else{
        ContainerNode<T>* newNode = new ContainerNode<T>(a, tail, head);
        tail->next = newNode;
        tail = newNode;
    }
}
template <class T>
void Container<T>::pop(T a){

}
template <class T>
T Container<T>::show(int a){
    ContainerNode<T>* newNode = head;
    for(int i = 0; i < a; i++){
        newNode = newNode->next;
    }
    return newNode->node;
}

int main(){
    Container<double> a;
    double b = 3;
    a.push(b);
    a.push(b+1);
    a.push(b+2);
    cout << a.show(1);
}
