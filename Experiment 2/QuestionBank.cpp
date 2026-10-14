#include "QuestionBank.h"

#include <iomanip>
#include <iostream>

QuestionBank::QuestionBank()
    : bankName("三角形练习题库"),
      questionCount(0),
      totalScore(0),
      averageScore(0.0)
{
}

QuestionBank::QuestionBank(const std::string& name)
    : bankName(name),
      questionCount(0),
      totalScore(0),
      averageScore(0.0)
{
}

QuestionBank::~QuestionBank()
{
}

void QuestionBank::setBankName(const std::string& name)
{
    bankName = name;
}

std::string QuestionBank::getBankName() const
{
    return bankName;
}

int QuestionBank::getQuestionCount() const
{
    return questionCount;
}

int QuestionBank::getTotalScore() const
{
    return totalScore;
}

double QuestionBank::getAverageScore() const
{
    return averageScore;
}

int QuestionBank::findQuestionIndex(int questionId) const
{
    int index;

    for (index = 0; index < questionCount; index++)
    {
        if (questions[index].getQuestionId() == questionId)
        {
            return index;
        }
    }

    return -1;
}

bool QuestionBank::addQuestion(const TriangleQuestion& question)
{
    if (questionCount >= 10)
    {
        return false;
    }

    if (findQuestionIndex(question.getQuestionId()) != -1)
    {
        return false;
    }

    questions[questionCount] = question;
    questionCount++;
    return true;
}

bool QuestionBank::deleteQuestion(int questionId)
{
    int index = findQuestionIndex(questionId);
    int i;

    if (index == -1)
    {
        return false;
    }

    for (i = index; i < questionCount - 1; i++)
    {
        questions[i] = questions[i + 1];
    }

    questionCount--;
    calculateScore();
    return true;
}

bool QuestionBank::answerQuestion(
    int questionId,
    double areaAnswer,
    double perimeterAnswer)
{
    int index = findQuestionIndex(questionId);

    if (index == -1)
    {
        return false;
    }

    questions[index].setUserAnswers(areaAnswer, perimeterAnswer);
    calculateScore();
    return true;
}

void QuestionBank::calculateScore()
{
    int i;
    int answeredQuestionCount = 0;

    totalScore = 0;

    for (i = 0; i < questionCount; i++)
    {
        if (questions[i].hasAnswered())
        {
            answeredQuestionCount++;

            if (questions[i].isAreaAnswerCorrect())
            {
                totalScore++;
            }

            if (questions[i].isPerimeterAnswerCorrect())
            {
                totalScore++;
            }
        }
    }

    if (answeredQuestionCount == 0)
    {
        averageScore = 0.0;
    }
    else
    {
        averageScore = totalScore * 100.0 / (answeredQuestionCount * 2);
    }
}

void QuestionBank::displayAllQuestions() const
{
    int i;

    std::cout << "\n题库名称：" << bankName << std::endl;
    std::cout << "题目数量：" << questionCount << std::endl;

    for (i = 0; i < questionCount; i++)
    {
        questions[i].displayQuestion();
    }
}

void QuestionBank::queryQuestion(int questionId) const
{
    int index = findQuestionIndex(questionId);

    if (index == -1)
    {
        std::cout << "没有找到编号为 " << questionId << " 的题目。" << std::endl;
        return;
    }

    questions[index].displayResult();
}

void QuestionBank::displayScore() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "答对的小问数：" << totalScore << std::endl;
    std::cout << "平均分：" << averageScore << std::endl;
}
