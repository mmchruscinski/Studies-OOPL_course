//1. Create a class named Point which represents a point on a plane. The class should contain:
//a. a constructor with default argument values,
//b. getter and setter methods for each field.

//2. Create a class named Rectangle which represents a rectangle on a plane.
//a. Consider what properties each rectangle on the plane has. Create the
//appropriate fields in the class to represent each of the properties. If
//necessary, use the Point class to store the rectangle's properties.
//b. Create the appropriate constructor in the class to initialize all class fields with
//default values. The constructor should have default values for each of its
//arguments.
//c. Add methods to read (getter) and modify (setter) each field.
//d. Extend the Rectangle class with methods that make it possible to perform
//simple geometric transformations, such as moving a rectangle on a plane by
//a certain vector. Also add a method that returns a rectangle's area.
//e. Create a method named print that prints the properties of the rectangle on
//the screen.
//f. In the main function, create an object of the Rectangle class and then
//modify its properties using setters methods. Print the object's state before and
//after modification using the print function. Perform a geometric
//transformation on the rectangle and print its state before and after the
//transformation

#include <iostream>
using namespace std;

class Point
{
private:
    float m_x, m_y;

public:
    Point() : m_x(0), m_y(0) {
        cout << "Default point created" << endl;
    }
    Point(float x, float y) : m_x(x), m_y(y) {
        cout << "Point (" << m_x << ", " << m_y << ") created" << endl;
    }
    void setLoc(float x, float y){
        m_x = x;
        m_y = y;
    }
    void moveX(float x) { m_x += x; }
    void moveY(float y) { m_y += y; }

    float getX() const { return m_x; }
    float getY() const { return m_y; }

    void printLoc(){
        cout << "X location: " << m_x << endl << "Y location: " << m_y << endl;
    }   
    void copyFrom(const Point& d){
        m_x = d.m_x;
        m_y = d.m_y;
    }
};

class Rectangle
{
private:
    Point m_p1, m_p2;
    float m_area;

public:
    Rectangle(){
        m_area = 0;
        cout << "Deafult rectangle created" << endl;
    }
    Rectangle(Point p1, Point p2) : m_p1{p1}, m_p2{p2} {                                //uniform initialization (C++11)
        m_area = abs(m_p1.getX() - m_p2.getX()) * abs(m_p1.getY() - m_p2.getY());
    }
    void printProp(){
        cout << "Rectangle's properties:" << endl;
        cout << "First corner: " << endl; m_p1.printLoc();
        cout << "Second corner: " << endl; m_p2.printLoc();
        cout << "Area: " << m_area << endl;
    }
    void move(float x, float y){
        m_p1.moveX(x);
        m_p1.moveY(y);
        m_p2.moveX(x);
        m_p2.moveY(y);
        }
    
    Point getP1() const { return m_p1; }
    Point getP2() const { return m_p2; }
    float getA() const {return m_area; }

    void setP1(Point p) { m_p1 = p; }
    void setP2(Point p) { m_p2 = p; }
};

int main(){

    Point p1;
    Point p2(10,10);

    Rectangle r1(p1, p2);

    r1.printProp();

    Rectangle r2;

    r2.printProp();

    r1.move(5,10.5);

    r1.printProp();

    return 0;

}