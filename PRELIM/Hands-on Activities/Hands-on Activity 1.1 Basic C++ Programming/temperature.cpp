#include <iostream>

double convertKelvinToFahrenheit(double K) {
    return (K - 273.15) * 9.0 / 5.0 + 32.0;
}

int main() {
    double K;
    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> K;
    std::cout << "Temperature in Fahrenheit: " << convertKelvinToFahrenheit(K)  << std::endl;
}