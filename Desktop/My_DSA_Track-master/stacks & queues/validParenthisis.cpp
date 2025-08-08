#include<iostream>
#include<stack>
using namespace std;

bool validParenthisis(string s){
  stack<char> st;
    for(auto i : s){
    if(i == '(' || i == '[' || i == '{' ){
        st.push(i);
    }
    else{
        if (st.empty()) return false;
        char ch= st.top();
        if((i == ')' and ch == '(') || (i == ']' and ch == '[') || (i == '}' and ch == '{')){
            st.pop();
            
          }

          else return false;
    }

    }

    return st.empty();
    
}

int main(){

    string s ="()[{]}";
    if(validParenthisis(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;


    return 0;
}