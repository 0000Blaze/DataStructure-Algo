//WAP to swap the values (of type int, double,char) using function template.

#include <iostream>
using namespace std;

//template
template<class T>
//swap function
void swap(T *a,T *b){
    T temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int i1=1,i2=2;
    double d1=5.55,d2=6.66;
    char c1='a',c2='b';
    cout<<"Initial Values before swapping:"<<endl<<i1<<" "<<i2<<endl<<d1<<" "<<d2<<endl<<c1<<" "<<c2<<endl;
    swap(&i1,&i2);
    swap(&d1,&d2);
    swap(&c1,&c2);
    cout<<"Values after swapping:"<<endl<<i1<<" "<<i2<<endl<<d1<<" "<<d2<<endl<<c1<<" "<<c2<<endl;
   return 0;
}

