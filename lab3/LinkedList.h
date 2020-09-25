 #include<iostream>
using std::cout;
using std::endl;

/********* Node class *********/
template<class T>
class Node{
public:
    T item;
    Node<T>* next;
};

/******************* Linked List *********************/
template<class T>
class LinkedList{
    Node<T>* start;
public:
    LinkedList(){
        start = nullptr;
    }

    ~LinkedList(){
        if(start != nullptr){
            Node<T>* p = start;
            Node<T>* q = p->next;
            if(q == nullptr){
                delete p;
            }
            else{
                for(;q!=nullptr;p = q, q= q->next)
                    delete p ;
            }
        }
    }
//insert
    void insertBeg(T var);
    void insertEnd(T var);
    void insertAfter(Node<T>* Xnode, T var);
    void insertBefore(Node<T>* Xnode, T var);
//remove
    T deleteAfter(Node<T>* Xnode);
    T deleteBeg();
    T deleteEnd();
//getter
    Node<T>* getNode(int index);
//display
    void display();
};

template<class T>
void LinkedList<T>::insertBeg(T var){
    Node<T>* newNode = new Node<T>();
    newNode->item= var;
    if(start == nullptr){       //first insertion
        newNode->next= nullptr;
        start= newNode;
    }
    else{       //other insertions
        newNode->next= start;
        start = newNode;
    }
}

template<class T>
void LinkedList<T>::insertEnd(T var){
    Node<T>* newNode = new Node<T>();
    newNode->item = var;
    newNode->next = nullptr;
    if(start == nullptr)
        start=newNode;
    else{
        Node<T>* p= start;
        Node<T>* q= p->next;
        for(; q != nullptr; p=q, q=p->next);
        p->next = newNode;
    }
}

template<class T>
void LinkedList<T>::insertBefore(Node<T>* Xnode, T var){
    Node<T>* newNode = new Node<T>();
    newNode->item = var;
    if(Xnode == start){ //start insert
        insertBeg(var);
        return;
    }
    Node<T>* p=start;
    Node<T>* q= p->next;
    for(; q != Xnode; p=q, q=p->next);  //traverse to specific node
    newNode->next = p->next;
    p->next = newNode;
}

template<class T>
void LinkedList<T>::insertAfter(Node<T>* Xnode, T var){
    Node<T>* newNode = new Node<T>();
    newNode->item = var;
    newNode->next = Xnode->next;
    Xnode->next = newNode;
}

template<class T>
T LinkedList<T>::deleteBeg(){
    if(start == nullptr){
        cout<<"Linked list is empty"<<endl;
        exit(EXIT_FAILURE);
    }
    T itemp;
    Node<T>* temp = start;
    start = start->next;
    itemp=temp->item;
    delete temp;
    return itemp;
}

template<class T>
T LinkedList<T>::deleteEnd(){
    if(start == nullptr){
        cout<<"Linked list is empty"<<endl;
        exit(EXIT_FAILURE);
    }
    T temp;
    Node<T>* p=start;
    Node<T>* q= nullptr;
    for(; p->next != nullptr; q= p, p=p->next);  //traverse to last node
    if(q == nullptr)
        start = nullptr;
    else
        q->next = nullptr;
    temp = p->item;
    delete p;
    return temp;
}

template<class T>
T LinkedList<T>::deleteAfter(Node<T>* Xnode){
    T temp;
    Node<T>* tempNode;
    tempNode = Xnode->next;
    temp = tempNode->item;
    Xnode->next = tempNode->next;
    delete tempNode;
    return temp;
}

template<class T>
Node<T>* LinkedList<T>::getNode(int index){
    if(start == nullptr){
        cout<<"Linked list is empty"<<endl;
        return nullptr;
    }
    Node<T>* p =start;
    for(int i=0; i<index; i++){
        if(p == nullptr){
            cout<<"Invalid index"<<endl;
            return nullptr;
        }
        p= p->next;
    }
    return p;
}

template<class T>
void LinkedList<T>::display(){
    if(start == nullptr){
        cout<<"Linked list is empty"<<endl;
        exit(EXIT_FAILURE);
    }
    Node<T>* p =start;
    for(;p !=nullptr;p = p ->next)
        cout<<" "<<p->item;
    cout<<endl;
}

