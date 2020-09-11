//Evaluate the postfix expression

#include<bits/stdc++.h>

using namespace std;

void evaluate(string s){
    int l = s.length();
    stack<int> st;
    //iteration through string
    for(int i=0;i<l;i++){

    //digit encountered
        if(s[i]>='0' && s[i]<='9')//stack holds int type  so to compare we have to do in same type
           st.push(s[i]-'0');//to push int type we have to convert char type into int type done by subtraction of ASCII value or other methods
           //for example if s[i]='2' its ASCII value is 50 and ASCII value of 0 is 48
           //so 50-48 gives integer value 2 then only it can be pushed into the stack that holds int type data

    //operator
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ){
            //pop two variables
                int var1 = st.top(); //error line
                st.pop();
                int var2=st.top();
                st.pop();
                int var3;
            //operate and push to stack
                if(s[i] == '+'){
                    var3= var2+var1;
                    st.push(var3);
                }
                else if(s[i] == '-'){
                    var3= var2-var1;
                    st.push(var3);
                }
                else if(s[i] == '*'){
                    var3= var2*var1;
                    st.push(var3);
                }
                else if(s[i] == '/'){
                    var3= var2/var1;
                    st.push(var3);
                }
            }
        else
            continue;
    }
    cout<<"Final answer: "<<st.top();
}

int main(){
    string exp="43-45-3+*2/";
    cout<<exp<<endl;
    evaluate(exp);
return 0;
}
