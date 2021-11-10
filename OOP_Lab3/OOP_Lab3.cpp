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
    ContainerNode(const T node, ContainerNode* prev, ContainerNode* next, ContainerNode* head){
        this->node = node;
        this->prev = prev;
        this->next = next;
        this->head = head;
    }
};
template <class T>
class Container{
private:
    ContainerNode<T>* head;
    ContainerNode<T>* tail;
    ContainerNode<T>* current;
public:
    Container(){
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }
    Container(T* a){
        head = a;
        tail = a;
        current = a;
    }
    void add(T a);
    void add(T a, int index);
    void pop();
    void pop(T a);
    void popIndex(int a);
    void first();
    bool eol();
    void next();
    ContainerNode<T> getObject();
    ContainerNode<T> getObject(int a);
    int length();
};
template <class T>
void Container<T>::add(T a){
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
void Container<T>::add(T a, int index){
    if((head != nullptr)&&(this->length() >= index)){
        ContainerNode<T>* tempNode = head;
        for(int i = 0; i < index; i++){
            tempNode = tempNode->next;
        }
        ContainerNode<T>* newNode = new ContainerNode<T>(a, tempNode->prev, tempNode, head);
        tempNode->prev->next = newNode;
        tempNode->prev = newNode;
        tempNode = newNode;
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
void Container<T>::popIndex(int a){
    if(head != nullptr){
        ContainerNode<T>* newNode = head;
        for(int i = 0; i < a; i++){
            newNode = newNode->next;
        }
        delete(newNode);
    }
}
template <class T>
void Container<T>::first(){
    if(head != nullptr)
        current = head;
}
template <class T>
bool Container<T>::eol(){
    if(current == tail)
        return 1;
    else
        return 0;
}
template <class T>
void Container<T>::next(){
    if((current != nullptr)&&(current!= tail))
        current = current->next;
}
template <class T>
ContainerNode<T> Container<T>::getObject(){
    return *current;
}
template <class T>
ContainerNode<T> Container<T>::getObject(int a){
    if(head != nullptr){
        ContainerNode<T>* newNode = head;
        for(int i = 0; i < a; i++){
            newNode = newNode->next;
        }
        return *newNode;
    }
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
    int b = 0;
    for(int i = 0; i < 10; i++){
        a.add(i);
    }
    for(int i = 0; i < a.length(); i++){
        cout << a.getObject(i).node << "\n";
    }
    cout << "\n";
    a.add(1000, 5);
    a.add(1000, 5);
    a.add(1000, 15);
    for(int i = 0; i < a.length(); i++){
        cout << a.getObject(i).node << "\n";
    }

    Container<int> storage;
    for(int i = 0; i < 10; i++)
        storage.add(4);
    for(storage.first(); !storage.eol(); storage.next())
        storage.getObject().node;
    for(storage.first(); !storage.eol(); storage.next())
        cout << storage.getObject().node << "\n";
}
