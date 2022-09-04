#include<iostream>
#ifndef DEBUG_NEW_H_
#define DEBUG_NEW_H_
#define new new(__FILE__,__LINE__)
#endif //