#include "QuestionBank.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "========== 实验三  继承与派生 ==========" << std::endl;
    std::cout << "本次练习包含正方形、长方形、圆形、三角形和梯形。" << std::endl;

    int questionCount;
    std::cout << "请输入练习题数量（1到10）：";
    std::cin >> questionCount;

    if (questionCount < 1 || questionCount > 10)
    {
        std::cout << "输入超出范围，本次自动生成5道题。" << std::endl;
        questionCount = 5;
    }

    QuestionBank bank("小学数学几何图形综合练习题库");
    bank.generateRandomQuestions(questionCount);
    bank.displayAllQuestions();

    for (int i = 1; i <= bank.getQuestionCount(); i++)
    {
        double areaAnswer;
        double perimeterAnswer;

        std::cout << "\n请作答第 " << i << " 题。" << std::endl;
        std::cout << "请输入面积答案（可保留两位小数）：";
        std::cin >> areaAnswer;
        std::cout << "请输入周长答案（可保留两位小数）：";
        std::cin >> perimeterAnswer;
        bank.answerQuestion(i, areaAnswer, perimeterAnswer);
    }

    bank.displayAllResults();
    bank.displayScore();

    return 0;
}
