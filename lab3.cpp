#include <iostream>
#include <conio.h>
#include <vector>
#include <variant>
#include <random>
#include <ctime>
using namespace std;

class Point {
public:
    int x, y;
public:
    Point() {
        cout << "Point()\n";
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
       // cout << "Point(int x, int y)\n";
        this->x = x;
        this->y = y;
    }
    Point(const Point& p) {
        //cout << "Point(const Point &p)\n";
        x = p.x;
        y = p.y;
    }
    ~Point() {
        //cout << "~Point()\n";
        //cout << x << ", " << y << endl;
    }
    void method1() {
        cout << "black\n";
   
    }
    void method2() {
        cout << "white\n";
  
    }
    // void reset();
};

class ColoredPoint : public Point {
protected:
    int color;
public:
    ColoredPoint() :Point() {
        cout << "ColoredPoint()\n";
        color = 0;
    }
    ColoredPoint(int x, int y, int color) :Point(x, y) {
        //cout << "ColoredPoint(int x, int y, int color)\n";
        //cout << "ColoredPoint (" << x << ", " << y << ", " << color << ")"<<endl;
        this->color = color;
    }
    ColoredPoint(const ColoredPoint& p) {
        cout << "ColoredPoint(const ColoredPoint &p)\n";
        color = p.color;
        x = p.x;
        y = p.y;
    }
    ~ColoredPoint() {
        //cout << x << ", " << y << endl;
        //cout << "~ColoredPoint()\n";
    }
    void change_color(int new_color) {
        color = new_color;
    }

};

 
//    int getCount()
//    {
//        amount = sizeof(array) / sizeof(array[0]);
//        return amount;


class MyStorage {
private:
    Point** array;
    int size;
    int amount=10;
public:
    MyStorage(int size)
    {
        this->size = size;
        array = new Point * [size];
    }
    void setObject(int i, Point* object) {
        array[i] = object;
    }
    int getCount()
    {
        //amount = sizeof(objects) / sizeof(objects[0]);
        return amount;
    }
    Point getObject(int i) {
        return *array[i];
    }
    void deleteObject(int i) {
        Point* p1 = array[i];
        if (p1->x == -572662307) {
            cout << i <<" is empty " << endl;
        }
        else delete array[i];
        cout << "deleted " << i << endl;
    }
    ~MyStorage()
            {
             
            }
};

int main()
{
    unsigned int start_time = clock();
    int kol = 10;
    // создаем хранилище
    MyStorage storage(10);
    // добавляем в него объекты
    for (int i = 0; i < storage.getCount(); i++) {
        random_device random;// генератор псевдо случайных чисел
        mt19937 mersenne(random());
        int m = random() % (2 + 1 - 1) + 1;
        if (m == 1) {
            int x = random() % (100 + 1 - 1) + 1;
            int y = random() % (100 + 1 - 1) + 1;
            storage.setObject(i, new Point(x, y));
            cout << "Point "<< i  << " (" << x << ", " << y << ")" << endl;

        }
        if (m == 2) {
            int x = random() % (100 + 1 - 1) + 1;
            int y = random() % (100 + 1 - 1) + 1;
            int c = random() % (100 + 1 - 1) + 1;
            storage.setObject(i, new ColoredPoint(x, y, c));
            cout << "ColoredPoint "<< i  <<"(" << x << ", " << y << ", " << c << ")" << endl;
        }
    }
    // обращаемся поочередно ко всем
    for (int i = 0; i < storage.getCount(); i++) {
        random_device random;// генератор псевдо случайных чисел
        mt19937 mersenne(random());
        int m = random() % (2 + 1 - 1) + 1;
        if (m == 1) {
            storage.getObject(i).method1();
        }
        if (m == 2) {
            storage.getObject(i).method2();
        }
    }
    cout  << endl;
    cout  << endl;

    // рандомные действия
    for (int i = 0; i < storage.getCount(); i++) {
        random_device random;// генератор псевдо случайных чисел
        mt19937 mersenne(random());
        int m = random() % (3 + 1 - 1) + 1;

        if (m == 1) {
            int n = random() % (2 + 1 - 1) + 1;
            if (n == 1) {
                int x = random() % (100 + 1 - 1) + 1;
                int y = random() % (100 + 1 - 1) + 1;
                int l = random() % (9 + 0 - 0) + 0;
                storage.setObject(l, new Point(x, y));
                cout << "Point " << i << " (" << x << ", " << y << ")" << endl;
            }
            if (n == 2) {
                int x = random() % (100 + 1 - 1) + 1;
                int y = random() % (100 + 1 - 1) + 1;
                int c = random() % (100 + 1 - 1) + 1;
                int l = random() % (9 + 0 - 0) + 0;
                storage.setObject(l, new ColoredPoint(x, y, c));
                cout << "ColoredPoint " << i << "(" << x << ", " << y << ", " << c << ")" << endl;
            }
        }
            if (m == 2) {
                int l = random() % (9 + 0 - 0) + 0;
                storage.deleteObject(l);
            }
            if (m == 3) {
                int l = random() % (9 + 0 - 0) + 0;
                int n = random() % (1 + 0 - 0) + 0;
                if (n == 0) {
                    storage.getObject(l).method1();

                }
                if (n == 1) {
                    storage.getObject(l).method2();
                }
            }

        }

        {
            /*Point p;
            Point p2(10, 20);
            Point p3(p2);*/
        }

        //Point* p4 = new Point;
       // Point* p5 = new Point(10, 20);
        //Point* p6 = new Point(*p5);

        //p5->reset();
        //p5->move(10, 10);

        //delete p4;
        //delete p5;
        //delete p6;

       // ColoredPoint* cp = new ColoredPoint(1, 2, 42);
        //Point* p7 = new ColoredPoint(1, 2, 42);
        //delete cp;
        //delete p7;

        //Section* s1 = new Section;
        //Section* s2 = new Section(*s1);

       // delete s1;
        //delete s2;
      
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << endl;
        cout << ((float)search_time) / CLOCKS_PER_SEC<< " seconds"<<endl;
        _getch();

    }


