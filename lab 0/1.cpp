//WAP to implement the following two functions on string using pointer
//  i.To calculate length of given string
//  ii.To concatenate two string

#include <iostream>
using namespace std;
//counts the number of character of string
int length(char* s){
    int count=0;
    while(*s != '\0'){
        count++;
        s++;
    }
    return count;
}
//input string
void input(char s[100]){
    cout<<"Enter string: ";
    cin>>s;
}
//concatenation function
void concatinate(char pointer[100]){

    int len1,len2,totLen;
    char add[100];
    input(add);
    len1=length(pointer);
    len2=length(add);
    totLen=len1+len2;
    for(int i=0;i<len2;i++)
        pointer[len1+i]=add[i];
    pointer[totLen]='\0';
}

int main(){
    char pointer[100];
    input(pointer);
//display length
    cout<<"The length of "<<pointer<<" is "<<length(pointer)<<endl;
//concatenation process
    concatinate(pointer);
//display concatenated string
    cout<<"The concatenated string is "<<pointer<<endl;
    return 0;
}
