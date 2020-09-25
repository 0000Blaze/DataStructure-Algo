/****
    The tracker class defines an array of 100 to keep track of the index of the list which are being used,
    this(i.e., a tracker ) is required for the program to be called a list. As without tracker , it is a simple array.
***/
#include<iostream>
#define MaxSize 100
using std::cout;
using std::endl;

/*********** List tracker class ************/
class Track{
    public:
    int arr[100];
    int point =-1;

    void addToArr(int var);
    void removeFromArr(int var);
    void rearrange(int i);
    bool getIndex(int i);
};

//adder for tracker array
void Track::addToArr(int var){
    point++;
    arr[point] = var;
}

//remover for tracker array
void Track::removeFromArr(int var){
    if(point == -1){
        cout<<"Tracker error"<<endl;
    }
    for(int i =0;i<=point;i++){
        if(arr[i]== var){
            this->rearrange(i);
        }
    }
    point--;
}

// rearrange the array to remove an item of index say i
void Track::rearrange(int i){
    for(int j=i;i<(point);j++){
        arr[j]=arr[j+1];
    }
}

bool Track::getIndex(int i){
    for(int k=0;k<=point;k++){
        if(i == arr[k])
            return true;
    }
    return false;
}
/************************* List class *****************************/

template<class T>
class List{
    int ptr, i ;
    T lst[MaxSize];
    int count;
public:
    Track traker;

    List(){ptr = -1;count=0;}
//insert
    void insrt(T var);
    void insrt(T var,const int position);
//checkers
    bool ifEmpty(){return(ptr == -1);}
    bool ifFull(){return(ptr == 99);}
//remover
    void deleteAll();
    void del(const int position);
//return number of items
    int number();
//display entire list
    void display();

};

template<class T>
void List<T>::insrt(T var){
    if(ifFull()){
        cout<<"The list is Full"<<endl;
    }
    else{
        ptr++;
        lst[ptr] = var ;
        cout<<"Insertion of "<<var<<" at "<<ptr<<" position"<<endl;
        count++;
    //tracker part
        traker.addToArr(ptr);
    }
}

template<class T>
void List<T>::insrt(T var,const int position){
    if(ifEmpty()){
        cout<<"List is empty"<<endl;
    }
    else{
        lst[position]= var;
        ptr++;
        cout<<"Insertion of "<<var<<" at "<<position<<" position"<<endl;
        count++;
        //tracker part
        traker.addToArr(position);
    }
}

template<class T>
void List<T>::deleteAll(){
    ptr= -1;
    count= 0;
    //tracker part
    traker.point= -1;
}

template<class T>
void List<T>::del(const int position){
    if(ifEmpty()){
        cout<<"The list is empty"<<endl;
    }
    else{
        ptr--;
        count--;
        //tracker part
        traker.removeFromArr(position);
    }
}

template<class T>
int List<T>::number(){
    return count;
}

template<class T>
void List<T>::display(){
    if(ifEmpty()){
        cout<<"The list is empty"<<endl;
    }
    else{
        cout<<"The elements are:"<<endl;
        int num =1;
        for(i =0; i<=99;i++){
            if(traker.getIndex(i)){
                cout<<num<<". At position:"<<i<<" item: "<<lst[i]<<endl;
                num++;
            }
        }
        cout<<endl;
    }
}
