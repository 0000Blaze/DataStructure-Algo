/***
    Factorial implementation with the use of recursion for given number N
         i. long long int is used as the product value becomes exponentially larger as numbers go on increasing
        ii. Due to limited memory size the program can only calculate factorial for relatively small numbers depending on the hardware of computer
            (in my computer it can only calculate till 25)
***/

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Factorial{
    int number;
    long long int answer;

public:
     long long int fact(int );
    void display();
};

long long int Factorial::fact(int n){
    if (n == 1)
        return 1;
    else{
        return n*fact(n-1);
    }
}

void Factorial::display(){
    cout<<"Enter number to calculate factorial:";
    cin>>number;
    answer=fact(number);
    cout<<"The factorial of "<<number<<" is "<<answer<<endl;
}

int main(){
    Factorial f;
    f.display();

return 0;
}
