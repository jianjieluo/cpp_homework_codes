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
#define mstr(a) str(a)  // #a ע�����ߵ�����
#define str(a) #a
#define WARN_IF(a) if (a) std::cout << "Warning: " << #a << std::endl;
#endif

/*
 * 1�����ڷ���#��##

�������Ŷ�ֻ������Ԥ�������չ����������ͨ��Դ����ʹ�����ǣ�ֻ���ں궨����ʹ�á�

�򵥵�˵��#�ǰѺ������Ϊһ���ַ�����##�ǰ����������������һ��

2����������/

*/
