// Problem:
// A bracket is any one of the following characters: () {} []. Given a string,
// determine whether the brackets is balanced.
// 
// Example:
// Input: {[(])}
// Output: false
// 
// Solution:
// Use a stack, push opening braskets, and pop and match closing braskets. If
// any closing brasket does not match, or stack is empty when a closing brasket
// is encountered, or stack is not empty at the end, it is not balanced.

bool is_balanced(string str)
{
    stack<char> stk;
    int i;
    
    for (i = 0; i < str.size(); i++) {
        switch (str[i]) {
            case '{':
            case '[':
            case '(':
                stk.push(str[i]);
                break;
            case '}':
                if (!stk.empty() && stk.top() == '{') stk.pop();
                else return false;
                break;
            case ']':
                if (!stk.empty() && stk.top() == '[') stk.pop();
                else return false;
                break;
            case ')':
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else return false;
                break;
            default:
                return false;
        }
    }
    
    return stk.empty();
}