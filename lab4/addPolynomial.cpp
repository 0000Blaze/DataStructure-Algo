//add two polynomials
/**
    Singly Linked list is utilized to add two polynomials

**/
#include<iostream>
using namespace std;

/******* Node class  ******/
template<class T>
class Node{
public:
    T number;
    T expo;
    Node<T>* next;
};

/*********** Linked list **********/
template<class T>
class LinkedList{
public:
    Node<T>* start;
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
    void insertBeg(T var,T expo);
    void insertEnd(T var,T expo);

//remove
    T deleteBeg();
//getter
    Node<T>* getNode(int index);
//display
    void display();
};

template<class T>
void LinkedList<T>::insertBeg(T var, T expo){
    Node<T>* newNode = new Node<T>();
    newNode->number= var;
    newNode->expo= expo;
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
void LinkedList<T>::insertEnd(T var, T expo){
    Node<T>* newNode = new Node<T>();
    newNode->number= var;
    newNode->expo= expo;
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
T LinkedList<T>::deleteBeg(){
    if(start == nullptr){
        cout<<"Linked list is empty"<<endl;
        exit(EXIT_FAILURE);
    }
    Node<T>* temp = start;
    start = start->next;
    T num = temp->number;
    T expon=temp->expo;
    cout<<"X^"<<expon<<"x";
    delete temp;
    return num;
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
        cout<<" "<<p->number<<"X^"<<p->expo;
    cout<<endl;
}
/************* Non-Class Functions *****************/

template<class T>
void inputPoly(LinkedList<T>* ptr){
    T num, expo;
    cout<<"Enter number and exponential value:";
    cin>>num>>expo;
    ptr->insertEnd(num,expo);
}

template<class T>
void ifMistake(LinkedList<T>* ptr){
    T num;
    cout<<"Deleted:"<<num=ptr->deleteBeg();
}


/***** Implementation *****/
int main(){
    LinkedList<int> poly1;
    LinkedList<int> poly2;
    char choice;
//input first polynomial
    cout<<"Enter value for first polynomial:"<<endl;
    do{
        inputPoly(&poly1);
        cout<<"Continue to input(Y/N):";cin>>choice;
    }while(choice == 'Y' || choice == 'y');
    cout<<endl;
//input second polynomial
    cout<<"Enter value for second polynomial:"<<endl;
    do{
        inputPoly(&poly2);
    cout<<"Continue to input(Y/N):";cin>>choice;
    }while(choice == 'Y' || choice == 'y');
    cout<<endl;
    LinkedList<int> poly;
    poly1.display();
    poly2.display();
    cout<<"*****ADDING******"<<endl;
    Node<int>* p = new Node<int>();
    p= poly1.start;
    Node<int>* q = new Node<int>();
    q = poly2.start;
    Node<int>* r = new Node<int>();
    r = poly.start;
    do{
        if(p->expo > q->expo){
            poly.insertEnd(p->number,p->expo);
            p = p->next;
        }
        else if(p->expo < q->expo){
            poly.insertEnd(q->number,q->expo);
            q = q->next;
        }
        else if(p->expo == q->expo){
            poly.insertEnd(p->number + q->number, p->expo);
            p = p->next;
            q = q->next;
        }
        else
            cout<<"ERROR"<<endl;
    }while(p != nullptr && q != nullptr);

//when polynomial 1 elements left
    if(p != nullptr){
        do{
            poly.insertEnd(p->number,p->expo);
            p = p->next;
        }while(p != nullptr);
    }

//when polynomial 2 element left
    else if(q != nullptr){
        do{
            poly.insertEnd(q->number,q->expo);
            q= q->next;
        }while(q != nullptr);
    }
    cout<<"Sum : ";
    poly.display();
return 0;
}
