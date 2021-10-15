// Лабораторная работа №3 "Использование ассемблерных вставок в программах на C++"
// Работа выполнена командой #5 группы ПМ-31 Волковым Егором Юрьевичем и Смирновым Михаилом Алексеевичем
// Данный модуль содержит решения всех пяти заданий ЛР3, функции, необходимые для решения каждого задания, выделены комментариями в отдельные озаглавленные блоки


#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////
// Л3.1, вариант 5
void task1()
{

    unsigned int z;
    unsigned int w;

    unsigned int x = 1000;
    unsigned int y = 233;

    __asm__ __volatile__
    (
     "movq %[x], %%rax\n"
     "movq %[y], %%rcx\n"
     "subq $134, %%rcx\n"
     "movl $0,   %%edx\n"
     "idivl %%ecx\n"
     "movl %%eax, %[z]\n"
     "movl %%edx, %[w]\n"
     :[z]"=m"(z), [w]"=m"(w)
     :[x]"g"(x), [y]"g"(y)
     :"%rax", "%rcx", "%edx", "cc"
    );

    cout << "Task 1:" << endl;
    cout << "ASM:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "z = x/(y-134) = " << z << endl;
    cout << "w = x%(y-134) = " << w << endl;
    cout << "C++:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "z = x/(y-134) = " << x/(y-134) << endl;
    cout << "w = x%(y-134) = " << x%(y-134) << endl;
    cout << endl;

}
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// Л3.2, вариант 5
void task2()
{

    unsigned int z;
    unsigned int w;

    unsigned int x = 940;
    unsigned int y = 599;

    __asm__ __volatile__
    (
    "movq (%[p]), %%rax\n"
    "movq (%[q]), %%rcx\n"
    "subq $134, %%rcx\n"
    "movl $0, %%edx\n"
    "idivl %%ecx\n"
    "movl %%eax, %[z]\n"
    "movl %%edx, %[w]\n"
    :[z]"=m"(z), [w]"=m"(w)
    :[p]"g"(&x), [q]"g"(&y)
    :"%rax", "%rcx", "%edx", "cc"
    );

    cout << "Task 2:" << endl;
    cout << "ASM:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "z = x/(y-134) = " << z << endl;
    cout << "w = x%(y-134) = " << w << endl;
    cout << "C++:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "z = x/(y-134) = " << x/(y-134) << endl;
    cout << "w = x%(y-134) = " << x%(y-134) << endl;
    cout <<endl;

}
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// Л3.3, вариант 5
void task3()
{

    unsigned int z;
    unsigned int w;

    unsigned int x = 1005;
    unsigned int y = 237;

    __asm__ __volatile__
    (
     "subl $134, %[y]\n"
     "movl $0,   %%edx\n"
     "idivl %[y]\n"
     :[z]"=a"(z), [w]"=d"(w)
     :"A"(x), [y]"c"(y)
     :"cc"
    );

    cout << "Task 3: " << endl;
    cout << "ASM:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "z = x/(y-134) = " << z << endl;
    cout << "w = x%(y-134) = " << w << endl;
    cout << "C++:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "z = x/(y-134) = " << x/(y-134) << endl;
    cout << "w = x%(y-134) = " << x%(y-134) << endl;
    cout << endl;
}
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// Л3.4, вариант 5
void task4()
{
    int M[10]{0};

    int k = 1;
    int x = 10;

    cout << "Task 4: " << endl;
    cout << "k = " << k << ", x = " << x << endl;
    cout << "M: ";
    for(int i = 0; i < 10; i++)
        cout << M[i] << " ";
    cout << endl;

    __asm__ __volatile__
    (
    "movq %%rax, (%%rbx,%%rsi,4)\n"
    :
    :"a"(x),"S"(k),"b"(M)
    :"cc"
    );

    cout << "M: ";
    for(int i = 0; i < 10; i++)
        cout << M[i] << " ";
    cout << endl;

    cout << endl;
}
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// Л3.5, вариант 5
void task5()
{
    int M[10]{0};

    int j = 3;

    cout << "Task 5: " << endl;
    cout << "j = " << j << endl;
    cout << "M: ";
    for(int i = 0; i < 10; i++)
        cout << M[i] << " ";
    cout << endl;

    asm
    (
     "movq $0xFF, 1(%%rbx,%%rsi,4)\n"
     :
     : "b"(M), "S"(j)
     : "cc"
    );
   cout << "M: ";
   for(int i = 0; i < 10; i++)
        cout << hex << M[i] << " ";
    cout << endl;

    cout << endl;
}
/////////////////////////////////////////////////////////////

int main()
{

    task1();
    task2();
    task3();
    task4();
    task5();

    return 0;

}



