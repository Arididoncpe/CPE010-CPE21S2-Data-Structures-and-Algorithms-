#include <iostream>

class Triangle {

private:
        double totalAngle, angleA, angleB, angleC;
public: 
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    const bool validateTriangle();
};
Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}

double calculateArea(double base, double height) {
    return (0.5 * base * height);
}

double calculatePerimeter(double sideA, double sideB, double sideC) {
    return (sideA + sideB + sideC);
}

std::string classifyTriangleAngles(double angleA, double angleB, double angleC) {
    if (angleA < 90 && angleB < 90 && angleC < 90) {
        return "The triangle is an acute triangle.";
    } else if (angleA == 90 || angleB == 90 || angleC == 90) {
        return "The triangle is a right triangle.";
    } else {
        return "The triangle is an obtuse triangle.";
    }
}

int main(){
    double angleA, angleB, angleC;
    double sideA, sideB, sideC, base, height;
    
    std::cout << "Enter the angles of the triangle: ";
    std::cin >> angleA >> angleB >> angleC;

    Triangle set1(angleA, angleB, angleC);

    if (set1.validateTriangle()){
        std::cout << "The shape is a valid triangle " << std::endl;
        std::cout << "Enter base and height of the triangle: ";
        std::cin >> base >> height;

        std::cout << "The area of the triangle is: " << calculateArea(base, height) << std::endl;
        std::cout << "Enter the lengths of the three sides of the triangle: ";
        std::cin >> sideA >> sideB >> sideC;

        std::cout << "The perimeter of the triangle is: " << calculatePerimeter(sideA, sideB, sideC) << std::endl;
        std::cout << classifyTriangleAngles(angleA, angleB, angleC) << std::endl;
    }
    else {
        std::cout << "The shape is NOT a valid triangle " << std::endl;
    }
    return 0;



   

}