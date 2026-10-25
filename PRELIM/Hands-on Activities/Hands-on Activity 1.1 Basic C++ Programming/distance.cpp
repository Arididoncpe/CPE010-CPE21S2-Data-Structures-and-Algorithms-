#include <iostream>
#include <cmath>

float calculateDistance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1,2));
}

int main() {
    float x1, y1, x2, y2;
    std::cout << "Enter the coordinates of the first point (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the coordinates of the second point (x2, y2): ";
    std::cin >> x2 >> y2;
    std::cout << "The distance between the two points is: " << calculateDistance(x1, y1, x2, y2) << std::endl;
    return 0;
}