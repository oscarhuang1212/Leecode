// File name:   LeetCode#150_Evaluate_Reverse_Polish_Notation.cpp
// Author:      Oscar Huang
// Description: Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//              Valid operators are +, -, *, /. Each operand may be an integer or another expression.
// Note:
//      Division between two integers should truncate toward zero.
//      The given RPN expression is always valid. 
//      That means the expression would always evaluate to a result and there won't be any divide by zero operation.
//Example 1:
//      Input: ["2", "1", "+", "3", "*"]
//      Output: 9
//      Explanation: ((2 + 1) * 3) = 9
//Example 2:
//      Input: ["4", "13", "5", "/", "+"]
//      Output: 6
//      Explanation: (4 + (13 / 5)) = 6
// Kyepoints: Stack implementation

#include  <iostream>
#include <string>
#include <vector>
#include <stack>


using namespace std;

int evalRPN(vector<string>& tokens);

int main(int argc, char *argv[]){

    vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    

    cout<<evalRPN(tokens)<<endl;
    cout<<evalRPN(tokens2)<<endl;
    cout<<evalRPN(tokens3)<<endl;
    
    return 0;
}


int evalRPN(vector<string>& tokens){
    

    stack<int> temp;
    for(int i=0; i<tokens.size();i++){
        //push the token into the stack if the next token is a number
        if(atoi(tokens[i].c_str()) || tokens[i][0]=='0')
            temp.push(atoi(tokens[i].c_str()));
        //Do the calculation between the top two elements if the next token is an operator
        else{
            int x = temp.top();
            temp.pop();
            int y = temp.top();
            temp.pop();

            if(tokens[i]=="+")
                temp.push(x+y);
            else if(tokens[i]=="-")
                temp.push(y-x);
            else if(tokens[i]=="*")
                temp.push(y*x);
            else    
                temp.push(y/x);
        }
    }
    
    return temp.top();
}






