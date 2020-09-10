//Check the paired parenthesis in mathematical expression

#include<bits/stdc++.h>
using namespace std;

//bracket check function
void checkBrackets(string s){
    int l =s.length();
    stack<char> st;
    st.push('N');
    string final;
//iteration through expression
    for(int var=0;var<l;var++){
    //starting bracket "("
        if(s[var]=='(')
            st.push('(');
    //ending bracket ")" encountered first
        else if(s[var]==')' && st.top()=='N'){
            st.push(')');
            cout<<"Error ) bracket before ( , ";
            break;
        }
    //")" encountered after "("
        else if(s[var]==')' && st.top()!='N'){
            st.pop();
        }
    }
//stack top is "N"
    if(st.top()=='N')
        cout<<"All brackets are paired";
    else
        cout<<"All brackets are not paired";
}

int main(){
//expression to be checked
//***************HARDCODED********************//
    string exp = "(a+b)*(k+(s/e))";
    checkBrackets(exp);
return 0;
}
