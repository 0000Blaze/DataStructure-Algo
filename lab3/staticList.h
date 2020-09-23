#include<iostream>
#define MaxSize 100

using std::cout;
using std::endl;

/************* List class **************/

template<class T>
class List{
    int ptr, i ;
    T lst[MaxSize];
public:
    List(){ptr = -1;}
//insert
    void insrt(T var);
    void insrt(T var,const int position);
//checkers
    bool ifEmpty(){return(ptr == -1);}
    bool ifFull(){return(ptr == 99);}
//remover
    void deleteAll();
    void del(const int position);
//total count
    int number();
//update at specific position
    void update(T var,const int position);
//display entire list
    void display();

};

template<class T>
void List<T>::insrt(T var){
    if(ifFull()){
        cout<<"The list is Full"<<endl;
    }
    else{
        ptr++;
        lst[ptr] = var ;
        cout<<"Insertion of "<<var<<" at "<<ptr<<" position"<<endl;
    }
}

template<class T>
void List<T>::insrt(T var,const int position){
    if(ifEmpty()){
        cout<<"List is empty"<<endl;
    }
    else{
        for(i = ptr;i>=position;i--){
            lst[i+1]=lst[i];
        }
        lst[position]= var;
        ptr++;
    }
}

template<class T>
void List<T>::deleteAll(){
    ptr= -1;
}

template<class T>
void List<T>::del(const int position){
    if(ifEmpty()){
        cout<<"The list is empty"<<endl;
    }
    else{
        for(i=position;i<ptr;i++){
            lst[i]=lst[i+1];
        }
        ptr--;
    }
}

template<class T>
int List<T>::number(){
    return (ptr+1);
}

template<class T>
void List<T>::update(T var,const int position){
    if(ifEmpty()){
        cout<<"The list is empty"<<endl;
    }
    else if(position > ptr){
        cout<<"Invalid position"<<endl;
    }
    else{
        lst[position] = var ;
        cout<<"The value "<<var<<" has been inserted to "<<position<<endl;
    }
}

template<class T>
void List<T>::display(){
    if(ifEmpty()){
        cout<<"The list is empty"<<endl;
    }
    else{
        cout<<"The elements are:"<<endl;
        for(i =0; i<=ptr;i++){
            cout<<lst[i]<<" ";
        }
        cout<<endl;
    }
}
