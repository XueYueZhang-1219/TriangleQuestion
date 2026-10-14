#ifndef QUESTION_BANK_H
#define QUESTION_BANK_H

#include "TriangleQuestion.h"

#include <string>

// 实验二中的整体类：题库由若干个 TriangleQuestion 对象组成。
class QuestionBank
{
private:
    std::string bankName;
    TriangleQuestion questions[10];
    int questionCount;
    int totalScore;
    double averageScore;

    int findQuestionIndex(int questionId) const;

public:
    QuestionBank();
    QuestionBank(const std::string& name);
    ~QuestionBank();

    void setBankName(const std::string& name);
    std::string getBankName() const;
    int getQuestionCount() const;
    int getTotalScore() const;
    double getAverageScore() const;

    // 参数中使用 TriangleQuestion 的引用，体现依赖关系。
    bool addQuestion(const TriangleQuestion& question);
    bool deleteQuestion(int questionId);
    bool answerQuestion(int questionId, double areaAnswer, double perimeterAnswer);

    void calculateScore();
    void displayAllQuestions() const;
    void queryQuestion(int questionId) const;
    void displayScore() const;
};

#endif
