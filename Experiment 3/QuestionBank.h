#ifndef QUESTION_BANK_H
#define QUESTION_BANK_H

#include "ShapeQuestion.h"

#include <string>

// 题库继续保留实验二的组合关系。
// 因为实验三还没有学习多态，所以不用 ShapeQuestion* 混装各种题目，
// 而是用五组固定对象数组分别保存五种派生类对象。
class QuestionBank
{
private:
    static const int MAX_QUESTIONS = 10;

    std::string bankName;
    SquareQuestion squareQuestions[MAX_QUESTIONS];
    RectangleQuestion rectangleQuestions[MAX_QUESTIONS];
    CircleQuestion circleQuestions[MAX_QUESTIONS];
    TriangleQuestion triangleQuestions[MAX_QUESTIONS];
    TrapezoidQuestion trapezoidQuestions[MAX_QUESTIONS];

    int squareCount;
    int rectangleCount;
    int circleCount;
    int triangleCount;
    int trapezoidCount;

    // questionTypes[i] 记录第 i 道题的种类，questionPositions[i] 记录它
    // 在对应对象数组中的位置。这样不需要 vector 和多态也能保存混合题目顺序。
    int questionTypes[MAX_QUESTIONS];
    int questionPositions[MAX_QUESTIONS];
    int questionCount;

    void displayQuestionAt(int index) const;
    void displayResultAt(int index) const;
    int getCorrectPartCountAt(int index) const;

public:
    QuestionBank();
    QuestionBank(const std::string& name);
    ~QuestionBank();

    int getQuestionCount() const;
    void generateRandomQuestions(int count);
    void displayAllQuestions() const;
    bool answerQuestion(int questionNumber, double areaAnswer, double perimeterAnswer);
    void displayAllResults() const;
    void displayScore() const;
};

#endif
