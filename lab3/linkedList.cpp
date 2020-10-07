/**
    LINKED LIST:

1.	INSERTION OPERATIONS
    a.	INSERT NODE AT BEGINNING OF THE LIST
    b.	INSERT NODE AT END OF THE LIST
    c.	INSERT NODE AFTER SPECIFIC NODE
    d.	INSERT NODE BEFORE SPECIFIC NODE

2.	DELETION OPERATIONS
    a.	DELETE NODE FROM BEGINNING OF THE LIST
    b.	DELETE NODE FROM END OF THE LIST
    c.	DELETE NODE AFTER SPECIFIC NODE

**/

#include<iostream>
#include "LinkedList.h"
using std::cin;

int main(){
    LinkedList<int> iList;
    char choice;
    int index, var;
    Node<int>* ptr;

    do{
        cout<<"Enter operation to be performed:"<<endl<<"1.Insert   2.Delete   3.Display   4.Exit"<<endl;
        cin>>choice;
        if(choice=='1'){
            cout<<"Where to insert:"<<endl<<"1.Begining   2.Before Index   3.After Index   4.Ending"<<endl;
            cin>>choice;
            cout<<"Enter item to be inserted: ";
            cin>>var;
            if(choice == '1')
                iList.insertBeg(var);
            else if(choice == '4')
                iList.insertEnd(var);
            else if(choice == '2'){
                cout<<"Enter index: ";cin>>index;
                ptr = iList.getNode(index);
                iList.insertBefore(ptr,var);
            }
            else if(choice == '3'){
                cout<<"Enter index: ";cin>>index;
                ptr = iList.getNode(index);
                iList.insertAfter(ptr,var);
            }
            else
                break;
        }
        else if(choice=='2'){
            cout<<"\nWhere to delete:"<<endl<<"1.Begining   2.After Index   3.Ending"<<endl;
            cin>>choice;
            if(choice == '1')
                iList.deleteBeg();
            else if(choice == '3')
                iList.deleteEnd();
            else if(choice == '2'){
                cout<<"Enter index: ";cin>>index;
                ptr = iList.getNode(index);
                iList.deleteAfter(ptr);
            }
            else
                break;
        }
        else if(choice == '3'){
            cout<<"Linked List:"<<endl;
            iList.display();
        }
        else
            break;
    cout<<"---------------------------"<<endl;
    }while(true);

return 0;
}
