#include <iostream>
#include <cmath>

// Define a structure to represent a point with x and y coordinates
struct Point {
    float x, y;
    Point* prev;
    Point* next;
};

// Function to calculate the signed area of a triangle formed by three points
float Area(Point* p1, Point* p2, Point* p3) {
    return (p1->x * (p2->y - p3->y) + p2->x * (p3->y - p1->y) + p3->x * (p1->y - p2->y)) / 2.0;
}

// Function to implement the Scan algorithm
void Scan(Point* ptslist) {
    Point* p = ptslist;
    Point* p1 = ptslist;

    do {
        Point* p2 = p1->next;
        if (p2->next != nullptr) {
            Point* p3 = p2->next;

            float temp = Area(p1, p2, p3);

            if (temp >= 0.0) {
                p1 = p1->next;
            } else {
                p1->next = p3;
                p3->prev = p1;
                delete p2;
                p1 = p1->prev;
            }
        } else {
            return; // End of the list
        }
    } while (true);
}

// Function to compare points based on the angle made with the z-axis
bool compareAngles(Point* a, Point* b) {
    float angleA = atan2(a->y, a->x);
    float angleB = atan2(b->y, b->x);
    return angleA < angleB;
}

// Function to sort the points based on the angle made with the z-axis
void Sort(Point* ptslist) {
    std::sort(ptslist->next, nullptr, compareAngles);
}

// Function to print the points in the list
void PrintList(Point* ptslist) {
    Point* current = ptslist;
    while (current != nullptr) {
        std::cout << "(" << current->x << ", " << current->y << ") ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Point* ptslist = new Point{ 0, 0, nullptr, nullptr };

    // Adding points to the list
    Point* p1 = new Point{ 0, 3, nullptr, nullptr };
    Point* p2 = new Point{ 1, 1, nullptr, nullptr };
    Point* p3 = new Point{ 2, 2, nullptr, nullptr };
    Point* p4 = new Point{ 4, 4, nullptr, nullptr };
    Point* p5 = new Point{ 0, 0, nullptr, nullptr };
    Point* p6 = new Point{ 1, 2, nullptr, nullptr };
    Point* p7 = new Point{ 3, 1, nullptr, nullptr };
    Point* p8 = new Point{ 3, 3, nullptr, nullptr };

    ptslist->next = p1;
    p1->prev = ptslist;
    p1->next = p2;
    p2->prev = p1;
    p2->next = p3;
    p3->prev = p2;
    p3->next = p4;
    p4->prev = p3;
    p4->next = p5;
    p5->prev = p4;
    p5->next = p6;
    p6->prev = p5;
    p6->next = p7;
    p7->prev = p6;
    p7->next = p8;
    p8->prev = p7;

    // Sort the points and find the convex hull
    Sort(ptslist);
    Scan(ptslist);

    // Print the resulting convex hull
    std::cout << "Convex Hull Points:\n";
    PrintList(ptslist);

    // Cleanup: Delete the dynamically allocated points
    Point* current = ptslist;
    while (current != nullptr) {
        Point* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
