#include <bits/stdc++.h>
using namespace std;
struct Point
{
    float x, y;
    Point *prev;
    Point *next;
};

float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
    return (x2 * y3 - x3 * y2) - (x1 * y3 - x3 * y1) + (x1 * y2 - x2 * y1);
}

void Scan(Point *list)
{
    Point *p = list;
    Point *p1 = list;

    do
    {
        Point *p2 = p1->next;
        Point *p3 = p2 ? p2->next : nullptr;

        if (!p3)
        {
            return; // End of the list
        }

        float temp = area(p1->x, p1->y, p2->x, p2->y, p3->x, p3->y);

        if (temp >= 0.0f)
        {
            p1 = p1->next;
        }
        else
        {
            p1->next = p3;
            p3->prev = p1;
            delete p2;
            p1 = p1->prev;
        }
    } while (true);
}

void Sort(Point *&list)
{
    // Sort points according to the angle made with the first point and the z-axis
    // Use a custom comparison function that compares the angles
    std::sort(list, list, [](Point *a, Point *b)
              {
        if (a->y < b->y) {
            return true;
        } else if (a->y > b->y) {
            return false;
        } else {
            // Same y-coordinate, compare angles
            float angle1 = std::atan2(a->x, a->y);
            float angle2 = std::atan2(b->x, b->y);
            return angle1 < angle2;
        } });
}

void ConvexHull(Point *&ptslist)
{
    // Sort points and perform the Scan algorithm
    Sort(ptslist);
    Scan(ptslist);
}
