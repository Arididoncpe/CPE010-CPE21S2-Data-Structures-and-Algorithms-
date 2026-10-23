#include <iostream>
#include <string>

int sum(int fNum, int sNum) {
    return fNum + sNum;
} 

std::string compare(int v1, int v2) {
    if (v1 > v2) {
        return "Variable A is greater than Variable B";
    }
    else if (v1 < v2)  {
        return "Variable B is greater than Variable A";
    }
    else {
        return "Variable A and B are both equal";
    }
}

bool compareBool(bool a, bool b) {
    std::cout << "a && b = " << (a && b) << std::endl;
    std::cout << "a || b = " << (a || b) << std::endl;
    std::cout << "!a = " << (!a) << std::endl;
    std::cout << "!b = " << (!b) << std::endl;

return true;
}


int main() {
    int fNum, sNum, v1, v2;
    bool a, b;
    std::cout << "Enter first number: ";
    std::cin >> fNum;
    std::cout << "Enter second number: ";
    std::cin >> sNum;
    std::cout << "The sum is: " << sum(fNum, sNum) << std::endl;
    
    std::cout << "Enter variable A: ";
    std::cin >> v1;
    std::cout << "Enter variable B: ";
    std::cin >> v2;
    std::cout << compare(v1, v2) << std::endl;

    std::cout << "Enter first boolean value(1 or 0): ";
    std::cin >> a;
    std::cout << "Enter second boolean value(1 or 0): ";
    std::cin >> b;
    std::cout << compareBool(a,b);

    return 0;


}