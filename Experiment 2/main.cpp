#include "QuestionBank.h"
#include "TriangleQuestion.h"

#include <iostream>
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "========== 实验二  组合关系与依赖关系 =========="
        << std::endl;



    // 步骤一：分别创建三角形题目对象。
    TriangleQuestion question1(1, 3.0, 4.0, 5.0);
    TriangleQuestion question2(2, 5.0, 5.0, 6.0);
    TriangleQuestion question3(3, 6.0, 8.0, 10.0);

    // 步骤二：创建题库对象，并通过引用参数增加题目。
    QuestionBank bank("小学数学三角形练习题库");
    bank.addQuestion(question1);
    bank.addQuestion(question2);
    bank.addQuestion(question3);

    std::cout << "\n1. 显示题库中的全部题目" << std::endl;
    bank.displayAllQuestions();

    // 步骤三：输入答案，由题库对象找到相应题目并记录答案。
    double areaAnswer;
    double perimeterAnswer;
    int questionId;

    std::cout << "\n2. 依次完成三道题" << std::endl;
    for (questionId = 1; questionId <= 3; questionId++)
    {
        bank.queryQuestion(questionId);
        std::cout << "请输入题目" << questionId << "的面积答案：";
        std::cin >> areaAnswer;
        std::cout << "请输入题目" << questionId << "的周长答案：";
        std::cin >> perimeterAnswer;
        bank.answerQuestion(questionId, areaAnswer, perimeterAnswer);
    }

    // 步骤四：查询题目并显示成绩。
    std::cout << "\n3. 查询编号为2的题目" << std::endl;
    bank.queryQuestion(2);

    std::cout << "\n4. 显示本次练习成绩" << std::endl;
    bank.displayScore();

    // 步骤五：删除题目，验证题库数量发生变化。
    std::cout << "\n5. 删除编号为2的题目" << std::endl;
    if (bank.deleteQuestion(2))
    {
        std::cout << "删除成功。" << std::endl;
    }
    bank.displayAllQuestions();

    return 0;
}
