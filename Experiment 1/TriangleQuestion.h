#ifndef TRIANGLE_QUESTION_H
#define TRIANGLE_QUESTION_H

// 实验一：三角形题目类
// 本文件只放类的声明，成员函数的定义放在 TriangleQuestion.cpp 中。
class TriangleQuestion
{
private:
    double sideA;
    double sideB;
    double sideC;

    bool isValid(double a, double b, double c) const;

public:
    TriangleQuestion();
    TriangleQuestion(double a, double b, double c);
    ~TriangleQuestion();

    bool setSides(double a, double b, double c);
    bool setSideA(double a);
    bool setSideB(double b);
    bool setSideC(double c);

    double getSideA() const;
    double getSideB() const;
    double getSideC() const;

    double calculatePerimeter() const;
    double calculateArea() const;

    void displayQuestion() const;
    void displayInformation() const;
    void displayType() const;
};

#endif
