#include "ShapeQuestion.h"

#include <cmath>
#include <iomanip>
#include <iostream>

ShapeQuestion::ShapeQuestion()
    : questionId(0),
      shapeName("图形"),
      userAreaAnswer(0.0),
      userPerimeterAnswer(0.0),
      correctArea(0.0),
      correctPerimeter(0.0),
      answered(false)
{
}

ShapeQuestion::ShapeQuestion(int id, const std::string& name)
    : questionId(id),
      shapeName(name),
      userAreaAnswer(0.0),
      userPerimeterAnswer(0.0),
      correctArea(0.0),
      correctPerimeter(0.0),
      answered(false)
{
}

ShapeQuestion::~ShapeQuestion()
{
}

void ShapeQuestion::setBasicInformation(int id, const std::string& name)
{
    questionId = id;
    shapeName = name;
    userAreaAnswer = 0.0;
    userPerimeterAnswer = 0.0;
    answered = false;
}

void ShapeQuestion::setCorrectAnswers(double area, double perimeter)
{
    correctArea = area;
    correctPerimeter = perimeter;
}

int ShapeQuestion::getQuestionId() const
{
    return questionId;
}

std::string ShapeQuestion::getShapeName() const
{
    return shapeName;
}

bool ShapeQuestion::hasAnswered() const
{
    return answered;
}

bool ShapeQuestion::isAreaAnswerCorrect() const
{
    const double error = 0.01;
    return answered && std::fabs(userAreaAnswer - correctArea) < error;
}

bool ShapeQuestion::isPerimeterAnswerCorrect() const
{
    const double error = 0.01;
    return answered && std::fabs(userPerimeterAnswer - correctPerimeter) < error;
}

void ShapeQuestion::setUserAnswers(double areaAnswer, double perimeterAnswer)
{
    userAreaAnswer = areaAnswer;
    userPerimeterAnswer = perimeterAnswer;
    answered = true;
}

void ShapeQuestion::displayAnswerResult() const
{
    std::cout << std::fixed << std::setprecision(2);

    if (!answered)
    {
        std::cout << "状态：尚未作答" << std::endl;
        return;
    }

    std::cout << "面积：你的答案为 " << userAreaAnswer
              << "，正确答案为 " << correctArea
              << "，" << (isAreaAnswerCorrect() ? "回答正确" : "回答错误")
              << std::endl;
    std::cout << "周长：你的答案为 " << userPerimeterAnswer
              << "，正确答案为 " << correctPerimeter
              << "，" << (isPerimeterAnswerCorrect() ? "回答正确" : "回答错误")
              << std::endl;
}

void ShapeQuestion::displayQuestion() const
{
    std::cout << "题目" << questionId << "：这是一道" << shapeName
              << "的面积和周长计算题。" << std::endl;
}

SquareQuestion::SquareQuestion()
    : ShapeQuestion(0, "正方形"), side(1.0)
{
    setCorrectAnswers(calculateArea(), calculatePerimeter());
}

SquareQuestion::SquareQuestion(int id, double sideLength)
    : ShapeQuestion(id, "正方形"), side(1.0)
{
    setQuestion(id, sideLength);
}

SquareQuestion::~SquareQuestion()
{
}

bool SquareQuestion::setQuestion(int id, double sideLength)
{
    if (sideLength <= 0)
    {
        return false;
    }

    setBasicInformation(id, "正方形");
    side = sideLength;
    setCorrectAnswers(calculateArea(), calculatePerimeter());
    return true;
}

double SquareQuestion::getSide() const
{
    return side;
}

double SquareQuestion::calculateArea() const
{
    return side * side;
}

double SquareQuestion::calculatePerimeter() const
{
    return 4.0 * side;
}

void SquareQuestion::displayQuestion() const
{
    std::cout << "题目" << questionId << "：正方形边长为 " << side
              << "，请计算面积和周长。" << std::endl;
}

RectangleQuestion::RectangleQuestion()
    : ShapeQuestion(0, "长方形"), length(1.0), width(1.0)
{
    setCorrectAnswers(calculateArea(), calculatePerimeter());
}

RectangleQuestion::RectangleQuestion(
    int id,
    double rectangleLength,
    double rectangleWidth)
    : ShapeQuestion(id, "长方形"), length(1.0), width(1.0)
{
    setQuestion(id, rectangleLength, rectangleWidth);
}

RectangleQuestion::~RectangleQuestion()
{
}

bool RectangleQuestion::setQuestion(
    int id,
    double rectangleLength,
    double rectangleWidth)
{
    if (rectangleLength <= 0 || rectangleWidth <= 0)
    {
        return false;
    }

    setBasicInformation(id, "长方形");
    length = rectangleLength;
    width = rectangleWidth;
    setCorrectAnswers(calculateArea(), calculatePerimeter());
    return true;
}

double RectangleQuestion::getLength() const
{
    return length;
}

double RectangleQuestion::getWidth() const
{
    return width;
}

double RectangleQuestion::calculateArea() const
{
    return length * width;
}

double RectangleQuestion::calculatePerimeter() const
{
    return 2.0 * (length + width);
}

void RectangleQuestion::displayQuestion() const
{
    std::cout << "题目" << questionId << "：长方形长为 " << length
              << "，宽为 " << width << "，请计算面积和周长。" << std::endl;
}

CircleQuestion::CircleQuestion()
    : ShapeQuestion(0, "圆形"), radius(1.0)
{
    setCorrectAnswers(calculateArea(), calculatePerimeter());
}

CircleQuestion::CircleQuestion(int id, double circleRadius)
    : ShapeQuestion(id, "圆形"), radius(1.0)
{
    setQuestion(id, circleRadius);
}

CircleQuestion::~CircleQuestion()
{
}

bool CircleQuestion::setQuestion(int id, double circleRadius)
{
    if (circleRadius <= 0)
    {
        return false;
    }

    setBasicInformation(id, "圆形");
    radius = circleRadius;
    setCorrectAnswers(calculateArea(), calculatePerimeter());
    return true;
}

double CircleQuestion::getRadius() const
{
    return radius;
}

double CircleQuestion::calculateArea() const
{
    const double pi = 3.14159;
    return pi * radius * radius;
}

double CircleQuestion::calculatePerimeter() const
{
    const double pi = 3.14159;
    return 2.0 * pi * radius;
}

void CircleQuestion::displayQuestion() const
{
    std::cout << "题目" << questionId << "：圆的半径为 " << radius
              << "，请计算面积和周长。圆周率取3.14159。" << std::endl;
}

TriangleQuestion::TriangleQuestion()
    : ShapeQuestion(0, "三角形"), sideA(3.0), sideB(4.0), sideC(5.0)
{
    setCorrectAnswers(calculateArea(), calculatePerimeter());
}

TriangleQuestion::TriangleQuestion(int id, double a, double b, double c)
    : ShapeQuestion(id, "三角形"), sideA(3.0), sideB(4.0), sideC(5.0)
{
    setQuestion(id, a, b, c);
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

bool TriangleQuestion::setQuestion(int id, double a, double b, double c)
{
    if (!isValid(a, b, c))
    {
        return false;
    }

    setBasicInformation(id, "三角形");
    sideA = a;
    sideB = b;
    sideC = c;
    setCorrectAnswers(calculateArea(), calculatePerimeter());
    return true;
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

double TriangleQuestion::calculateArea() const
{
    const double halfPerimeter = calculatePerimeter() / 2.0;
    return std::sqrt(
        halfPerimeter
        * (halfPerimeter - sideA)
        * (halfPerimeter - sideB)
        * (halfPerimeter - sideC));
}

double TriangleQuestion::calculatePerimeter() const
{
    return sideA + sideB + sideC;
}

void TriangleQuestion::displayQuestion() const
{
    std::cout << "题目" << questionId << "：三角形三边为 "
              << sideA << "、" << sideB << "、" << sideC
              << "，请计算面积和周长。" << std::endl;
}

TrapezoidQuestion::TrapezoidQuestion()
    : ShapeQuestion(0, "梯形"),
      topBase(2.0),
      bottomBase(4.0),
      height(3.0),
      leftSide(std::sqrt(10.0)),
      rightSide(std::sqrt(10.0))
{
    setCorrectAnswers(calculateArea(), calculatePerimeter());
}

TrapezoidQuestion::TrapezoidQuestion(
    int id,
    double top,
    double bottom,
    double trapezoidHeight,
    double left,
    double right)
    : ShapeQuestion(id, "梯形"),
      topBase(2.0),
      bottomBase(4.0),
      height(3.0),
      leftSide(std::sqrt(10.0)),
      rightSide(std::sqrt(10.0))
{
    setQuestion(id, top, bottom, trapezoidHeight, left, right);
}

TrapezoidQuestion::~TrapezoidQuestion()
{
}

bool TrapezoidQuestion::setQuestion(
    int id,
    double top,
    double bottom,
    double trapezoidHeight,
    double left,
    double right)
{
    if (top <= 0 || bottom <= 0 || trapezoidHeight <= 0
        || left <= 0 || right <= 0)
    {
        return false;
    }

    setBasicInformation(id, "梯形");
    topBase = top;
    bottomBase = bottom;
    height = trapezoidHeight;
    leftSide = left;
    rightSide = right;
    setCorrectAnswers(calculateArea(), calculatePerimeter());
    return true;
}

double TrapezoidQuestion::calculateArea() const
{
    return (topBase + bottomBase) * height / 2.0;
}

double TrapezoidQuestion::calculatePerimeter() const
{
    return topBase + bottomBase + leftSide + rightSide;
}

void TrapezoidQuestion::displayQuestion() const
{
    std::cout << "题目" << questionId << "：梯形上底为 " << topBase
              << "，下底为 " << bottomBase << "，高为 " << height
              << "，两腰分别为 " << leftSide << "、" << rightSide
              << "，请计算面积和周长。" << std::endl;
}
