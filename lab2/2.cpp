//Perform enqueue and dequeue operations in Circular Queue

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

/******************************  Queue class  ***************************/
//declaration of class
class Queue{

    int *arr;
    int front;
    int rear;
    int capacity;

 public:
     Queue(int s=5);
     ~Queue();
     void enqueue(int);
     void dequeue();
     int peek();
     bool isEmpty();
     bool isFull();
};
//class functions

//constructor of Queue
//default size is 5

Queue::Queue(int s){
    arr= new int[s];
    front=-1;
    rear= -1;
    capacity= s;
}

//destructor of Queue
Queue::~Queue(){
    delete[] arr;
}

//check if queue is empty
bool Queue::isEmpty(){
    if(front == -1 )
        return true;
    else
        return false;
}

//check if queue is full
bool Queue::isFull(){
    if(front== (rear+1) %capacity)
        return true;
    else
        return false;
}

//return the element at front pointer
int Queue::peek(){
    if(isEmpty()){
        cout<<"Circular Queue underflow condition"<<endl;
        exit(EXIT_FAILURE);
    }
return arr[front];
}

//add to the queue function
void Queue::enqueue(int var){
    if(isFull()){
        cout<<"Circular Queue overflow condition"<<endl;
        exit(EXIT_FAILURE);
    }
    else if(front== -1){
        front = rear = 0;
    }
    else{
        rear=(rear+1)%capacity;
    }
    cout<<"Inserting "<< rear<<" position item : "<<var<<endl;
    arr[rear]=var;
}

//delete the end element
void Queue::dequeue(){
    int position = front;
    if(isEmpty()){
        cout<<"Circular Queue underflow condition"<<endl;
        exit(EXIT_FAILURE);
    }
    else if (front == rear){
        front = rear =-1 ;
    }
    else
        front=(front+1)%capacity;

    cout<<"Removing "<<position<<" position item :  "<<arr[position]<<endl;
}

/****************************** Implementation *******************************************/
int main(){
    Queue q(3);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<endl;
    q.dequeue();
    q.enqueue(4);

    cout<<endl;
   //q.enqueue(5); //overflow
    q.dequeue();
    q.dequeue();
    q.dequeue();
    //q.dequeue(); //underflow

return 0;
}

