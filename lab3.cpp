#include <iostream>
#include <conio.h>
#include <vector>
#include <variant>
#include <random>
#include <ctime>
using namespace std;
int storageSize;

class Point {//определение класса Point
public: //доступны в данном классе и классах-потомках
    int x, y;
public:
    Point() { //конструктор по умолчанию
        x = 0;
        y = 0;
    }
    Point(int x, int y) { //конструктор с параметрами
        this->x = x;
        this->y = y;
    }
    Point(const Point& p)  //конструктор копирования
    {
        x = p.x;
        y = p.y;
    }
    ~Point() //деструктор Point
    {

    }
    void method1() //реализация метода в определении класса
    {
        cout << "black\n";
   
    }
    void method2() //реализация метода в определении класса
    {
        cout << "white\n";
    }
};

class ColoredPoint : public Point {//класс-наследник класса Point
protected:
    int color;
public:
    ColoredPoint() :Point() //конструктор по умолчанию
    {
        color = 0;
    }
    ColoredPoint(int x, int y, int color) :Point(x, y) //конструктор с параметрами
    {
        this->color = color;
    }
    ColoredPoint(const ColoredPoint& p) {//конструктор копирования
        color = p.color;
        x = p.x;
        y = p.y;
    }
    ~ColoredPoint() {//деструктор ColoredPoint

    }
    void change_color(int new_color) {//метод смены цвета
        color = new_color;
    }

};

class MyStorage {
private:
    Point** array;
    int size;
    int amount=storageSize;
public:
    MyStorage(int size)//конструктор с параметром
    {
        this->size = size;
        array = new Point * [size];
    }
    void setObject(int i, Point* object)  //метод  добавления объекта
    {
        array[i] = object;
    }
    int getCount() //метод возвращения количества
    {
        return amount;
    }
    Point getObject(int i)  //метод обращения к объекту
    {
        return *array[i];
    }
    void deleteObject(int i) //метод удаления объекта
    {
        Point* p1 = array[i];
        if (p1->x == -572662307) 
        {
            cout << i <<" is empty " << endl;
            return;
        }
        else delete array[i];
        cout << "deleted element with index " << i << endl;
    }
    ~MyStorage() //деструктор MyStorage
            {
             
            }
};

int main()
{
    cout << "Enter storage size: ";
    cin >> storageSize; 
    MyStorage storage(storageSize);  // создаем хранилище 
    for (int i = 0; i < storage.getCount(); i++)     // добавляем в него объекты
    {
        random_device random;// генератор псевдо случайных чисел
        mt19937 mersenne(random());
        int m = random() % (2 + 1 - 1) + 1;
        if (m == 1) // создание и добавление объекта Point
        {
            int x = random() % (100 + 1 - 1) + 1;
            int y = random() % (100 + 1 - 1) + 1;
            storage.setObject(i, new Point(x, y));
            cout << "Point "<< i  << " (" << x << ", " << y << ")" << endl;

        }
        if (m == 2) // создаие и добавление объекта ColoredPoint
        {
            int x = random() % (100 + 1 - 1) + 1;
            int y = random() % (100 + 1 - 1) + 1;
            int c = random() % (100 + 1 - 1) + 1;
            storage.setObject(i, new ColoredPoint(x, y, c));
            cout << "ColoredPoint "<< i  <<"(" << x << ", " << y << ", " << c << ")" << endl;
        }
    }
    cout << endl;

    int operations;
    cout << "Enter amount of operations: ";
    cin >> operations;
    cout  << endl;
    cout  << endl;
    unsigned int start_time = clock(); // старт таймера
    for (int i = 0; i < operations; i++) {    // рандомные действия
        random_device random;// генератор псевдо случайных чисел
        mt19937 mersenne(random());
        int m = random() % (3 + 1 - 1) + 1;

        if (m == 1) 
        {
            int n = random() % (2 + 1 - 1) + 1;
            if (n == 1) // создаие и добавление объекта Point
            {
                int x = random() % (100 + 1 - 1) + 1;
                int y = random() % (100 + 1 - 1) + 1;
                int l = random() % (storageSize + 0 - 0) + 0;
                storage.setObject(l, new Point(x, y));
                cout << "Created new Point " << i << " (" << x << ", " << y << ")" << endl;
            }
            if (n == 2) // создаие и добавление объекта ColoredPoint
            {
                int x = random() % (100 + 1 - 1) + 1;
                int y = random() % (100 + 1 - 1) + 1;
                int c = random() % (100 + 1 - 1) + 1;
                int l = random() % (storageSize + 0 - 0) + 0;
                storage.setObject(l, new ColoredPoint(x, y, c));
                cout << "Created new ColoredPoint " << i << "(" << x << ", " << y << ", " << c << ")" << endl;
            }
        }
            if (m == 2) //удаление объекта
            {
                int l = random() % (9 + 0 - 0) + 0;
                storage.deleteObject(l);
            }
            if (m == 3) //вызов случайного метода
            {
                int l = random() % (9 + 0 - 0) + 0;
                int n = random() % (2 + 1 - 1) + 1;

                if (n == 1) 
                {
                    cout << "Method1 call on element with index " << l << ": ";                   
                    storage.getObject(l).method1();

                }
                if (n == 2) 
                {
                    cout << "Method2 call on element with index " << l << ": ";
                    storage.getObject(l).method2();
                }
            }
        }

        unsigned int end_time = clock();//остановка таймера
        unsigned int search_time = end_time - start_time;
        cout << endl;
        cout << "Runtime: " <<((float)search_time) / CLOCKS_PER_SEC<< " seconds"<<endl;
        _getch();
    }


