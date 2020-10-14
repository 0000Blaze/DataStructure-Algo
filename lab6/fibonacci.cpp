/****
    Fibonacci numbers till N term
***/

#include<iostream>
using namespace std;

class Fibonacci{
    int n,a,b,c,count=1;
public:
    int fibo(int , int);
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
    cout<<"Enter till what term fibonacci series required: ";
    cin>>n;
    a=0;b=1;
    cout<<endl<<a;
    fibo(b,a);
}

int main(){
    Fibonacci f;
    f.display();
return 0;
}
