#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
//////////////////////////////////
// Задание Л5.№1
void task1()
{
    cout << "Task 1: " << endl;

    cout << "Float:" << endl;

    float Sd_f [3];
    float Sa_f [3];

    int n[3] = {static_cast<int>(pow(10,3)), static_cast<int>(pow(10,6)), static_cast<int>(pow(10,9))};

    for(int k = 0; k < 3; k++)
    {
        for(int i = 1; i <= n[k]; i++)
            Sd_f[k] += static_cast<float>(1)/i;
        for(int i = n[k]; i > 0; i--)
            Sa_f[k] += static_cast<float>(1)/i;
        cout << "n = " << n[k] << " : Sd = " << Sd_f[k] << ", Sa = " << Sa_f[k] << endl;
    }

    cout << "Double:" << endl;

    double Sd_d [3];
    double Sa_d [3];

    for(int k = 0; k < 3; k++)
    {
        for(int i = 1; i <= n[k]; i++)
            Sd_d[k] += static_cast<double>(1)/i;
        for(int i = n[k]; i > 0; i--)
            Sa_d[k] += static_cast<double>(1)/i;
        cout << "n = " << n[k] << " : Sd = " << Sd_d[k] << ", Sa = " << Sa_d[k] << endl;
    }

    cout << endl;
}
//////////////////////////////////

//////////////////////////////////
// Задание Л5.№2
double term2(unsigned long long int i)
{
    return pow(-1,i)*(3.0/(i+3));
}

double two_sum(double& t, double a, double b)
{
    double s = a+b; // сумма чисел a и b

    // вычисление погрешности нахождения суммы
    double bs = s-a;
    double as = s-bs;
    t = (b-bs)+(a-as);

    return s;
}

void task2()
{
    double eps = pow(10,-6);

    double sum1 = 0; // текущее значение суммы для первого алгоритма
    double t = 0; // текущее значение погрешности найденной суммы
    double t_i; // погрешность на i-ой итерации
    double sum2 = 0; // текущее значение суммы для второго алгоритма

    // Rump–Ogita–Oishi algorithm
    for(int i = 0; abs(term2(i+1)) > eps; i++)
    {
        sum1 = two_sum(t_i,sum1,term2(i));
        t += t_i;
    }

    // Наивный алгоритм суммирования для сравнения
    for(int i = 0; abs(term2(i+1)-term2(i)) > eps; i++)
        sum2 += term2(i);

    cout << "Task 2:" << endl;
    cout << "Rump-Ogita-Oishi algorithm: sum = " << sum1+t << ", eps = " << eps << endl;
    cout << "Naive algorithm: sum = " << sum2 << ", eps = " << eps << endl;
    cout << "Difference: " << sum1+t-sum2 << endl;
    cout << endl;
}
//////////////////////////////////

//////////////////////////////////
// Задание Л5.№3
double term3(unsigned long long int i, double alpha)
{
    return 1.0/pow(i,alpha);
}

void task3()
{
    double eps = pow(10,-6);
    double alpha = 2; // рассматриваемые значения alpha > 1 - рассматриваются только сходящиеся ряды

    double sum1 = 0; // текущее значение суммы для первого алгоритма
    double a_i = term3(1,alpha);
    double t = 0; // текущее значение погрешности найденной суммы
    double t_i; // погрешность на i-ой итерации
    double sum2 = 0; // текущее значение суммы для второго алгоритма

    // Rump–Ogita–Oishi algorithm
    for(int i = 1; a_i + term3(i+1,alpha-1)/(alpha-1) > eps; i++)
    {
        sum1 = two_sum(t_i,sum1,term3(i,alpha));
        t += t_i;
        a_i = term3(i+1,alpha);
    }

    a_i = term3(1,alpha);
    // Наивный алгоритм суммирования для сравнения
    for(int i = 1; a_i + term3(i+1,alpha-1)/(alpha-1) > eps; i++)
    {
        sum2 += term3(i,alpha);
        a_i = term3(i+1,alpha);
    }

    cout << "Task 3:" << endl;
    cout << "Rump-Ogita-Oishi algorithm: sum = " << sum1+t << ", eps = " << eps << endl;
    cout << "Naive algorithm: sum = " << sum2 << ", eps = " << eps << endl;
    cout << "Difference: " << sum1+t-sum2 << endl;
    cout << endl;
}
//////////////////////////////////

//////////////////////////////////
// Задание Л5.№4
extern "C" double task4_asm_fpu(double x);

void task4()
{
    double x = 4.25;
    double y = task4_asm_fpu(x);

    cout << "Task 4:" << endl;
    cout << "Assembler: x = " << x << ", y = " << y << endl;
    cout << "CPP: x = " << x << ", y = " << (pow(2,x)-1)*(2+2*x) << endl;
    cout << endl;
}
//////////////////////////////////

//////////////////////////////////
// Задание Л5.№5
void task5()
{
    double x[4] = {1.1, 2.2, 3.3, 4.4};
    double y[4] = {10.5, 11.6, 12.7, 13.8};

    cout << "Task 5: " << endl;
    cout << "x: ";
    for(int i = 0; i < 4; i++)
        cout << setw(5) << x[i];
    cout << endl;
    cout << "y: ";
    for(int i = 0; i < 4; i++)
        cout << setw(5) << y[i];
    cout << endl;

    double z[4]{0};

    asm(
    "vmovapd (%0), %%ymm0\n"
    "vmovapd (%1), %%ymm1\n"
    "vmovapd (%2), %%ymm2\n"
    "vaddpd %%ymm0, %%ymm1, %%ymm3\n"
    "vsubpd %%ymm1, %%ymm0, %%ymm4\n"
    "vmulpd %%ymm3, %%ymm4, %%ymm2\n"
    "vmovapd %%ymm2, (%2)\n"
    :: "r"(x), "r"(y),"r"(z)
    : "%ymm0", "%ymm1", "%ymm2", "%ymm3", "%ymm4"
    );

    cout << "z: ";
    for(int i = 0; i < 4; i++)
        cout << setw(5) << z[i] << " ";
    cout << endl << endl;
}
//////////////////////////////////

//////////////////////////////////
// Задание Л5.№6
extern "C" double task6_cpp(double x, double y);
double task6_cpp(double x, double y)
{
    return 4.6*pow(x,y)-1.3;
}
//////////////////////////////////

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();

    return 0;
}
