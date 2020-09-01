//no.5 without exception handle

#include<iostream>
using namespace std;

int main(){
    double t1,t2,result;
    char op;
//input
    cout<<"Enter the operation as 'a+b': ";
    cin>>t1;
    cin>>op;
    cin>>t2;
//arithmetic operations
if(op == '+')

    result = t1+t2;
else if(op == '-')

    result = t1-t2;
else if(op == '*')

    result = t1+t2;
else if(op == '/'){

        if (t2!=0)
            result = t1/t2;
        else{
            cout<<"Invalid as denominator should not be zero";
            return 1;
        }
    }
else{
    cout<<"Invalid operator";
    return 2;
    }
    cout<<"The result of operation is "<<result;

    return 0;
}
