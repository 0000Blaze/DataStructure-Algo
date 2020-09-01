//WAP to swap the values (of type int, double,char) using function template.

#include <iostream>
using namespace std;
//template class
template<class T>
class swaper{
private:
    T a,b;
public:
    swaper(T n1=0,T n2=0){
        a=n1;
        b=n2;
    }
//display
    void display(){
        cout<<"Number1= "<<a<<" Number2= "<<b<<endl;
    }
//swap function
    void swap(){
        T temp;
        temp=a;
        a=b;
        b=temp;
    }
};

int main(){
    swaper<int> i(1,2);
    swaper<double> d(5.55,6.66);
    swaper<char> c('a','b');
//display initial condition
    cout<<"Before swap:"<<endl;
    i.display();
    d.display();
    c.display();
//swap values
    i.swap();
    d.swap();
    c.swap();
//display final condition
    cout<<endl<<"After swap:"<<endl;
    i.display();
    d.display();
    c.display();
return 0;
}
