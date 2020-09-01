//WAP to perform arithmetic operation on two numbers and throw the exception if the divided is zero or does not contain an operator.
//Enter the input as a+b, where 'a' and 'b' are input numbers and '+' as operator.Check for the valid operators and perform the different operations
//like addition, subtraction, multiplication and division accordingly.

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
try{
if(op=='+')
    result = t1+t2;
else if(op == '-')
    result = t1-t2;
else if(op == '*')
    result = t1+t2;
else if(op == '/'){
 //exception handling
        try{
            if (t2==0)
                throw t2;
            result = t1/t2;
            }
            catch(double x){
                cout<<"Invalid as denominator should not be zero";
                return 1;
            }
        }
else
    throw op;
}
catch(char er){
    cout<<"Invalid operator used";
    return 2;
}
    cout<<"The result of operation is "<<result;

    return 0;
}
