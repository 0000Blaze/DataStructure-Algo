//Perform push and pop operations in stack

#include<iostream>
using namespace std;

//class declaration
class Stack{
    int length;
    int top=-1;
    int stack[];


public:
    Stack(int l=0){
        length= l;
        stack[length];
    }
    void push(int a);
    int pop();
};

//class function defines

void Stack::push(int a){
    top++;
    if(top>length){
        cout<<endl<<"Overflow condition reached , no space in stack"<<endl;
        top--;
    }
    else{
        cout<<"Pushing item number "<<top<<" done"<<endl;
        stack[top]=a;
    }
}

int Stack::pop(){
    if( top< 0 ){
        cout<<endl<<"Underflow condition reached,no element to pop in stack"<<endl;
        return 0;
    }
    else{
        top--;
        return (stack[top+1]);
    }
}
//*************class Stack end************/
//pushing function
void pushing(Stack* ptr){
    int c;
    cout<<"Enter item to be pushed:";
    cin>>c;
    ptr->push(c);
}
//poping function
void poping(Stack* ptr){
    int var;
    var= ptr->pop();
    cout<<"Top item: "<<var<<endl;

}

int main(){
//create stack
    int size,var;
    cout<<"Enter length of stack needed: ";
    cin>>size;
    Stack s(size-1);

//choose operation to perform
    int choice;
//loop stack operations
    char looper;
    do{
        cout<<endl<<"Choose:"<<endl<<"1. Push"<<endl<<"2. Pop"<<endl;
        cin>>choice;

        if(choice==1)
//push to stack
            pushing(&s);
        else if(choice==2)
//pop from stack
            poping(&s);
        else
            cout<<"Invalid choice"<<endl;
//looping condition
        cout<<"Do you want to continue operating in Stack(Y/N):";
        cin>>looper;

    }while(looper=='y' || looper=='Y');
return 0;
}
