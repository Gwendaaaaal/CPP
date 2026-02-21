#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

static bool isOperatorToken(const std::string& tok)
{
    return (tok.size() == 1 && (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/'));
}

static bool isDigitToken(const std::string& tok)
{
    return (tok.size() == 1 && std::isdigit(static_cast<unsigned char>(tok[0])));
}

static int applyOp(int a, int b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/')
    {
        if (b == 0)
            throw std::runtime_error("Error");
        return a / b;
    }
    throw std::runtime_error("Error");
}

int RPN(const std::string& expr)
{
    std::stack<int> st;
    std::stringstream ss(expr);
    std::string tok;

    while (ss >> tok)
    {
        if (isDigitToken(tok))
        {
            st.push(tok[0] - '0');
        }
        else if (isOperatorToken(tok))
        {
            if (st.size() < 2)
                throw std::runtime_error("Error");

            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            int res = applyOp(a, b, tok[0]);
            st.push(res);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (st.size() != 1)
        throw std::runtime_error("Error");

    return st.top();
}
