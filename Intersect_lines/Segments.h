#pragma once
#include "Tree.h"
#include"Segment.h"

#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
#ifndef AISD_SECTION_H
#define AISD_SECTION_H

bool intersection(const Segment& a, const Segment& b);

class Segs {
    std::vector<Segment> segments;
    std::vector<Point> points;

    int partition(int l, int r);
    Segment* randCreateSeg(int width);
    Segment* randSegsByLength(double len);
public:
    Segs() {};
    Segs(const Segs& s);

    void rSetByPoints(int n, int k = -1, int width = 1);
    void rSetByLength(double length, int n);

    size_t getLen() { return segments.size(); }
    size_t getPointLen() { return points.size(); }
    void pushBack(Segment seg);
    void sortPoints(int l, int r);

    void readFromFile(const std::string& filePath);
    void saveToFile(const std::string& filePath, bool clearFile = false);
    void printS();
    void clear();

    bool intersectionNaive();
    bool intersectionEffective();

    bool seg_has_inter_befor_K(const Segment& s, int k);
    bool seg_has_inter_wout_last(const Segment& s, int k);

    Segment front() { return segments.front(); }
    Segment back() { return segments.back(); }

    friend std::ostream& operator << (std::ostream& out, const std::vector<Point>& vec);

    Segment operator [] (int i) {
        if (i < 0 || i >= segments.size()) {
            throw - 1;
        }
        return segments[i];
    }
};

#endif //AISD_SECTION_H