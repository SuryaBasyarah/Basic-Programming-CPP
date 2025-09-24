#include <iostream>
#include <cstring>
#include <cctype>
#include <stack>

using namespace std;

int postfix(string stEXP)
{
    stack<int> st;

    for (int i = 0; i < stEXP.size(); i++)
    {
        if (isdigit(stEXP[i]))
        {
            st.push(stEXP[i] - '0');
        }

        else
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            switch (stEXP[i])
            {
            case '+':
                st.push(num2 + num1);
                break;
            
            case '-':
                st.push(num2 - num1);
                break;

            case '*':
                st.push(num2 * num1);
                break;

            case '/':
                st.push(num2 / num1);
                break;

            default:
                break;
            }
        }
    }
    return st.top();
}

int main()
{

    string sEXP = "56*";
    cout << "Total value: " << postfix(sEXP) << endl;
    cout << endl;
    sEXP = "561+*";
    cout << "Total value: " << postfix(sEXP) << endl;
    cout << endl;
    sEXP = "56*9-";
    cout << "Total value: " << postfix(sEXP) << endl;
    cout << endl;
    sEXP = "456*3/+";
    cout << "Total value: " << postfix(sEXP);
    return 0;
}