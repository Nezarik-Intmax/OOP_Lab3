#include <iostream>
using namespace std;

template <class T>
class ContainerNode{
public:
    ContainerNode* next;
    ContainerNode* prev;
    T node;
    ContainerNode(const T node){
        this->node = node;
        this->prev = nullptr;
        this->next = nullptr;
    }
    ContainerNode(const T node, ContainerNode* prev){
        this->node = node;
        this->prev = prev;
        this->next = nullptr;
    }
    ContainerNode(const T node, ContainerNode* prev, ContainerNode* next){
        this->node = node;
        this->prev = prev;
        this->next = next;
    }
    ~ContainerNode(){
        next = nullptr;
        prev = nullptr;
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
        tail = head;
    } else{
        ContainerNode<T>* newNode = new ContainerNode<T>(a, tail);
        tail->next = newNode;
        tail = newNode;
    }
}
template <class T>
void Container<T>::add(T a, int index){
    if((this->length() == 0) || (this->length() == index)){
        this->add(a);
    } else if(index == 0){
        ContainerNode<T>* newNode = new ContainerNode<T>(a, nullptr, head);
        head->prev = newNode;
        head = newNode;

    } else if((head != nullptr) && (this->length() > index)){
        ContainerNode<T>* tempNode = head;
        for(int i = 0; i < index; i++){
            tempNode = tempNode->next;
        }
        ContainerNode<T>* newNode = new ContainerNode<T>(a, tempNode->prev, tempNode);
        tempNode->prev->next = newNode;
        tempNode->prev = newNode;
    }
}
template <class T>
void Container<T>::pop(){
    if(tail != nullptr){
        ContainerNode<T>* newNode = tail->prev;
        delete(tail);
        tail = newNode;
        tail->next = nullptr;
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
    if((head != nullptr)&&(this->length() > a)){
        ContainerNode<T>* newNode = head;
        for(int i = 0; i < a; i++){
            newNode = newNode->next;
        }
        if((newNode->prev != nullptr)&&(newNode->next != nullptr)){
            newNode->prev->next = newNode->next;
            newNode->next->prev = newNode->prev;
        }else if(newNode->prev != nullptr){
            newNode->prev->next = nullptr;
            tail = newNode->prev;
        }else if(newNode->next != nullptr){
            newNode->next->prev = nullptr;
            head = newNode->next;
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
    if(current == nullptr)
        return 1;
    else
        return 0;
}
template <class T>
void Container<T>::next(){
    if(current != nullptr)
        current = current->next;
}
template <class T>
ContainerNode<T> Container<T>::getObject(){
    if(current != nullptr)
        return *current;
    else if(head != nullptr)
        return *head;
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
    Container<int> storage;
    int randFunc = 0;
    int a = 0;
    int index = 0;
    unsigned int start_time = clock();
    storage.first();
    for(int i = 0; i < 100000; i++){
        randFunc = rand() % 3;
        switch(randFunc){
        case 0:
            a = rand() % 25;
            storage.add(a);
            cout << i << ": add | " << a << "\n";
            break;
        case 1:
            a = rand() % 25;
            index = rand() % (storage.length() + 1);
            storage.add(a, index);
            cout << i << ": add index | " << a << " " << index << "\n";
            break;
        case 2:
            index = rand() % (storage.length() + 1);
            storage.popIndex(index);
            cout << i << ": popIndex | " << index << "\n";
            break;
        default:
            break;
        }
    }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    for(storage.first(); !storage.eol(); storage.next())
        cout << storage.getObject().node << "\n";
    cout << "\n\n\n" << search_time << "\n\n\n";
}
