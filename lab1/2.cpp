//Convert :
//a. Infix expression to postfix expression
//b. Infix expression to prefix expression

#include<bits/stdc++.h>
using namespace std;

//precidance of operators
int precidance(char op){
    if (op == '^')
        return 5;
    else if(op == '/')
        return 4;
    else if(op == '*')
        return 3;
    else if(op == '+')
        return 2;
    else if(op == '-')
        return 1;
    else
        return -1;
}

//choice 1
void infixToPostfix(string s){
    std::stack<char> st;
    st.push('N');
    int length=s.length();
    string final;
//iteration loop
    for(int var=0;var<length;var++){

    //character a-z and A-Z case
        if((s[var]>='a' && s[var]<='z') || (s[var]>='A' && s[var]<='Z'))
            final+=s[var];

    //when "(" is encountered
        else if(s[var]=='(')
            st.push('(');

    //when ")" is encountered
        else if(s[var]==')'){
           while(st.top()!='N' && st.top() != '(' ){
                char cha= st.top();
                st.pop();
                final+=cha;
           }
           if(st.top()=='(')
                st.pop();
        }
    //when operator encountered
        else {
            while(st.top()!='N' && precidance(s[var])<= precidance(st.top())){
                char cha= st.top();
                st.pop();
                final+=cha;
            }
            st.push(s[var]);
        }
    }
  //pop remaining elements from stack
  while(st.top()!='N'){
    char cha = st.top();
    st.pop();
    final+=cha;
  }
  cout<<final;
}

//choice 2
void infixToPrefix(string s){
    std::stack<char> st;
    st.push('N');
    int length=s.length();
    string final;

    reverse(s.begin(),s.end());
    for(int i=0;i<length;i++){
        if (s[i] == '(') {
            s[i] = ')';
            i++;
        }
        else if (s[i] == ')') {
            s[i] = '(';
            i++;
        }
    }


//iteration loop
    for(int var=0;var<length;var++){

    //character a-z and A-Z case
        if((s[var]>='a' && s[var]<='z') || (s[var]>='A' && s[var]<='Z'))
            final+=s[var];

    //when "(" is encountered
        else if(s[var]=='(')
            st.push('(');

    //when ")" is encountered
        else if(s[var]==')'){
           while(st.top()!='N' && st.top() != '(' ){
                char cha= st.top();
                st.pop();
                final+=cha;
           }
           if(st.top()=='(')
                st.pop();
        }
    //when operator encountered
        else {
            while(st.top()!='N' && precidance(s[var])< precidance(st.top())){
                char cha= st.top();
                st.pop();
                final+=cha;
            }
            if(precidance(s[var])== precidance(st.top())){
                st.push(s[var]);
            }
            else
                st.push(s[var]);

        }
    }
  //pop remaining elements from stack
  while(st.top()!='N'){
    char cha = st.top();
    st.pop();
    final+=cha;
  }
  reverse(final.begin(),final.end());
  cout<<final;
}


int main(){
    string exp =  "(a+b*(c+d/e)^f*g)";      //prefix +a**b^+c/defg
//choice of infix to postfix or to prefix
    int choice;
    cout<<"Choice:"<<endl<<"1.Infix to postfix"<<endl<<"2.Infix to prefix"<<endl;
    cin>>choice;
    if(choice==1)
        infixToPostfix(exp);
    else if(choice==2)
        infixToPrefix(exp);
    else
        cout<<"Invalid choice!!";
return 0;
}
