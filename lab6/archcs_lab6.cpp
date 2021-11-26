// Âàðèàíò 5

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


////////////////////////////////////
// Задание Л6.№1
extern "C" bool task1_asm(int x);

void task1()
{
    cout << "Task 1:" << endl;
    cout << "x = " << 10 << ", (x >= 8) : " << task1_asm(10) << endl;
    cout << "x = " << 8 << ", (x >= 8) : " << task1_asm(8) << endl;
    cout << "x = " << 2 << ", (x >= 8) : " << task1_asm(2) << endl;
    cout << endl;
}
////////////////////////////////////

////////////////////////////////////
// Задание Л6.№2
void task2()
{

    int x = 8;
    int y;
    __asm__ __volatile__
    (
     "movl %[x], %%ecx\n"
     "movl %[y], %%eax\n"
     "cmpl $7,   %%ecx\n"
     "movl $23, %%eax\n"

     "leal 76(%%ecx,%%ecx,4), %%edx \n"
     "cmovlel %%edx, %%eax\n"

     "movl %%eax, %[y]\n"
     :[y]"=m"(y)
     :[x]"g"(x),[Zero]"rm"(0)
     :"eax", "ecx","edx",  "cc"
    );

    cout << "Task 2:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    x = 2;
    __asm__ __volatile__
    (
     "movl %[x], %%ecx\n"
     "movl %[y], %%eax\n"
     "cmpl $7,   %%ecx\n"
     "movl $23, %%eax\n"

     "leal 76(%%ecx,%%ecx,4), %%edx \n"
     "cmovlel %%edx, %%eax\n"

     "movl %%eax, %[y]\n"
     :[y]"=m"(y)
     :[x]"g"(x),[Zero]"rm"(0)
     :"eax", "ecx","edx",  "cc"
    );

    cout << "x = " << x << ", y = " << y << endl;


    cout << endl;

}
////////////////////////////////////

////////////////////////////////////
// Задание Л6.№3
extern "C" double task3_asm(double x);

void task3()
{
    cout << "Task 3:" << endl;
    cout << "x = " << 10.1 << ", y(x) = " << task3_asm(10.1) << endl;
    cout << "x = " << M_PI/2 << ", y(x) = " << task3_asm(M_PI/2) << endl;

    cout << endl;
}
////////////////////////////////////

////////////////////////////////////
// Задание Л6.№4
extern "C" int task4_asm(int N, int x);

void task4()
{
    int N;
    int x;

    cout << "Task 4:" << endl;

    cout << "Input N: ";
    cin >> N;
    cout << "Input x0: ";
    cin >> x;

    cout << task4_asm(N,x);

    cout << endl << endl;
}
////////////////////////////////////

////////////////////////////////////
// Задание Л6.№5
extern "C" void task5_asm(int* M, size_t L);

void task5()
{
    size_t L = 5;
    int M[L];

    task5_asm(M,L);

    cout << "Task 5: " << endl;
    for(int i = 0; i < L;i++)
        cout << setw(5) << M[i];
    cout << endl << endl;
}
////////////////////////////////////

////////////////////////////////////
// Задание Л6.№6
extern "C" double task6_asm(double eps);

void task6()
{
    double eps = pow(10,-6);

    cout << "Task 6:" << endl;
    cout << "Sum = " << task6_asm(eps) << endl;
}
////////////////////////////////////

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();

    return 0;
}

