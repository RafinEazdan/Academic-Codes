#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x, y;
};

float area(const Point& a,const Point& b,const Point& c ){
    return abs((a.x*(b.y-c.y))+b.x*(c.y-a.y)+c.x*(a.y-b.y));
}

bool isInsideTriangle(const Point& p, const Point& a, const Point& b, const Point& c) {
   
    double a1 = area(a,b,c);
    double a2 = area(p,b,c);
    double a3 = area(a,p,c);
    double a4 = area(a,b,p);
    return(a1 == a2+a3+a4);
}

vector<Point> findExtremePoints(vector<Point>& points) {
    vector<Point> extremePoints;

    for (int i = 0; i < points.size(); i++) {
        bool isExtreme = true;
        for (int j = 0; j < points.size(); j++) {
            if (i == j) continue;
            for (int k = 0; k < points.size(); k++) {
                if (i == k || j == k) continue;
                if (isInsideTriangle(points[i], points[j], points[k], points[k + 1])) {
                    isExtreme = false;
                    break;
                }
            }
            if (!isExtreme) break;
        }
        if (isExtreme) extremePoints.push_back(points[i]);
    }

    return extremePoints;
}

int main() {
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4},{0, 0}, {1, 2}, {3, 1}, {3, 3}};
    vector<Point> extremePoints = findExtremePoints(points);

    cout << "Extreme points of the convex hull: " << endl;
    for (const Point& point : extremePoints) {
        cout << "(" << point.x << ", " << point.y << ")" << endl;
    }

    return 0;
}
