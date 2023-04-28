
制作一个公司职员管理系统,主要实现以下功能:
• 1、记录公司所有成员的信息,公司成员主要信息主要包括 姓名、职位、当月工资和级别 。
公司职位有: 总经理、技术经理、技术人员、销售经理和销售人员 。 
其中,经理固定月薪 20000 元,技术经理固定月薪 12000 元,技术人员固定月薪 10000 元,销售经理固定月薪 10000 元,销售人员固定月薪 8000 元。经理每月提成为公司当月销售额的 10%,技术部⻔为 5%,销售部⻔为 1%, 公司销售额作为用户输入的一个变量;

• 2、只要用户不关闭程序,程序可以一直运行并且保存公司成员的信息。重启程序后,程序可加载出公司成员的信息,即程序要保证用户信息不丢失;
• 3、程序对所有人员规定级别
￼

>总经理为 4 级,技术经理和销售经理为 3 级,技术人员为 2 级,销售人员为 1 级。技术人员仅可升级为技术经理,销售人员仅可升级为销售经理,销售经理与技术经理均可升级为总经理;
• 4、程序需要提供添加新成员、删除新成员、已有成员调换岗位等功能;
• 5、程序需要提供显示当前公司所有成员的功能,要求按照成员级别由高到低对成员进行排序并打印到终端;
# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (project)

# 指定生成目标
add_executable(Demo main.cpp people.cpp)



• 6、需要在 Linux 环境下编写该程序,


$

     整体工程以 CMake 结构呈现。  



