#include <iostream>
#include <string>

#define maxCap 100

// Global declarations
char stackArr[maxCap];
int topIndex = -1;


// Prototype functions
void push(char newData);
char pop();
bool isEmpty();
bool isFull();
bool match(char open, char close);
bool balanced(std::string expression);


// Main driver
int main() {

    std::string expression;

    std::cout << "Enter expression: ";
    getline(std::cin, expression);

    if (balanced(expression)) {
        std::cout << "Expression is Balanced." << std::endl;
    }
    else {
        std::cout << "Expression is NOT Balanced." << std::endl;
    }

    return 0;
}


// Check if stack is empty
bool isEmpty() {
    if (topIndex == -1)
        return true;

    return false;
}


// Check if stack is full
bool isFull() {
    if (topIndex == maxCap - 1)
        return true;

    return false;
}


// Push operation
void push(char newData) {

    if (isFull()) {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }

    stackArr[++topIndex] = newData;
}


// Pop operation
char pop() {

    if (isEmpty()) {
        return '\0';
    }

    return stackArr[topIndex--];
}


// Check matching symbols
bool match(char open, char close) {

    if (open == '(' && close == ')')
        return true;

    if (open == '{' && close == '}')
        return true;

    if (open == '[' && close == ']')
        return true;

    return false;
}


// Balanced symbol checker
bool balanced(std::string expression) {

    for (char ch : expression) {

        // If opening symbol, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {

            push(ch);

        }

        // If closing symbol, check stack
        else if (ch == ')' || ch == '}' || ch == ']') {

            if (isEmpty())
                return false;

            char temp = pop();

            if (!match(temp, ch))
                return false;
        }
    }


    // If stack is empty, all symbols matched
    return isEmpty();
}