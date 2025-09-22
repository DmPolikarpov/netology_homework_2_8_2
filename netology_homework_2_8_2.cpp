#include <iostream>
#include <Windows.h>

#include "shapeException.h"

class Shape
{

public:
    virtual void getSides() {};
    virtual void getAngles() {};
    virtual int getSidesNumber() { return 0; };
    virtual bool isCorrect() { return true; };
};

class Triangle : public Shape
{
private:
    int side1{};
    int side2{};
    int side3{};
    int angle1{};
    int angle2{};
    int angle3{};
    int sides{ 3 };

public:
    Triangle(int setSide1, int setSide2, int setSide3, int setAngle1, int setAngle2, int setAngle3) : side1{ setSide1 }, side2{ setSide2 }, side3{ setSide3 }, angle1{ setAngle1 }, angle2{ setAngle2 }, angle3{ setAngle3 }
    {
        if (!isCorrect())
            throw ShapeException("Ошибка создания треугольника, проверьте входные данные!");
    };
    void getSides() override
    {
        std::cout << "Стороны: a = " << side1 << " b = " << side2 << " c = " << side3 << std::endl;
    };
    void getAngles() override
    {
        std::cout << "Углы: A = " << angle1 << " B = " << angle2 << " C = " << angle3 << std::endl;
    };
    int getSidesNumber() override { return sides; };

    bool isCorrect() {
        return angle1 + angle2 + angle3 == 180 && side1 && side2 && side3 ? true : false;
    };
    int getSide1() {
        return side1;
    };
    int getSide2() {
        return side2;
    };
    int getSide3() {
        return side3;
    };
    int getAngle1() {
        return angle1;
    };
    int getAngle2() {
        return angle2;
    };
    int getAngle3() {
        return angle3;
    };
};

// TRIANGLE OPTIONS

class RightTriangle : public Triangle
{
public:
    RightTriangle(int setSide1, int setSide2, int setSide3, int setAngle1, int setAngle2) : Triangle{ setSide1, setSide2, setSide3, setAngle1, setAngle2, 90 }
    {
        if (Triangle::isCorrect() && !isCorrect())
            throw ShapeException("Ошибка создания прямоугольного треугольника, проверьте входные данные!");
    };

    bool isCorrect() {
        return Triangle::isCorrect() && getAngle3() == 90 ? true : false;
    };
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int setSide1, int setSide2, int setAngle1, int setAngle2) : Triangle{ setSide1, setSide2, setSide2, setAngle1, setAngle2, setAngle2 }
    {
        if (Triangle::isCorrect() && !isCorrect())
            throw ShapeException("Ошибка создания равнобедренного треугольника, проверьте входные данные!");
    };
    bool isCorrect() {
        return Triangle::isCorrect() && getAngle1() == getAngle3() && getSide1() == getSide3() ? true : false;
    };
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    EquilateralTriangle(int setSide) : IsoscelesTriangle{ setSide, setSide, 60, 60 }
    {
        if (IsoscelesTriangle::isCorrect() && !isCorrect())
            throw ShapeException("Ошибка создания равностороннего треугольника, проверьте входные данные!");
    };
    bool isCorrect() {
        return IsoscelesTriangle::isCorrect() && getAngle1() == 60 && getAngle3() == 60 && getAngle2() == 60 && getSide1() == getSide2() && getSide1() == getSide3() && getSide2() == getSide3() ? true : false;
    };
};

// QUADRANGLE OPTIONS

class Quadrangle : public Shape
{
private:
    int side1{};
    int side2{};
    int side3{};
    int side4{};
    int angle1{};
    int angle2{};
    int angle3{};
    int angle4{};
    int sides{ 4 };

public:
    Quadrangle(int setSide1, int setSide2, int setSide3, int setSide4, int setAngle1, int setAngle2, int setAngle3, int setAngle4) :
        side1{ setSide1 }, side2{ setSide2 }, side3{ setSide3 }, side4{ setSide4 }, angle1{ setAngle1 }, angle2{ setAngle2 }, angle3{ setAngle3 }, angle4{ setAngle4 }
    {
        if (!isCorrect())
            throw ShapeException("Ошибка создания четырехугольника, проверьте входные данные!");
    };
    void getSides() override
    {
        std::cout << "Стороны: a = " << side1 << " b = " << side2 << " c = " << side3 << " d = " << side4 << std::endl;
    };
    void getAngles() override
    {
        std::cout << "Углы: A = " << angle1 << " B = " << angle2 << " C = " << angle3 << " D = " << angle4 << std::endl;
    };
    int getSidesNumber() override { return sides; };

    bool isCorrect() {
        return angle1 + angle2 + angle3 + angle4 == 360 && side1 && side2 && side3 && side4 ? true : false;
    };
    int getSide1() {
        return side1;
    };
    int getSide2() {
        return side2;
    };
    int getSide3() {
        return side3;
    };
    int getSide4() {
        return side4;
    };
    int getAngle1() {
        return angle1;
    };
    int getAngle2() {
        return angle2;
    };
    int getAngle3() {
        return angle3;
    };
    int getAngle4() {
        return angle4;
    };
};

class Rectangle1 : public Quadrangle
{
public:
    Rectangle1(int setSide1, int setSide2) : Quadrangle{ setSide1, setSide2, setSide1, setSide2, 90, 90, 90, 90 }
    {
        if (Quadrangle::isCorrect() && !isCorrect())
            throw ShapeException("Ошибка создания прямоугольника, проверьте входные данные!");
    };
    bool isCorrect() {
        return Quadrangle::isCorrect() && getAngle1() == 90 && getAngle2() == 90 && getAngle3() == 90 && getAngle4() == 90 && getSide1() == getSide3() && getSide2() == getSide4() ? true : false;
    };
};

class Square : public Rectangle1
{
public:
    Square(int setSide) : Rectangle1{ setSide, setSide }
    {
        if (Rectangle1::isCorrect() && !isCorrect())
            throw ShapeException("Ошибка создания квадрата, проверьте входные данные!");
    };
    bool isCorrect() {
        return Rectangle1::isCorrect() && getAngle1() == 90 && getAngle2() == 90 && getAngle3() == 90 && getAngle4() == 90 &&
            getSide1() == getSide2() && getSide1() == getSide3() && getSide1() == getSide4() &&
            getSide2() == getSide3() && getSide2() == getSide4() &&
            getSide3() == getSide4() ? true : false;
    };
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int setSide1, int setSide2, int setAngle1, int setAngle2) : Quadrangle{ setSide1, setSide2, setSide1, setSide2, setAngle1, setAngle2, setAngle1, setAngle2 }
    {
        if (Quadrangle::isCorrect() && !isCorrect())
            throw ShapeException("Ошибка создания параллелограмма, проверьте входные данные!");
    };
    bool isCorrect() {
        return Quadrangle::isCorrect() && getAngle1() == getAngle3() && getAngle2() == getAngle4() && getSide1() == getSide3() && getSide2() == getSide4() ? true : false;
    };
};

class Rhomb : public Parallelogram
{
public:
    Rhomb(int setSide1, int setAngle1, int setAngle2) : Parallelogram{ setSide1, setSide1, setAngle1, setAngle2 }
    {
        if (Parallelogram::isCorrect() && !isCorrect())
            throw ShapeException("Ошибка создания ромба, проверьте входные данные!");
    };
    bool isCorrect() {
        return Parallelogram::isCorrect() && getAngle1() == getAngle3() && getAngle2() == getAngle4() &&
            getSide1() == getSide2() && getSide1() == getSide3() && getSide1() == getSide4() &&
            getSide2() == getSide3() && getSide2() == getSide4() &&
            getSide3() == getSide4() ? true : false;
    };
};

// COMMON FUNCTIONS
void print_info(Shape* shape);


int main()
{
    setlocale(LC_ALL, "Russian");

    Shape shape{};
    std::cout << "Фигура: " << std::endl;
    print_info(&shape);

    std::cout << std::endl;

    // TRIANGLES

    try
    {

        Triangle triangle{ 10, 20, 30, 60, 60, 60 };
        RightTriangle rightTriangle{ 10, 20, 45, 45, 45 };
        IsoscelesTriangle isoscelesTriangle{ 10, 20, 40, 50 };
        EquilateralTriangle equilateralTriangle{ 10 };

        // QUADRANGLES

        Quadrangle quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };
        Rectangle1 rectangle{ 10, 20 };
        Square square{ 10 };
        Parallelogram parallelogram{ 10, 20, 50, 60 };
        Rhomb rhomb{ 20, 50, 60 };

        // TRIANGLES DATA

        std::cout << "Треугольник: " << std::endl;
        print_info(&triangle);
        std::cout << "Прямоугольный треугольник: " << std::endl;
        print_info(&rightTriangle);
        std::cout << "Равнобедренный треугольник: " << std::endl;
        print_info(&isoscelesTriangle);
        std::cout << "Равносторонний треугольник: " << std::endl;
        print_info(&equilateralTriangle);

        std::cout << std::endl;

        // QUADRANGLE DATA

        std::cout << "Четырёхугольник: " << std::endl;
        print_info(&quadrangle);
        std::cout << "Прямоугольник: " << std::endl;
        print_info(&rectangle);
        std::cout << "Квадрат: " << std::endl;
        print_info(&square);
        std::cout << "параллелограмм: " << std::endl;
        print_info(&parallelogram);
        std::cout << "Ромб: " << std::endl;
        print_info(&rhomb);

    }
    catch (const ShapeException& exception)
    {
        std::cout << exception.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Неизвестная ошибка!" << std::endl;
    }


    return EXIT_SUCCESS;
}

void print_info(Shape* shape)
{
    shape->isCorrect() ? std::cout << "Правильная" << std::endl : std::cout << "Неправильная" << std::endl;
    std::cout << "Количество сторон: " << shape->getSidesNumber() << std::endl;
    shape->getSides();
    shape->getAngles();
    std::cout << std::endl;
};
