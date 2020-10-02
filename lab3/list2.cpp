//Queue as List
/**
      i. Queue operations is performed by the List class inherited functions with some tweaks
     ii. The implementation is of a linear queue
*/
#include<iostream>
#include "staticList.h"
using namespace std;

/******** Queue by list ********/
template<class T>
class Queue: public List<T>{
    int rear= -1,front= 0;
public:
    //Track tracker;
    void enque(T var){
        rear++;
        this->insrt(var,rear);
    }

    void deque(){
        if(!this->ifEmpty()){
            cout<<"Item dequeued:"<<this->lst[front]<<endl;
            this->del(front);
            front++;
        }
        else
            cout<<"Queue is empty"<<endl;
    }

    void display(){
        if(this->ifEmpty()){
        cout<<"The list is empty"<<endl;
        }
        else{
            cout<<"The elements are:"<<endl;
            int num =1;
            for(int i =0; i<=99;i++){
                if(this->traker.getIndex(i)){
                    cout<<num<<". Item: "<<this->lst[i]<<endl;
                    num++;
                }
            }
        }
    }
};

/******* Implementation *******/
int main(){
    Queue<int> q;       //integer type queue used
    char choice;
    int var;
    while(true){
            cout<<"Enter operation:"<<endl<<"1.Enqueue"<<endl<<"2.Dequeue"<<endl<<"3.Display"<<endl
            <<"4.Exit"<<endl<<"Choice:";
            cin>>choice;
            if(choice=='1'){
                cout<<"Enter number to enqueue:";
                cin>>var;
                q.enque(var);
            }
            else if (choice == '2'){
                q.deque();
            }
            else if (choice == '3'){
                q.display();
                cout<<endl;
            }
            else
                break;
            cout<<"----------------------------------------------"<<endl;
    }
return 0;
}
