# 实验二 组合关系与依赖关系

本工程依据实验指导书“题目1：题库类组合三角形题目类”完成，并从小学数学练习系统最终成品中反向拆分出实验二阶段应有的功能。

## 文件分工

- `TriangleQuestion.h`、`TriangleQuestion.cpp`：部分类，表示一道三角形面积和周长题。
- `QuestionBank.h`、`QuestionBank.cpp`：整体类，内部使用固定长度对象数组保存题目。
- `main.cpp`：创建对象，完成增加、作答、查询、计分和删除测试。
- `Experiment2_QuestionBank.sln`：Visual Studio 解决方案。

## 类之间的关系

- 组合关系：`QuestionBank` 内部含有 `TriangleQuestion questions[10]`，即题库“包含”题目。
- 依赖关系：`QuestionBank::addQuestion` 的参数是 `const TriangleQuestion&`，即该成员函数“使用”三角形题目对象。

## 仅使用截至实验二的知识

- 类、对象、访问控制、构造函数和析构函数
- 对象数组和基本循环
- 组合关系
- 对象引用参数体现依赖关系
- 基本输入输出、条件判断和函数调用

本实验没有使用继承、多态、虚函数、`vector`、模板、文件流、运算符重载、动态内存或算法库。

## 与指导书步骤的对应关系

1. 选择简单几何图形题库系统中的组合关系题目。
2. 建立 `TriangleQuestion` 和 `QuestionBank` 两个类。
3. 在题库类中用三角形题目对象数组体现组合关系。
4. 用 `addQuestion(const TriangleQuestion&)` 的引用参数体现依赖关系。
5. 创建对象并完成初始化、增加、作答、查询、计分、删除和显示。
