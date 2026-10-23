#include <iostream>

int main(){
int a,b,c;
a = 8;
b = 7;
c = a;
a = b;
b = c;
std::cout << "a = " << a << std::endl;
std::cout << "b = " << b << std::endl;
}