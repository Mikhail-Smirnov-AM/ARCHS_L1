// Задания Л4.№1, Л4.№3 Вариант № 5. Код вызывающей функции для задания Л4.№1 и вызываемой функции для задания Л4.№3.

#include <iostream>
using namespace std;

    extern "C" int task1_asm(int x, int y);

void task1()
{
    int x = 10, y = 20;
    int z = task1_asm(x,y);

    cout << "Task 1:" << endl;
    cout << "Assembler result: " << z << endl;
    cout << "C++ result: " << 657+5*x+2*y << endl;
    cout << endl;
}

extern "C" int task3_cpp(int x1, int x2, int x3, int x4, int x5);
int task3_cpp(int x1, int x2, int x3, int x4, int x5)
{
    printf("x1 = %d, x2 = %d, x3 = %d, x4 = %d\n", x1,x2,x3,x4);
    return x5;
}

int main()
{
    task1();
    return 0;
}
