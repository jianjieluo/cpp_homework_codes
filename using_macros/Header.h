#ifndef HEADER_H_
#define HEADER_H_
#include <cmath>
#include <string>
#include <iostream>

#define MAX 100
#define MIN -100
#define max(a, b) ((a > b) ? a : b)
#define square(a) ((a) * (a))
#define e(a, b) (a * pow(10, b))
#define mstr(a) str(a)  // #a 注意两者的区别
#define str(a) #a
#define WARN_IF(a) if (a) std::cout << "Warning: " << #a << std::endl;
#endif

/*
 * 1、关于符号#和##

两个符号都只能用于预处理宏扩展。不能在普通的源码中使用它们，只能在宏定义中使用。

简单的说，#是把宏参数变为一个字符串，##是把两个宏参数连接在一起。

2）断行链接/

*/
