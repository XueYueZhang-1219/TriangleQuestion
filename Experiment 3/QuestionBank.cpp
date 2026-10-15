#include "QuestionBank.h"

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

QuestionBank::QuestionBank()
    : bankName("小学数学几何图形题库"),
      squareCount(0),
      rectangleCount(0),
      circleCount(0),
      triangleCount(0),
      trapezoidCount(0),
      questionCount(0)
{
}

QuestionBank::QuestionBank(const std::string& name)
    : bankName(name),
      squareCount(0),
      rectangleCount(0),
      circleCount(0),
      triangleCount(0),
      trapezoidCount(0),
      questionCount(0)
{
}

QuestionBank::~QuestionBank()
{
}

int QuestionBank::getQuestionCount() const
{
    return questionCount;
}

void QuestionBank::generateRandomQuestions(int count)
{
    if (count < 1)
    {
        count = 1;
    }
    if (count > MAX_QUESTIONS)
    {
        count = MAX_QUESTIONS;
    }

    squareCount = 0;
    rectangleCount = 0;
    circleCount = 0;
    triangleCount = 0;
    trapezoidCount = 0;
    questionCount = count;

    for (int i = 0; i < questionCount; i++)
    {
        const int questionId = i + 1;
        const int type = std::rand() % 5 + 1;
        questionTypes[i] = type;

        if (type == 1)
        {
            const double side = std::rand() % 9 + 2;
            questionPositions[i] = squareCount;
            squareQuestions[squareCount].setQuestion(questionId, side);
            squareCount++;
        }
        else if (type == 2)
        {
            const double length = std::rand() % 9 + 2;
            const double width = std::rand() % 9 + 2;
            questionPositions[i] = rectangleCount;
            rectangleQuestions[rectangleCount].setQuestion(questionId, length, width);
            rectangleCount++;
        }
        else if (type == 3)
        {
            const double radius = std::rand() % 10 + 1;
            questionPositions[i] = circleCount;
            circleQuestions[circleCount].setQuestion(questionId, radius);
            circleCount++;
        }
        else if (type == 4)
        {
            const double sideA = std::rand() % 8 + 3;
            const double sideB = std::rand() % 8 + 3;
            const double sideC = std::sqrt(sideA * sideA + sideB * sideB);
            questionPositions[i] = triangleCount;
            triangleQuestions[triangleCount].setQuestion(
                questionId,
                sideA,
                sideB,
                sideC);
            triangleCount++;
        }
        else
        {
            const double top = std::rand() % 5 + 2;
            const double bottom = top + std::rand() % 5 + 2;
            const double height = std::rand() % 7 + 2;
            const double halfDifference = (bottom - top) / 2.0;
            const double leg = std::sqrt(
                halfDifference * halfDifference + height * height);

            questionPositions[i] = trapezoidCount;
            trapezoidQuestions[trapezoidCount].setQuestion(
                questionId,
                top,
                bottom,
                height,
                leg,
                leg);
            trapezoidCount++;
        }
    }
}

void QuestionBank::displayQuestionAt(int index) const
{
    const int type = questionTypes[index];
    const int position = questionPositions[index];

    if (type == 1)
    {
        squareQuestions[position].displayQuestion();
    }
    else if (type == 2)
    {
        rectangleQuestions[position].displayQuestion();
    }
    else if (type == 3)
    {
        circleQuestions[position].displayQuestion();
    }
    else if (type == 4)
    {
        triangleQuestions[position].displayQuestion();
    }
    else
    {
        trapezoidQuestions[position].displayQuestion();
    }
}

void QuestionBank::displayResultAt(int index) const
{
    const int type = questionTypes[index];
    const int position = questionPositions[index];

    displayQuestionAt(index);

    if (type == 1)
    {
        squareQuestions[position].displayAnswerResult();
    }
    else if (type == 2)
    {
        rectangleQuestions[position].displayAnswerResult();
    }
    else if (type == 3)
    {
        circleQuestions[position].displayAnswerResult();
    }
    else if (type == 4)
    {
        triangleQuestions[position].displayAnswerResult();
    }
    else
    {
        trapezoidQuestions[position].displayAnswerResult();
    }
}

int QuestionBank::getCorrectPartCountAt(int index) const
{
    const int type = questionTypes[index];
    const int position = questionPositions[index];
    int correctCount = 0;

    if (type == 1)
    {
        correctCount += squareQuestions[position].isAreaAnswerCorrect() ? 1 : 0;
        correctCount += squareQuestions[position].isPerimeterAnswerCorrect() ? 1 : 0;
    }
    else if (type == 2)
    {
        correctCount += rectangleQuestions[position].isAreaAnswerCorrect() ? 1 : 0;
        correctCount += rectangleQuestions[position].isPerimeterAnswerCorrect() ? 1 : 0;
    }
    else if (type == 3)
    {
        correctCount += circleQuestions[position].isAreaAnswerCorrect() ? 1 : 0;
        correctCount += circleQuestions[position].isPerimeterAnswerCorrect() ? 1 : 0;
    }
    else if (type == 4)
    {
        correctCount += triangleQuestions[position].isAreaAnswerCorrect() ? 1 : 0;
        correctCount += triangleQuestions[position].isPerimeterAnswerCorrect() ? 1 : 0;
    }
    else
    {
        correctCount += trapezoidQuestions[position].isAreaAnswerCorrect() ? 1 : 0;
        correctCount += trapezoidQuestions[position].isPerimeterAnswerCorrect() ? 1 : 0;
    }

    return correctCount;
}

void QuestionBank::displayAllQuestions() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n题库名称：" << bankName << std::endl;
    std::cout << "本次共有 " << questionCount << " 道题。" << std::endl;

    for (int i = 0; i < questionCount; i++)
    {
        displayQuestionAt(i);
    }
}

bool QuestionBank::answerQuestion(
    int questionNumber,
    double areaAnswer,
    double perimeterAnswer)
{
    const int index = questionNumber - 1;
    if (index < 0 || index >= questionCount)
    {
        return false;
    }

    const int type = questionTypes[index];
    const int position = questionPositions[index];

    if (type == 1)
    {
        squareQuestions[position].setUserAnswers(areaAnswer, perimeterAnswer);
    }
    else if (type == 2)
    {
        rectangleQuestions[position].setUserAnswers(areaAnswer, perimeterAnswer);
    }
    else if (type == 3)
    {
        circleQuestions[position].setUserAnswers(areaAnswer, perimeterAnswer);
    }
    else if (type == 4)
    {
        triangleQuestions[position].setUserAnswers(areaAnswer, perimeterAnswer);
    }
    else
    {
        trapezoidQuestions[position].setUserAnswers(areaAnswer, perimeterAnswer);
    }

    return true;
}

void QuestionBank::displayAllResults() const
{
    std::cout << "\n========== 答题回看 ==========" << std::endl;
    for (int i = 0; i < questionCount; i++)
    {
        displayResultAt(i);
        std::cout << std::endl;
    }
}

void QuestionBank::displayScore() const
{
    int correctPartCount = 0;

    for (int i = 0; i < questionCount; i++)
    {
        correctPartCount += getCorrectPartCountAt(i);
    }

    const int allPartCount = questionCount * 2;
    double score = 0.0;
    if (allPartCount > 0)
    {
        score = correctPartCount * 100.0 / allPartCount;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "========== 本次成绩 ==========" << std::endl;
    std::cout << "答对小问数：" << correctPartCount << " / " << allPartCount << std::endl;
    std::cout << "本次得分：" << score << " 分" << std::endl;
}
