/***
    Linked list implemented as stack , we utilize add node at beginning (push) and remove (pop) at beginning only
**/

//IMPLEMENT STACK AS LINKED LIST

#include<iostream>
#include "LinkedList.h"
using namespace std;


/****************** Stack class ************************/
template<class T>
class Stack:public LinkedList<T>{
public:
    void push(T var);
    void pop();
    T seek();
    void display();
 };

template<class T>
void Stack<T>::push(T var){
    LinkedList<T>::insertBeg(var);
}

template<class T>
void Stack<T>::pop(){
    if(this->start== nullptr){
        cout<<"Stack empty"<<endl;
    }
    else{
        T var=LinkedList<T>::deleteBeg();
        cout<<"Stack Poped:"<<var;
    }
}

template<class T>
T Stack<T>::seek(){
    if(this->start == nullptr){
        cout<<"Stack empty"<<endl;
        return 1;
    }
    else
        return this->start->item;
}

template<class T>
void Stack<T>::display(){
    if(this->start == nullptr){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Elements:";
        Node<T>* p =this->start;
        for(;p !=nullptr;p = p ->next)
            cout<<" "<<p->item;
        cout<<endl;
    }
}

/************ Implementations ****************/

int main(){
    Stack<int> st;
    int choice,var;
    do{
        cout<<"Choose:"<<endl<<"1.Push   2.POP   3.Seek   4.Display   5.EXIT"<<endl;
        cin>>choice;
        if(choice == 1){
            cout<<"Enter element:";
            cin>>var;
            st.push(var);
        }
        else if(choice == 2)
            st.pop();
        else if(choice == 3)
            cout<<"Element at top:"<<st.seek()<<endl;
        else if(choice == 4)
            st.display();
        else{
            cout<<"Thank you for visiting"<<endl;
            break;
        }
    cout<<"----------------------------"<<endl;
    }while(true);


return 0;
}
