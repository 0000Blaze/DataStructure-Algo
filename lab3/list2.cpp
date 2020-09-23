//Queue as List
/**
      i. Queue operations is performed by the list defined before
     ii. The list is as a member of Queue class and its functions are utilized accordingly
    iii. The implementation is of a linear queue
*/
#include<iostream>
#include "staticList.h"
using namespace std;

/******** Queue by list ********/
template<class T>

class Queue{
    List<T> items;
    int rear,front = 0;
public:
    void enque(T var){
        if(front == 0){
            front++;
            items.insrt(var);
        }
        else
            items.insrt(var,0);
    }

    void deque(){
        rear = items.number()-1 ;
        items.del(rear);
    }

    void display(){
        items.display();
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
                cout<<"Item dequeued"<<endl;
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
