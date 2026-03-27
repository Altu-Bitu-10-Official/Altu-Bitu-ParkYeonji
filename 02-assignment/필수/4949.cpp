#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    while (true) {
        string s;
        getline(cin, s);

        if (s == ".") break;

        stack<char> st;
        bool check = true;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            }

            else if (s[i] == ')') {
                if (st.empty() == true || st.top() != '(') {
                    check = false;
                }

                else {
                    st.pop();
                }
            }

            else if (s[i] == ']') {
                if (st.empty() == true || st.top() != '[') {
                    check = false;
                }
                else {
                    st.pop();
                }
            }
        }

        if (st.empty() == false) {
            check = false;
        }
        if (check == true) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}
