// Лабораторная работа №1 "Представление данных в ЭВМ"
// Работа выполнена командой #5 группы ПМ-31 Волковым Егором Юрьевичем и Смирновым Михаилом Алексеевичем
// Данный модуль содержит решения всех пяти заданий ЛР1, функции, необходимые для решения каждого задания, выделены комментариями в отдельные озаглавленные блоки

#include <locale.h>
#include <iostream>
#include <iomanip>
#define X  0xA1B2C3D4
#define Y 3
#define Z -8

using namespace std;

/////////////////////////////////////////////////////////////
// Л1.1, вариант 5
void task1()
{
    cout << "Task 1:" << endl;

    cout << "char: " << sizeof(char) << endl;
    cout << "signed char: " << sizeof(signed char) << endl;
    cout << "unsigned char: " << sizeof(unsigned char) << endl;
    cout << "char*: " << sizeof(char*) << endl;
    cout << "wchar_t: " << sizeof(wchar_t) << endl;
    cout << "wchar_t*: " << sizeof(wchar_t*) << endl;
    cout << "short: " << sizeof(short) << endl;
    cout << "short*: " << sizeof(short*) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "int*: " << sizeof(int*) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "long*: " << sizeof(long*) << endl;
    cout << "long long: " << sizeof(long long) << endl;
    cout << "long long*: " << sizeof(long long*) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "float*: " << sizeof(float*) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "double*: " << sizeof(double*) << endl;
    cout << "long double: " << sizeof(long double) << endl;
    cout << "long double*: " << sizeof(long double*) << endl;
    cout << endl;
}
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// Л1.№2, вариант 5
void print16(void * p)
{
    cout<<"16 bit reinterpret"<<endl;

    cout<<"Unsigned Hex:"<<endl;

    cout<<hex<<*(reinterpret_cast<unsigned short *>(p))<<endl;
    cout<<"Signed Hex:"<<endl;
    cout<<hex<< *(reinterpret_cast< short  *>(p))<<endl;
    cout<<"Signed Dec:"<<endl;
      cout<<dec<< *(reinterpret_cast< short  *>(p))<<endl;
      cout<<"Unsigned Dec:"<<endl;
       cout<< *(reinterpret_cast< unsigned short  *>(p))<<endl;
}

void task2()
{
       cout << "Task 2:" << endl;

       unsigned short int max_un= 65535;
       unsigned short int min_un= 0;
       short int max_s= 32767;
       short int min_s= -32767;
       short int y= Y;
       short int z= Z;

       cout<<"max_un="<<max_un<<endl;
       print16(&max_un);
       cout<<"min_un="<<min_un<<endl;
       print16(&min_un);
       cout<<"max_s="<<max_s<<endl;
       print16(&max_s);
       cout<<"min_s="<<min_s<<endl;
       print16(&min_s);
       cout<<"y="<<y<<endl;
       print16(&y);
       cout<<"z="<<z<<endl;
       print16(&z);
       cout << endl;

}
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// Л1.3, вариант 5
void print32(void* p)
{
   cout << hex << setw(15) <<  *(reinterpret_cast<unsigned int *>(p));
   cout << dec << setw(15) << *(reinterpret_cast<unsigned int *>(p));
   cout << hex << setw(15) << *(reinterpret_cast<signed int *>(p));
   cout << dec << setw(15) << *(reinterpret_cast<signed int *>(p));
   cout << dec << setw(15) << *(reinterpret_cast<float *>(p)) << endl;
}

void print64(void* p)
{
   cout << hex << setw(30) << *(reinterpret_cast<unsigned long long *>(p));
   cout << dec << setw(30) << *(reinterpret_cast<unsigned long long *>(p));
   cout << hex << setw(30) << *(reinterpret_cast<signed long long *>(p));
   cout << dec << setw(30) << *(reinterpret_cast<signed long long *>(p));
   cout << dec << setw(30) << *(reinterpret_cast<double *>(p)) << endl;
}

void printBin(long long value, int bit)
{
    for (int i=bit; i>=0; i--)
      if (value & (1<<i)) cout << "1";
      else cout << "0";
    cout << endl;
}

void task3()
{
    cout << "Task 3:" << endl;

    cout << "32:" << endl;

    cout << setw(15) << "  Unsigned hex ";
    cout << setw(15) << "Unsigned dec ";
    cout << setw(15) << "Signed hex ";
    cout << setw(15) << "Signed dec ";
    cout << setw(15) << "Float dec: " << endl;

    unsigned int p1_1 = 0;
    print32(&p1_1);
    p1_1 = 4294967295;
    print32(&p1_1);

    int p2_1 = -2147483647;
    print32(&p2_1);
    p2_1 = 2147483647;
    print32(&p2_1);
    p2_1 = X;
    print32(&p2_1);
    p2_1 = Y;
    print32(&p2_1);
    p2_1 = Z;
    print32(&p2_1);

    float p3_1 = X;
    print32(&p3_1);
    p3_1 = Y;
    print32(&p3_1);
    p3_1 = Z;
    print32(&p3_1);
    cout << endl;

    cout << "64:" << endl;

    cout << setw(30) << "Unsigned hex ";
    cout << setw(30) << "Unsigned dec ";
    cout << setw(30) << "Signed hex ";
    cout << setw(30) << "Signed dec ";
    cout << setw(30) << "Float dec: " << endl;

    unsigned long long p1_2 = 0;
    print64(&p1_2);
    p1_2 = 18446744073709551615;
    print64(&p1_2);

    long long p2_2 = -9223372036854775807;
    print64(&p2_2);
    p2_2 = 9223372036854775807;
    print64(&p2_2);
    p2_2 = X;
    print64(&p2_2);
    p2_2 = Y;
    print64(&p2_2);
    p2_2 = Z;
    print64(&p2_2);

    double p3_2 = X;
    print64(&p3_2);
    p3_2 = Y;
    print64(&p3_2);
    p3_2 = Z;
    print64(&p3_2);

    cout << endl << "Explanation of why 'nan' is displayed: " << endl;
    printBin(p1_2,64);
    p2_2 = 9223372036854775807;
    printBin(p2_2,64);
    p2_2 = Z;
    printBin(p2_2,64);
    cout << endl;
}
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// Л1.4, вариант 5
void task4()
{
    cout << "Task 4:" << endl;
    short y = Y, z = Z;

    unsigned int z1=static_cast<unsigned int>(z);
    int z2=static_cast<int>(z);

    cout<<"Original z= "<<z<<endl;
    print16(&z);
    cout<<"Unsigned z= "<<z1<<endl;
    print32(&z1);
    cout<<"Signed z= "<<z2<<endl;
    print32(&z2);

    unsigned int y1=static_cast<unsigned int>(y);
    int y2=static_cast<int>(y);

    cout<<"Original y= "<<y<<endl;
    print16(&y);
    cout<<"Unsigned y= "<<y1<<endl;
    print32(&y1);
    cout<<"Signed y= "<<y2<<endl;
    print32(&y2);
    cout << endl;

}

/////////////////////////////////////////////////////////////
// Л1.5, вариант 5
void printDump(void* p, size_t N)
{
    const unsigned char * p0 = reinterpret_cast<const unsigned char *>( p );

    for (int i = 0; i < N; i++ )
    {
         cout << setw(2) << hex << (signed short)(*(p0+i)) << " ";
    }
    cout << endl;
}

void task5()
{
    cout << "Task 5:" << endl;

    int p1 = X;
    printDump(&p1,4);
    int p2[3] = {static_cast<int>(X),Y,Z};
    printDump(&p2,12);
    double p3 = Y;
    printDump(&p3,8);
    char* p4 = "bcdxy";
    printDump(p4,6);
    char* p5 = "ёжзий";
    printDump(p5,12);
    wchar_t* p6 = L"bcdxy";
    printDump(p6,12);
    wchar_t* p7 = L"ёжзий";
    printDump(p7,12);
}

int main()
{

    task1();
    task2();
    task3();
    task4();
    task5();

    return 0;
}
