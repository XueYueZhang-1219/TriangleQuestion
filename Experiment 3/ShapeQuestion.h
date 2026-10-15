#ifndef SHAPE_QUESTION_H
#define SHAPE_QUESTION_H

#include <string>

// 图形题目基类：保存所有图形题目都有的共同数据和共同操作。
class ShapeQuestion
{
protected:
    int questionId;
    std::string shapeName;
    double userAreaAnswer;
    double userPerimeterAnswer;
    double correctArea;
    double correctPerimeter;
    bool answered;

    ShapeQuestion();
    ShapeQuestion(int id, const std::string& name);

    void setBasicInformation(int id, const std::string& name);
    void setCorrectAnswers(double area, double perimeter);

public:
    ~ShapeQuestion();

    int getQuestionId() const;
    std::string getShapeName() const;
    bool hasAnswered() const;
    bool isAreaAnswerCorrect() const;
    bool isPerimeterAnswerCorrect() const;

    void setUserAnswers(double areaAnswer, double perimeterAnswer);
    void displayAnswerResult() const;

    // 这是基类版本。派生类中有同名函数，体现“同名隐藏”。
    void displayQuestion() const;
};

// 正方形“是一个”图形题目，因此使用公有继承。
class SquareQuestion : public ShapeQuestion
{
private:
    double side;

public:
    SquareQuestion();
    SquareQuestion(int id, double sideLength);
    ~SquareQuestion();

    bool setQuestion(int id, double sideLength);
    double getSide() const;
    double calculateArea() const;
    double calculatePerimeter() const;
    void displayQuestion() const;
};

class RectangleQuestion : public ShapeQuestion
{
private:
    double length;
    double width;

public:
    RectangleQuestion();
    RectangleQuestion(int id, double rectangleLength, double rectangleWidth);
    ~RectangleQuestion();

    bool setQuestion(int id, double rectangleLength, double rectangleWidth);
    double getLength() const;
    double getWidth() const;
    double calculateArea() const;
    double calculatePerimeter() const;
    void displayQuestion() const;
};

class CircleQuestion : public ShapeQuestion
{
private:
    double radius;

public:
    CircleQuestion();
    CircleQuestion(int id, double circleRadius);
    ~CircleQuestion();

    bool setQuestion(int id, double circleRadius);
    double getRadius() const;
    double calculateArea() const;
    double calculatePerimeter() const;
    void displayQuestion() const;
};

class TriangleQuestion : public ShapeQuestion
{
private:
    double sideA;
    double sideB;
    double sideC;

    bool isValid(double a, double b, double c) const;

public:
    TriangleQuestion();
    TriangleQuestion(int id, double a, double b, double c);
    ~TriangleQuestion();

    bool setQuestion(int id, double a, double b, double c);
    double getSideA() const;
    double getSideB() const;
    double getSideC() const;
    double calculateArea() const;
    double calculatePerimeter() const;
    void displayQuestion() const;
};

class TrapezoidQuestion : public ShapeQuestion
{
private:
    double topBase;
    double bottomBase;
    double height;
    double leftSide;
    double rightSide;

public:
    TrapezoidQuestion();
    TrapezoidQuestion(
        int id,
        double top,
        double bottom,
        double trapezoidHeight,
        double left,
        double right);
    ~TrapezoidQuestion();

    bool setQuestion(
        int id,
        double top,
        double bottom,
        double trapezoidHeight,
        double left,
        double right);
    double calculateArea() const;
    double calculatePerimeter() const;
    void displayQuestion() const;
};

#endif
