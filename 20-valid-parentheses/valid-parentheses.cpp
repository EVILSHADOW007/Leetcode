#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if(st.empty()) return false;  // No matching opening bracket
                if(c == ')' && st.top() != '(') return false;
                if(c == ']' && st.top() != '[') return false;
                if(c == '}' && st.top() != '{') return false;
                st.pop();  // Pop the matching opening bracket
            }
        }
        
        return st.empty();  // Valid if no unmatched brackets remain
    }
};