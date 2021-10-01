// Лабораторная работа №2A "Ввод-вывод при помощи libc"
// Работа выполнена командой #5 группы ПМ-31 Волковым Егором Юрьевичем и Смирновым Михаилом Алексеевичем
// Данный модуль содержит решения всех пяти заданий ЛР2А, функции, необходимые для решения каждого задания, выделены комментариями в отдельные озаглавленные блоки

#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES
#define N 5

using namespace std;

/////////////////////////////////////////
//Блок функций, выводящих содержимое массивов на экран
template <class T>
void print(T M[N], int wide)
{
    for(int i = 0; i < N; i++)
        printf("%*X ",wide,M[i]);
    printf("\n");
}

void print(unsigned long long M[N], int wide)
{
    for(int i = 0; i < N; i++)
        printf("%*llX ",wide,M[i]);
    printf("\n");
}

void print(float M[N], int wide)
{
    for(int i = 0; i < N; i++)
        printf("%*.22f ",wide,M[i]);
    printf("\n");
}

void print(double M[N], int wide)
{
    for(int i = 0; i < N; i++)
        printf("%*.48lf ",wide,M[i]);
    printf("\n");
}
/////////////////////////////////////////

/////////////////////////////////////////
// Задание Л2А.1 Вариант 5
void task1(unsigned char Mb[N],unsigned short Ms[N],unsigned int Ml[N],unsigned long long Mq[N],float Mfs[N],double Mfl[N])
{
    print(Mb,2*sizeof(char));
    print(Ms,2*sizeof(short));
    print(Ml,2*sizeof(int));
    print(Mq,2*sizeof(long long));
    puts("\n");
    print(Mfs,1);
    print(Mfl,1);
    puts("\n\n");
}
/////////////////////////////////////////

/////////////////////////////////////////
// функции изменения i-го элемента массива
template<class T>
void change_arr(T A[],long long int i)
{
    printf("Enter new value: ");

    long long int new_number;

    while(scanf("%lld",&new_number)!=1)
    {
       const char *s="Error\n";
       puts(s);
       printf("Enter new value:");
       while(getchar() != '\n' );
    }
    getchar();
    A[i] = new_number;
}

void change_arr(float A[],long long int i)
{
    printf("Enter new value: ");

    float new_number;

    while(scanf("%f",&new_number)!=1)
    {
       const char *s="Error\n";
       puts(s);
       printf("Enter new value:");
       while(getchar() != '\n' );
    }
    getchar();
    A[i] = new_number;
}

void change_arr(double A[],long long int i)
{
    printf("Enter new value: ");

    double new_number;

    while(scanf("%lf",&new_number)!=1)
    {
       const char *s="Error\n";
       puts(s);
       printf("Enter new value:");
       while(getchar() != '\n' );
    }
    getchar();
    A[i] = new_number;
}
/////////////////////////////////////////

/////////////////////////////////////////
// Задание Л2А.2 Вариант 5
void task2(unsigned char Mb[N],unsigned short Ms[N],unsigned int Ml[N],unsigned long long Mq[N],float Mfs[N],double Mfl[N])
{
    change_arr(Mb,2);
    change_arr(Ms,2);
    change_arr(Ml,2);
    change_arr(Mq,2);
    change_arr(Mfs,2);
    change_arr(Mfl,2);

    task1(Mb,Ms,Ml,Mq,Mfs,Mfl);
}
/////////////////////////////////////////

/////////////////////////////////////////
// Задание Л2А.3 Вариант 5
void change_whole_arr(double Mfl[N])
{
    double new_number;
    printf("Input new number: ");
    while(!scanf("%lf",&new_number))
    {
        puts("Uncorrect input. Please, try again: ");
        while (getchar() != '\n');
    }
    getchar();
    puts("\n");

    for(int i = 0; i < N; i++)
        Mfl[i] = new_number;
}

void task3(unsigned char Mb[N],unsigned short Ms[N],unsigned int Ml[N],unsigned long long Mq[N],float Mfs[N],double Mfl[N])
{
    change_whole_arr(Mfl);

    task1(Mb,Ms,Ml,Mq,Mfs,Mfl);
}
/////////////////////////////////////////


/////////////////////////////////////////
// Задание Л2А.4 Вариант 5
void task4()
{
    char s1[10];
    char s2[10];
    char s3[10];

    printf("Enter string s2:\n");
    scanf("%[^\n]%*c", s2);
    printf("***%s***\n", s2);
    printf("Enter string s1:\n");
    scanf("%s", s1);
    printf("***%s***\n", s1);
    printf("Enter string s3:\n");
    scanf("%10s", s3);
    printf("***%s***\n", s3);

}
/////////////////////////////////////////

/////////////////////////////////////////
// Задание Л2А.5 Вариант 5
void task5(unsigned char Mb[N],unsigned short Ms[N],unsigned int Ml[N],unsigned long long Mq[N],float Mfs[N],double Mfl[N])
{
    int k = 30;
    print(Mb,k);
    print(Ms,k);
    print(Ml,k);
    print(Mq,k);
    puts("\n");
    print(Mfs,k);
    print(Mfl,k);
    puts("\n");
}

int main()
{
    // создание массивов
    unsigned char Mb[N]{0xED};
    unsigned short Ms[N]{0xC0DE};
    unsigned int Ml[N]{0xDEADBEEF};
    unsigned long long Mq[N]{0xBECACA01FFEDC0CA};
    float Mfs[N]{M_PI};
    double Mfl[N]{M_PI};

    // инициализация массивов
    for(int i = 1; i < N; i++)
    {
        Mb[i] = Mb[0];
        Ms[i] = Ms[0];
        Ml[i] = Ml[0];
        Mq[i] = Mq[0];
        Mfs[i] = Mfs[0];
        Mfl[i] = Mfl[0];
    }

    // выполнение заданий 1-5
    puts("Task 1:\n");
    task1(Mb,Ms,Ml,Mq,Mfs,Mfl);

    puts("Task 2:\n");
    task2(Mb,Ms,Ml,Mq,Mfs,Mfl);

    puts("Task 3:\n");
    task3(Mb,Ms,Ml,Mq,Mfs,Mfl);

    puts("Task 4:\n");
    task4();

    printf("Task 5:\n");
    task5(Mb,Ms,Ml,Mq,Mfs,Mfl);

    return 0;
}
