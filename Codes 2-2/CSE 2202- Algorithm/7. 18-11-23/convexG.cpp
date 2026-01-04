#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Point {
    double x, y;
    static bool compare(Point a, Point b) {
        double angleA = atan2(a.y, a.x);
        double angleB = atan2(b.y, b.x);
        return angleA < angleB || (angleA == angleB && hypot(a.x, a.y) < hypot(b.x, b.y));
    }
};
double crossProduct(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();  
    int pivot = 0;
    for (int i = 1; i < n; ++i) {
        if (points[i].y < points[pivot].y || (points[i].y == points[pivot].y && points[i].x < points[pivot].x)) {
            pivot = i;
        }
    }
    swap(points[0], points[pivot]);
    sort(points.begin() + 1, points.end(), Point::compare);
    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    for (int i = 2; i < n; ++i) {
        while (hull.size() > 1 && crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    vector<Point> points;
    ifstream inFile("rough.txt");
    Point tempPoint;
    while(inFile>> tempPoint.x >> tempPoint.y){
        points.push_back(tempPoint);
    }
    clock_t start = clock();
    vector<Point> convexHullPoints = convexHull(points);
    clock_t end = clock();
    cout << "Convex Hull Points:\n";
    for (const auto& point : convexHullPoints) {
        cout << "(" << point.x << ", " << point.y << ")\n";
    }
    cout<<"Time required: "<< ((float)(end - start) / CLOCKS_PER_SEC)*1000<<"ms"<<endl;
    inFile.close();
    return 0;
}
