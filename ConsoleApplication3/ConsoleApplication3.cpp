// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <string>

using namespace std;

class MyExcept1 {};

class MyExcept2 {
    string msg;
public:
    MyExcept2(const string& s) : msg(s) {}
    const char* message() const { return msg.c_str(); }
};

class MyExcept3 : public invalid_argument {
    double num;
public:
    MyExcept3(const string msg, double n) : invalid_argument(msg), num(n) {}
    double arg() const { return num; }
};
void root1(double a, double b) {
    
    double c, l, x, y, z;
    c = pow(pow(a, 2) + pow(b, 2), 1 / 2);
    l = asin(c / a);
    x = l * (180 / 3.14159);
    y = 90;
    z = 180 - (y + x);

    cout << "Углы равны: " << y << " | " << x << " | " << z << endl;
    
}

void root2(double a, double b) throw() {
    double c, l, x, y, z;
    c = pow(pow(a, 2) + pow(b, 2), 1 / 2);
    l = asin(c / a);
    x = l * (180 / 3.14159);
    y = 90;
    z = 180 - (y + x);

    cout << "Углы равны: " << y << " | " << x << " | " << z << endl;
   
}

void root3(double a, double b) throw(invalid_argument) {
    if (a == 0 or b == 0)
        throw invalid_argument("Один из катетов = 0");
    
    double c, l, x, y, z;
    c = pow(pow(a, 2) + pow(b, 2), 1 / 2);
    l = asin(c / a);
    x = l * (180 / 3.14159);
    y = 90;
    z = 180 - (y + x);

    cout << "Углы равны: " << y << " | " << x << " | " << z << endl;
}

void root4_1(double a, double b) throw(MyExcept1) {
    if (a == 0 or b == 0)
        throw MyExcept1();
   
    double c, l, x, y, z;
    c = pow(pow(a, 2) + pow(b, 2), 1 / 2);
    l = asin(c / a);
    x = l * (180 / 3.14159);
    y = 90;
    z = 180 - (y + x);

    cout << "Углы равны: " << y << " | " << x << " | " << z << endl;
}

void root4_2(double a, double b) throw(MyExcept2) {
    if (a == 0 or b == 0)
        throw MyExcept2("Один из катетов = 0");
   
    double c, l, x, y, z;
    c = pow(pow(a, 2) + pow(b, 2), 1 / 2);
    l = asin(c / a);
    x = l * (180 / 3.14159);
    y = 90;
    z = 180 - (y + x);

    cout << "Углы равны: " << y << " | " << x << " | " << z << endl;
}

void root4_3(double a, double b) throw(MyExcept3) {
    if (a == 0 or b == 0) {
        if (a == 0)
        {
            throw MyExcept3(" Ошибка в переменной которая равняется : ", a);
        }
        else {
            throw MyExcept3("Ошибка в переменной которая равняется: ", b);
       }
    }
   
    double c, l, x, y, z;
    c = pow(pow(a, 2) + pow(b, 2), 1 / 2);
   l = asin(c / a);
   x = l * (180 / 3.14159);
    y = 90;
    z = 180 - (y + x);

    cout << "Углы равны: " << y << " | " << x << " | " << z << endl;
}

void launcher(void (*func)(double, double)) {
    double a, b;
    cout << "Введите a=";
    cin >> a;
    cout << "Введите b=";
    cin >> b;

    
    func(a, b);
}
using namespace std;
int main()
{
    int x = 500;
    int y = 0;
    

   cout << "The End..." << endl;
   setlocale(LC_ALL, "rus");
   cout << "Функция вычисляет градусы прямоугольного треугольника\n";

   try {
       launcher(root1);
   }
   catch (...) {
       cout << "Произошло исключение в функции root1" << endl;
   }

   try {
       launcher(root2);
   }
   catch (...) {
       cout << "Произошло исключение в функции root2" << endl;
   }

   try {
       launcher(root3);
   }
   catch (invalid_argument& e) {
       cout << e.what() << endl;
   }

   try {
       launcher(root4_1);
   }
   catch (MyExcept1) {
       cout << "Произошло исключение MyExcept1 в функции root4_1" << endl;
   }

   try {
       launcher(root4_2);
   }
   catch (MyExcept2& e) {
       cout << e.message() << endl;
   }

   try {
      launcher(root4_3);
   }
  catch (MyExcept3& e) {
      cout <<  " " << e.arg() << endl;
 }
    return 0;
}


//15. Функція обчислює кути прямокутного трикутника.У якості параметрів
//передаються катети А и В.(Синус кута А1, протилежного катету А, обчислюється
//    по формулі sin(A1) = a / c де c — гіпотенуза трикутника.)


