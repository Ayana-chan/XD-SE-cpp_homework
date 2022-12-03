#include <iostream>

using namespace std;

class Circle;
class Square;
class Triangle;

class Shape
{
public:
    virtual bool intersect_sec(Shape* const s) = 0;//second dispatch.dispatch s2
//    bool intersect_sec(Shape* const s){
//        return s->judgeIntersect(*this);//error,cuz 'this' is regarded as Shape.
//    };
    //judge function
    virtual bool judgeIntersect(Circle& s) = 0;
    virtual bool judgeIntersect(Square& s) = 0;
    virtual bool judgeIntersect(Triangle& s) = 0;
};

class Circle : public Shape
{
public:
    bool intersect_sec(Shape* const s){
        return s->judgeIntersect(*this);
    }

    bool judgeIntersect(Circle& s){
        cout << "Circle & Circle" << endl;
        return false;
    }
    bool judgeIntersect(Square& s){
        cout << "Circle & Square" << endl;
        return false;
    }
    bool judgeIntersect(Triangle& t){
        cout << "Circle & Triangle" << endl;
        return false;
    }
};

class Square : public Shape
{
public:
    bool intersect_sec(Shape* const s){
        return s->judgeIntersect(*this);
    }

    bool judgeIntersect(Circle& s){
        return s.judgeIntersect(*this);//swap arguments to be handled in another function
    }
    bool judgeIntersect(Square& s){
        cout << "Square & Square" << endl;
        return false;
    }
    bool judgeIntersect(Triangle& s){
        cout << "Square & Triangle" << endl;
        return false;
    }
};

class Triangle : public Shape
{
public:
    bool intersect_sec(Shape* const s){
        return s->judgeIntersect(*this);
    }

    bool judgeIntersect(Circle& s){
        return s.judgeIntersect(*this);
    }
    bool judgeIntersect(Square& s){
        return s.judgeIntersect(*this);
    }
    bool judgeIntersect(Triangle& s){
        cout << "Triangle & Triangle" << endl;
        return false;
    }
};


bool intersect(Shape* s1, Shape* s2)//first dispatch.dispatch s1
{
    return s1->intersect_sec(s2);
}

int main()
{
    Circle circle;
    Square square;
    Triangle triangle;

    intersect(&circle,&circle);
    intersect(&square, &square);
    intersect(&triangle, &triangle);cout<<endl;

    intersect(&circle, &square);
    intersect(&square, &circle);cout<<endl;

    intersect(&circle, &triangle);
    intersect(&triangle, &circle);cout<<endl;

    intersect(&square, &triangle);
    intersect(&triangle, &square);cout<<endl;
}
