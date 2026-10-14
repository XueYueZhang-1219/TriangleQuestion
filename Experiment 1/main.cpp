#include "TriangleQuestion.h"

#include <iostream>

int main()
{
    std::cout << "========== 实验一  三角形题目类 ==========" << std::endl;

    // 步骤一：使用默认构造函数生成对象。
    TriangleQuestion defaultQuestion;
    std::cout << "\n1. 默认构造的题目" << std::endl;
    defaultQuestion.displayQuestion();
    defaultQuestion.displayInformation();

    // 步骤二：使用重载构造函数生成对象。
    TriangleQuestion givenQuestion(5.0, 5.0, 6.0);
    std::cout << "\n2. 使用三个参数构造的题目" << std::endl;
    givenQuestion.displayQuestion();
    givenQuestion.displayInformation();

    // 步骤三：通过公有成员函数修改和获取私有数据。
    std::cout << "\n3. 修改三条边" << std::endl;
    if (givenQuestion.setSides(6.0, 8.0, 10.0))
    {
        std::cout << "修改成功。" << std::endl;
    }
    givenQuestion.displayInformation();

    std::cout << "边A的当前值：" << givenQuestion.getSideA() << std::endl;

    // 步骤四：验证不合法数据不会破坏对象原有状态。
    std::cout << "\n4. 尝试设置不能构成三角形的三条边 1、2、5" << std::endl;
    if (!givenQuestion.setSides(1.0, 2.0, 5.0))
    {
        std::cout << "设置失败：三条边不合法，对象仍保留原来的数据。" << std::endl;
    }
    givenQuestion.displayInformation();

    return 0;
}
