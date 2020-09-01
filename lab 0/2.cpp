//WAP to create a structure Date with its member: day,month and year.Write a function which takes two pointer variables of
//type DATE to calculate the age of person (i.e. pass structure by reference)

#include <iostream>
using namespace std;
//structure DATE
struct DATE{
private:
    int day;
    int month;
    int year;
public:
    DATE(int dd=1, int mm=9 , int yy=2020){
        day=dd;
        month=mm;
        year=yy;
    }
//make function friend to access private member
friend void calcAge(DATE* current ,DATE* birth);
};

//function to calculate the exact age
void calcAge(DATE* current, DATE* birth)
{
    int ageY,ageM,ageD;
//calculate the exact age by day, month and year
    ageY= current->year - birth->year;
    ageM= current->month - birth->month;
    ageD= current->day - birth->day;

//day condition
    if(ageD<0){
//31 days condition
        if(current->month==1 || current->month==3 || current->month==5 || current->month==7 || current->month==8 || current->month==10 || current->month==12 )
            ageD=31+ageD;
//30 days condition
        else if(current->month==4 || current->month==6 || current->month==9 || current->month==11 )
            ageD=30+ageD;
//leap year considered
        else if(current->year/4==0 && current->month==2)
            ageD=29+ageD;
//feb consideration
        else
            ageD=28+ageD;
        ageM-=1;
    }
//month condition
    if(ageM<0){
        ageY-=1;
        ageM=12+ageM;
    }
//year condition
    if(ageY<0)
        cout<<"Invalid Date "<<endl;
    else
        cout<<"Your age is "<<ageY<<" years "<<ageM<<" months "<<ageD<<" days old"<<endl;
}
int main(){
    int dd,mm,yy;
    cout<<"Enter birthday(dd/mm/yy): ";
    cin>>dd>>mm>>yy;
    DATE birthDate(dd,mm,yy);
    DATE currentDate(1,9,2020);
    calcAge(&currentDate,&birthDate);
    return 0;
}
