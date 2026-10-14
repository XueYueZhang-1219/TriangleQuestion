#ifndef TRIANGLE_QUESTION_H
#define TRIANGLE_QUESTION_H

// 实验二中的部分类：一道三角形计算题。
class TriangleQuestion
{
private:
    int questionId;
    double sideA;
    double sideB;
    double sideC;
    double userAreaAnswer;
    double userPerimeterAnswer;
    bool answered;

    bool isValid(double a, double b, double c) const;

public:
    TriangleQuestion();
    TriangleQuestion(int id, double a, double b, double c);
    ~TriangleQuestion();

    bool setQuestion(int id, double a, double b, double c);
    void setQuestionId(int id);
    void setUserAnswers(double areaAnswer, double perimeterAnswer);

    int getQuestionId() const;
    double getSideA() const;
    double getSideB() const;
    double getSideC() const;
    double getUserAreaAnswer() const;
    double getUserPerimeterAnswer() const;
    bool hasAnswered() const;

    double calculateArea() const;
    double calculatePerimeter() const;
    bool isAreaAnswerCorrect() const;
    bool isPerimeterAnswerCorrect() const;

    void displayQuestion() const;
    void displayResult() const;
};

#endif
