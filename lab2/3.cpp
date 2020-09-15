/*Perform operations in Deque( Double ended queue) for:
a. Add at beginning
b. Add at end
c. Delete from beginning
d. Delete from end*/

#include<iostream>
using std::cout;
using std::endl;

/******************************  Deque class  ***************************/
//declaration of class
class Deque{

    int *arr;
    int right;
    int left;
    int size;

 public:
     Deque(int s=5);
     ~Deque();
     bool isEmpty();
     bool isFull();

     void insertLeft(int);
     void insertRight(int);
     void deleteLeft();
     void deleteRight();
     int getLeft();
     int getRight();
};

//class functions

//constructor of dequeue
//default size is 5
Deque::Deque(int s){
    arr= new int[s];
    right= -1;
    left= -1;
    size= s;
}

//destructor of dequeue
Deque::~Deque(){
    delete[] arr;
}

//check if dequeue is empty
bool Deque::isEmpty(){
    return (left == -1);
}

//check if dequeue is full
bool Deque::isFull(){
    return((left ==0 && right == size-1) || (left == right+1));
}

//Insert item at left
void Deque::insertLeft(int var){
    if(isFull()){
        cout<<"Overflow";
        exit(EXIT_FAILURE);
    }
    if(left == -1)          //dequeue is empty initially
        left = right =0;
    else{
        if(left == 0)     //right is at last position
            left= size-1;
        else
            left--;
    }
    cout<<"Left insertion: "<<var<<endl;
    arr[left]= var;
}

//Insert item at right
void Deque::insertRight(int var){
    if(isFull()){
        cout<<"Overflow";
        exit(EXIT_FAILURE);
    }
    if(left == -1)          //dequeue is empty initially
        left = right =0;
    else{
        if(right == size-1)     //right is at last position
            right=0;
        else
            right++;
    }
    cout<<"Right insertion: "<<var<<endl;
    arr[right]= var;
}

//delete from left
void Deque::deleteLeft(){
    if(isEmpty()){
        cout<<"Underflow";
        exit(EXIT_FAILURE);
    }
    cout<<"The deleted element is: "<<arr[left]<<endl;
    if(left == right)
        left=right= -1;
    else{
        if(left == size -1)
            left=0;
        else
            left++;
    }
}

//delete from right
void Deque::deleteRight(){
     if(isEmpty()){
        cout<<"Underflow";
        exit(EXIT_FAILURE);
    }
    cout<<"The deleted element is: "<<arr[right]<<endl;
    if(left == right)
        left=right= -1;
    else{
        if(right == 0)
            right= size-1;
        else
            right--;
    }
}

// retrieve left element
int Deque::getLeft() {
    if (isEmpty()){
        cout << " Underflow!!\n" << endl;
        exit(EXIT_FAILURE);
    }
    return arr[left];
}

// retrieve right element of Deque
int Deque::getRight(){
    if(isEmpty()){
        cout << " Underflow!!\n" << endl;
        exit(EXIT_FAILURE);
        }
    return arr[right];
}

/****************************** Implementation *******************************************/
int main(){
    Deque dq(3);
    dq.insertLeft(1);
    dq.insertLeft(2);
    dq.insertLeft(3);
    //dq.insertLeft(4);     //overflow condition

    cout<<endl;
    dq.deleteLeft();
    cout<<endl;

    dq.insertRight(5);

    cout<<endl;
    cout<<"The right element is: "<<dq.getRight()<<endl;
    cout<<endl;

    dq.deleteRight();

    cout<<endl;
    cout<<"The left element is: "<<dq.getLeft()<<endl;
    cout<<endl;

    dq.deleteRight();
    dq.deleteRight();
    //dq.deleteRight();     //underflow condition

return 0;
}

