#include "TriangleQuestion.h"

#include <cmath>
#include <iomanip>
#include <iostream>

TriangleQuestion::TriangleQuestion()
    : sideA(3.0), sideB(4.0), sideC(5.0)
{
}

TriangleQuestion::TriangleQuestion(double a, double b, double c)
    : sideA(3.0), sideB(4.0), sideC(5.0)
{
    setSides(a, b, c);
}

TriangleQuestion::~TriangleQuestion()
{
}

bool TriangleQuestion::isValid(double a, double b, double c) const
{
    return a > 0 && b > 0 && c > 0
        && a + b > c
        && a + c > b
        && b + c > a;
}

bool TriangleQuestion::setSides(double a, double b, double c)
{
    if (!isValid(a, b, c))
    {
        return false;
    }

    sideA = a;
    sideB = b;
    sideC = c;
    return true;
}

bool TriangleQuestion::setSideA(double a)
{
    return setSides(a, sideB, sideC);
}

bool TriangleQuestion::setSideB(double b)
{
    return setSides(sideA, b, sideC);
}

bool TriangleQuestion::setSideC(double c)
{
    return setSides(sideA, sideB, c);
}

double TriangleQuestion::getSideA() const
{
    return sideA;
}

double TriangleQuestion::getSideB() const
{
    return sideB;
}

double TriangleQuestion::getSideC() const
{
    return sideC;
}

double TriangleQuestion::calculatePerimeter() const
{
    return sideA + sideB + sideC;
}

double TriangleQuestion::calculateArea() const
{
    const double halfPerimeter = calculatePerimeter() / 2.0;
    return std::sqrt(
        halfPerimeter
        * (halfPerimeter - sideA)
        * (halfPerimeter - sideB)
        * (halfPerimeter - sideC));
}

void TriangleQuestion::displayQuestion() const
{
    std::cout << "已知三角形的三条边分别为 "
              << sideA << "、" << sideB << "、" << sideC
              << "，请计算它的周长和面积。" << std::endl;
}

void TriangleQuestion::displayInformation() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "三边：" << sideA << "，" << sideB << "，" << sideC << std::endl;
    std::cout << "周长：" << calculatePerimeter() << std::endl;
    std::cout << "面积：" << calculateArea() << std::endl;
    displayType();
}

void TriangleQuestion::displayType() const
{
    const double error = 0.000001;
    const bool abEqual = std::fabs(sideA - sideB) < error;
    const bool acEqual = std::fabs(sideA - sideC) < error;
    const bool bcEqual = std::fabs(sideB - sideC) < error;

    if (abEqual && acEqual)
    {
        std::cout << "类型：等边三角形" << std::endl;
        return;
    }

    const double aSquare = sideA * sideA;
    const double bSquare = sideB * sideB;
    const double cSquare = sideC * sideC;
    const bool isRight = std::fabs(aSquare + bSquare - cSquare) < error
        || std::fabs(aSquare + cSquare - bSquare) < error
        || std::fabs(bSquare + cSquare - aSquare) < error;

    if (isRight && (abEqual || acEqual || bcEqual))
    {
        std::cout << "类型：等腰直角三角形" << std::endl;
    }
    else if (isRight)
    {
        std::cout << "类型：直角三角形" << std::endl;
    }
    else if (abEqual || acEqual || bcEqual)
    {
        std::cout << "类型：等腰三角形" << std::endl;
    }
    else
    {
        std::cout << "类型：普通三角形" << std::endl;
    }
}
