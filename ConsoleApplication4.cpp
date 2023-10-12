#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& s) {
    std::stack<char> stack;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                stack.pop();
            }
            else {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    std::string input;
    std::cout << "Введите строку с скобками: ";
    std::cin >> input;

    if (isBalanced(input)) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
