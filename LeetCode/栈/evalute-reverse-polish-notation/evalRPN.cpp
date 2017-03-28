/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are+,-,*,/. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.size()==0)return 0;
        stack<int> production;
        for(int i=0;i<tokens.size();++i)
        {
            string s = tokens[i];
            if(s=="+"||s=="-"||s=="/"||s=="*")
            {
                if(production.size()<2)return 0;
                int result = 0;
                int num2 = production.top();
                production.pop();
                int num1 = production.top();
                production.pop();
                if(s=="+")result = num1+num2;
                else if(s=="-")result = num1-num2;
                else if(s=="*")result = num1*num2;
                else result = num1/num2;
                production.push(result); 
            }
            else production.push(atoi(s.c_str()));
        }
        return production.top();
    }
};