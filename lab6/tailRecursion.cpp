/***
    In tail recursion there is no pending operations in the system stack on recursive return.

    Tail Recursion Implementation of:
         i. Factorial of N number
        ii. Fibonacci Series till N terms

***/
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

/******************** Factorial Tail Recursion ***********************/
class Factorial{
    int number;
    long long int answer=1,ans;
    long long int fact(int , long long int);
public:
    void display();
};

long long int Factorial::fact(int n, long long int answer){
    if (n == 1)
        return answer;
    else{
        return fact(n-1,n*answer);
    }
}
void Factorial::display(){
    cout<<"Enter number to calculate factorial:";
    cin>>number;
    ans=fact(number,answer);
    cout<<endl<<"The factorial of "<<number<<" is "<<ans<<endl;
}

/**************** Fibonacci Tail recursion ********************/
class Fibonacci{
    int n,a,b,c,count=1;
    int fibo(int , int);
public:
    void display();
};

int Fibonacci::fibo(int n1 , int n2){
    if (count< n){
        cout<<" "<<n1;
        c=n1;
        count++;
        fibo(n1+n2,c);
    }
    else{
        cout<<endl;
        exit(EXIT_SUCCESS);
    }
}

void Fibonacci::display(){
    cout<<endl<<"Enter till what term fibonacci series required: ";
    cin>>n;
    a=0;b=1;
    cout<<endl<<a;
    fibo(b,a);
}

/**************** Implementation ******************/

int main(){
    cout<<"TAIL RECURSION IMPLEMENTATION"<<endl<<endl;
    Factorial fac;
    fac.display();

    Fibonacci fib;
    fib.display();
return 0;
}
