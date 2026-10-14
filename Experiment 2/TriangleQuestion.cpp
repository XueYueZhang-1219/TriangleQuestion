#include "TriangleQuestion.h"

#include <cmath>
#include <iomanip>
#include <iostream>

TriangleQuestion::TriangleQuestion()
    : questionId(0),
      sideA(3.0),
      sideB(4.0),
      sideC(5.0),
      userAreaAnswer(0.0),
      userPerimeterAnswer(0.0),
      answered(false)
{
}

TriangleQuestion::TriangleQuestion(int id, double a, double b, double c)
    : questionId(id),
      sideA(3.0),
      sideB(4.0),
      sideC(5.0),
      userAreaAnswer(0.0),
      userPerimeterAnswer(0.0),
      answered(false)
{
    if (isValid(a, b, c))
    {
        sideA = a;
        sideB = b;
        sideC = c;
    }
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

    questionId = id;
    sideA = a;
    sideB = b;
    sideC = c;
    userAreaAnswer = 0.0;
    userPerimeterAnswer = 0.0;
    answered = false;
    return true;
}

void TriangleQuestion::setQuestionId(int id)
{
    questionId = id;
}

void TriangleQuestion::setUserAnswers(double areaAnswer, double perimeterAnswer)
{
    userAreaAnswer = areaAnswer;
    userPerimeterAnswer = perimeterAnswer;
    answered = true;
}

int TriangleQuestion::getQuestionId() const
{
    return questionId;
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

double TriangleQuestion::getUserAreaAnswer() const
{
    return userAreaAnswer;
}

double TriangleQuestion::getUserPerimeterAnswer() const
{
    return userPerimeterAnswer;
}

bool TriangleQuestion::hasAnswered() const
{
    return answered;
}

double TriangleQuestion::calculateArea() const
{
    double halfPerimeter = calculatePerimeter() / 2.0;
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

bool TriangleQuestion::isAreaAnswerCorrect() const
{
    const double error = 0.01;
    return answered && std::fabs(userAreaAnswer - calculateArea()) < error;
}

bool TriangleQuestion::isPerimeterAnswerCorrect() const
{
    const double error = 0.01;
    return answered && std::fabs(userPerimeterAnswer - calculatePerimeter()) < error;
}

void TriangleQuestion::displayQuestion() const
{
    std::cout << "题目" << questionId
              << "：三角形三边为 " << sideA << "、" << sideB << "、" << sideC
              << "，请计算面积和周长。" << std::endl;
}

void TriangleQuestion::displayResult() const
{
    std::cout << std::fixed << std::setprecision(2);
    displayQuestion();

    if (!answered)
    {
        std::cout << "状态：尚未作答" << std::endl;
        return;
    }

    std::cout << "面积：你的答案为 " << userAreaAnswer
              << "，正确答案为 " << calculateArea()
              << "，" << (isAreaAnswerCorrect() ? "回答正确" : "回答错误")
              << std::endl;
    std::cout << "周长：你的答案为 " << userPerimeterAnswer
              << "，正确答案为 " << calculatePerimeter()
              << "，" << (isPerimeterAnswerCorrect() ? "回答正确" : "回答错误")
              << std::endl;
}
