#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(const string& s) {
    stack<int> st;
    st.push(-1); // base index
    int maxLen = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);  // reset base index
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }

    return maxLen;
}

int main() {
    string s = ")()())";
    cout << "Longest valid parentheses length: " << longestValidParentheses(s) << endl;
    return 0;
}
