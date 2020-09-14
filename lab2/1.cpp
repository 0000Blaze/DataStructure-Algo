//Perform enqueue and dequeue operations in Linear Queue

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

/******************************  Queue class  ***************************/
//declaration of class
class Queue{

    int *arr;
    int count;
    int front;
    int rear;
    int capacity;

 public:
     Queue(int s=5);
     ~Queue();
     void enqueue(int);
     void dequeue();
     int size();
     int peek();
     bool isEmpty();
     bool isFull();
};
//class functions

//constructor of Queue
//default size is 5

Queue::Queue(int s){
    arr= new int[s];
    front= 0;
    rear= -1;
    count= 0;
    capacity= s;
}

//destructor of Queue
Queue::~Queue(){
    delete[] arr;
}

//size getter function
int Queue::size(){
    return count;
}

//check if queue is empty
bool Queue::isEmpty(){
    if(size() == 0)
        return true;
    else
        return false;
}

//check if queue is full
bool Queue::isFull(){
    if(size()== capacity)
        return true;
    else
        return false;
}

//add to the queue function
void Queue::enqueue(int var){
    if(isFull()){
        cout<<"Queue is Full"<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"Inserting: "<< var<<endl;
    rear++;
    arr[rear]=var;
    count++;
}

//return the top element
int Queue::peek(){
    if(isEmpty()){
        cout<<"Queue is empty, underflow condition"<<endl;
        exit(EXIT_FAILURE);
    }
return arr[front];
}

//delete the end element
void Queue::dequeue(){
    if(isEmpty()){
        cout<<"Queue is empty, underflow condition"<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"Removing: "<<arr[front]<<endl;
    front++;
    count--;
}

/****************************** Implementation *******************************************/
int main(){
    Queue q(3);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    //q.enqueue(4); //Overflow condition

    cout<<endl<<"Top item: "<<q.size()<<endl <<endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    //q.dequeue();     //Underflow condition

return 0;
}
