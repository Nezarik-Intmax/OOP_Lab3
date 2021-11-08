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
        this->next = nullptr;
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
    }
    void push(T a);
    void pop();
    void pop(T a);
    T get(int a);
    int length();
};
template <class T>
void Container<T>::push(T a){
    if(tail == nullptr){
        head = new ContainerNode<T>(a);
        head->head = head;
        tail = head;
    } else{
        ContainerNode<T>* newNode = new ContainerNode<T>(a, tail, head);
        tail->next = newNode;
        tail = newNode;
    }
}
template <class T>
void Container<T>::pop(){
    if(tail != nullptr){
        ContainerNode<T>* newNode = tail->prev;
        delete(tail);
        tail = newNode;
    }
}
template <class T>
void Container<T>::pop(T a){
    if(head != nullptr){
        ContainerNode<T>* newNode = head;
        do{
            if(newNode->node == a){
                newNode->prev->next = newNode->next;
                delete(newNode);
            }
            newNode = newNode->next;
        }while (newNode!=nullptr);
    }

}
template <class T>
T Container<T>::get(int a){
    ContainerNode<T>* newNode = head;
    for(int i = 0; i < a; i++){
        newNode = newNode->next;
    }
    return newNode->node;
}
template <class T>
int Container<T>::length(){
    ContainerNode<T>* newNode = head;
    int i = 0;
    while(newNode!=nullptr){
        newNode = newNode->next;
        i++;
    }
    return i;
}

int main(){
    Container<int> a;
    int b = 3;
    a.push(b);
    a.push(b+1);
    a.push(b+2);
    for(int i = 0; i < a.length(); i++){
        cout << a.get(i) << "\n";
    }
    cout << "\n";
    a.pop();
    a.push(b + 10);
    for(int i = 0; i < a.length(); i++){
        cout << a.get(i) << "\n";
    }
}
