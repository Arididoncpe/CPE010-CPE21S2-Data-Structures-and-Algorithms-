#include <iostream>
#include <string>

#define maxCap 100

// Global declarations
char stackArr[maxCap];
char stackArr2[maxCap];
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

    if (open == close && close == open)
        return true;

    if (open == '1' && close == '1')
        return true;

    if (open == '2' && close == '2')
        return true;

    if (open == '3' && close == '3')
        return true;
    
    if (open == '4' && close == '4')
        return true;

    if (open == '5' && close == '5')
        return true;

    if (open == '6' && close == '6')
        return true;

    if (open == '7' && close == '7')
        return true;

    if (open == '8' && close == '8')
        return true;

    if (open == '9' && close == '9')
        return true;

    return false;
}


// Balanced symbol checker
bool balanced(std::string expression) {

    for (char ch : expression) {

        // If opening symbol, push to stack
        if (ch == '1' || ch == '2' || ch == '3' == ch == '4' || ch == '5' || ch == '6' == ch == '(' || ch == '7' || ch == '8' || ch == '9') {

           stackArr[] = push(ch);

        }

        // If closing symbol, check stack
        else if (ch == '1' || ch == '2' || ch == '3' == ch == '4' || ch == '5' || ch == '6' == ch == '(' || ch == '7' || ch == '8' || ch == '9') {

            if (isEmpty())
                return false;

            char stackArr2 = pop();

            if (match(stackArr2, ch))
                return false;
        }
        
             
    }


    // If stack is empty, all symbols matched
    return isEmpty();
}