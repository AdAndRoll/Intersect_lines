#pragma once
#include "iostream"

#ifndef INTERSECTIONS_OF_SEGMENTS_PSEG_H
#define INTERSECTIONS_OF_SEGMENTS_PSEG_H


#define ERROR_RATE 100000000
using namespace std;
int r(int left = -1000, int right = 1000);

struct Point {
    double x, y;
    double z = 0.0;
    Point() {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }
    Point(double x1, double y1) {
        x = x1;
        y = y1;
        z = 0.0;
    }
    Point(double x1, double y1, double z1) {
        x = x1;
        y = y1;
        z = z1;
    }
    Point(Point const &point);

    bool isLeft = false;
    bool beforeK(int k = -1) const {
        return k != -1 && segmentIndex <= k + 2;
    }
    int segmentIndex = -1;

    friend Point operator - (Point& p1, Point& p2);
    friend std::ostream& operator << (std::ostream& out, Point p);
    Point& operator = (const Point& p);
    friend bool operator == (Point& p1, Point& p2);
    friend bool operator < (Point& p1, Point& p2);
    friend bool operator <= (Point& p1, Point& p2);
    friend bool operator > (Point& p1, Point& p2);
    friend bool operator >= (Point& p1, Point& p2);
};

struct Vector {
    Point p;
    
    double x() { return p.x; }
    double y() { return p.y; }
    double z() { return p.z; }
    Vector (Point p1) {
        p = p1;
    }

    friend Vector operator * (Vector& v1, Vector& v2);
};


class Segment {
    Point p1;
    Point p2;

    double k;
    double b;
public:
    Segment();
    Segment(Point _p1, Point _p2);
    Segment(const Segment& seg);

    void calcCoef();
    void setSegIndexForPoints(int ind);

    Point getP1() const { return p1; }
    Point getP2() const { return p2; }

    double calcY(double time);

    friend std::ostream& operator << (std::ostream& out, Segment& seg);
    friend std::ostream& operator << (std::ostream& out, const Segment& seg);
    friend bool operator == (Segment seg1, Segment seg2);
    friend bool operator != (Segment seg1, Segment seg2);
};


#endif 