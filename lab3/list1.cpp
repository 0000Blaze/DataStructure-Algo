//insert and delete in static list
/**
      i. Default size of the static list is 100
     ii. The list is implemented by template but the program is hard coded to make a list of int type
    iii. No arrangement is done if overflow is reached and increment of size of list is required
*/
#include<iostream>
#include "staticList.h"
using namespace std;

/*************** Implementation ************/
int main(){
    int choose = 0;
    List<int> lt;       //int type list hard coded
    int var;
    int position;
    cout<<"List of size 100 created"<<endl;
    do{
        cout<<"1.Insert"<<endl<<"2.Insert at specific position"<<endl<<"3.Delete all elements"<<endl<<
        "4.Delete at specific position"<<endl<<"5.Update a value"<<endl<<"6.Display all elements"<<endl<<"7.Number of elements in list"<<endl<<"8.Exit"<<endl<<endl<<"Choice:";
        cin>>choose;
        if(choose == 1){
            cout<<"Enter element: ";
            cin>>var;
            lt.insrt(var);
        }
        else if(choose == 2){
            cout<<"Enter element and then position: ";
            cin>>var>>position;
            lt.insrt(var,position);
        }
        else if(choose == 3){
            lt.deleteAll();
        }
        else if(choose == 4){
            cout<<"Enter position for deletion: ";
            cin>>position;
            lt.del(position);
        }
        else if(choose == 5){
            cout<<"Enter element and then position to be updated: ";
            cin>>var>>position;
            lt.update(var,position);
        }
        else if(choose == 6){
            lt.display();
        }
        else if(choose == 7){
            int size=lt.number();
            cout<<"Total elements: "<<size<<endl;
        }
        else{
            cout<<"Exiting, Thanks for visiting"<<endl;
            break;
        }
        cout<<"-----------------------------------------------------------"<<endl;
    }while(true);
return 0;
}
