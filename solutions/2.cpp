#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>
using namespace std;


int calculate(int oper1, int oper2, char chr)
{
    switch (chr)
    {
        case '+':
            return oper1 + oper2;
        case '-':
            return oper1 - oper2;
        case '*':
            return oper1 * oper2;
        case '/':
            return oper1 / oper2;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    std::fstream myfile("/Users/HAM/Desktop/inputs/2.txt", std::ios_base::in);
    string s;
    stack<int> st;
    while (myfile >> s) {
        for (int i = (int)s.size()-1; i >=0; --i) {
            if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/') {
                int opr1 = st.top();
                st.pop();
                int opr2 = st.top();
                st.pop();
                st.push(calculate(opr1,opr2,s[i]));
            }
            else
                st.push((int)(s[i]-'0'));
            
        }
        cout << st.top() << endl;
    }
    
    
    
    return 0;
}
