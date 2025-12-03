//question 1
#include<iostream>
#include<stack>
using namespace std;
// class Stack{
//     int *arr;
//     int top;
//     int size;
//     public:
//     Stack(int capacity){
//         this->size = capacity;
//         this->arr = new int[size];
//         this->top = -1;

//     }
//     void push(int value){
//         if(this->top == this->size - 1){
//             cout<<"overflow"<<endl;
//             return;
//         }
//         else{
//             this->top++;
//             this->arr[this->top] = value;
//         }
//     }
//     void pop(){
//         if(this->top == -1){
//             cout<<"Underflow"<<endl;
//             return;
//         }
//         else{
//             this->top--;
//         }
//     }
//     bool isEmpty(){
//         return this->top == -1;
//     }
//     bool isFull(){
//         return this->top == this->size - 1;
//     }
//     int peek(){
//         if(this->top == -1){
//             cout<<"Underflow"<<endl;
//             return -1;
//         }
//         else{
//             return this->arr[this->top];
//         }
//     }
//     void display(){
//        for(int i = top;i>=0;i--){
//         cout<<arr[i]<<endl;
//        }
//     }
// };
// int precedence(char ch){
//     if(ch == '+' || ch == '-') return 1;
//     if(ch == '*' || ch == '/') return 2;
//     return 0;
// }
int main(){
    // int n;
    // cout<<"Enter the size of stack : ";cin>>n;
    // Stack st(n);
    // int x;
    // do{
        
    //     cout<<"Enter your operation for stack: "<<endl;
    //     cout<<"1 for push "<<endl;
    //     cout<<"2 for pop "<<endl;
    //     cout<<"3 for isEmpty "<<endl;
    //     cout<<"4 for isFull "<<endl;
    //     cout<<"5 for display "<<endl;
    //     cout<<"6 for peek "<<endl;
    //     cout<<"7 for break "<<endl;
    //     cin>>x;
    //     switch(x){
    //         case 1:
    //             int l;
    //             cout<<"Enter the element to be pushed : ";cin>>l;
    //             st.push(l);
    //             break;
    //         case 2:
    //             st.pop();
    //             break;
    //         case 3:
    //             if(st.isEmpty()==1)cout<<"Yes,it's empty.";
    //             else cout<<"Not empty";
    //             break;
    //         case 4:
    //             if(st.isFull()==1) cout<<"Yes , it's full";
    //             else cout<<"No, it's not full";
    //             break;
    //         case 5:
    //             cout<<"The stack is : "<<endl;
    //             st.display();
    //             break;
    //         case 6:
    //             cout<<"the top element is : "<<st.peek()<<endl;
    //             break;
    //         case 7:break;
    //         default : cout<<"invalid input";

            

    //     }


    // }while (x!=7);
    //question 2
    
    // string str = "DataStructure";
    // Stack st1(str.length());
    // for(int i = 0;i<str.length();i++){
    //     st1.push(str[i]);

    // }
    // for(int i = 0;i<str.length();i++){
    //     char ch = st1.peek();
    //     st1.pop();
    //     cout<<ch;
    // }
    
    //question 3 (program to check if the expression has balanced parenthesis )
    // string expr = "()()";
    // int a = 0;
    // Stack st2(expr.length());
    // for(int i = 0;i<expr.length();i++){
    //     if(expr[i] == '(') st2.push(expr[i]);
    //     else{
    //         if(st2.isEmpty()){
    //             cout<<"Unbalanced parentheses";
    //             a = 1;
    //             break;

    //         }
    //         else st2.pop();
    //     }
    // }
    // if (a==0) cout<<"balanced parentheses";
    //question 4. 
    //infix to postfix 
//     string expr2 = "A*(B+C-D)";
//     stack<char> st3;//here in this question, stack STL has been used.
//     string postfix;
//     for(int i=0;i<expr2.length();i++){
//        if(isalpha(expr2[i])||isdigit(expr2[i])) postfix += expr2[i];
//        else{
//         if(expr2[i]=='(') st3.push(expr2[i]);
//         else if(expr2[i]==')'){
//             while(!st3.empty() && st3.top() != '(' ) {postfix += st3.top();st3.pop();
//         }
//         st3.pop();
//        }
//        else{
//         while(!st3.empty() && precedence(expr2[i]) <= precedence(st3.top())){
//             char ch1 = st3.top();
//             st3.pop();
//             postfix += ch1;
            

//         }
//         st3.push(expr2[i]);
//        }


//     }
    
// }
// //pop remaining elements 
// while(!st3.empty()){
//     postfix += st3.top();
//     st3.pop();
// }
// for(int i=0;i<postfix.length();i++){
    
//     cout<<postfix[i];
// }
//question 4 evaluating the postfix. 
// string str = "23*84/+";
// int i = 0;
// stack<int> st4;
// while(i<str.length()){
//     while(str[i] != '*' && str[i] != '/' && str[i]!='+' && str[i]!='-'){
        
//         st4.push(str[i]-'0');
//         i++;
        

//     }
//     int ob2 = st4.top();st4.pop();
//     int ob1 = st4.top();st4.pop();
//     if(str[i] == '+') st4.push(ob1+ob2);
//     if(str[i] == '-') st4.push(ob1-ob2);
//     if(str[i] == '*') st4.push(ob1*ob2);
//     if(str[i] == '/') st4.push(ob1/ob2);
//     i++;

// }
// cout<<"the solution is "<<st4.top();
//in question 4 and 5 stack STL has been used.

    

    return 0;
}