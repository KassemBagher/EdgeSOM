//
// Created by Kassem Bagher on 2019-04-17.
// Adapted from https://www.bogotobogo.com/Algorithms/closest_points_pair.php
//

#include "ClosestPair.h"
// A divide and conquer program in C++ to find the smallest distance from a
// given set of points.

#include "float.h"
#include "stdlib.h"
#include "cmath"
#include <iostream>


// sort by x
inline int compareX(const void *a, const void *b) {
    Point2D *p1 = (Point2D *) a, *p2 = (Point2D *) b;
    return (p1->x - p2->x);
}

// sort by y
inline int compareY(const void *a, const void *b) {
    Point2D *p1 = (Point2D *) a, *p2 = (Point2D *) b;
    return (p1->y - p2->y);
}

// find the distance between two points
inline double dist(Point2D p1, Point2D p2) {
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) +
                ((p1.y - p2.y) * (p1.y - p2.y)));
}

double bruteForce(Point2D P[], int n, Point2D &p1, Point2D &p2) {
    double min = DBL_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min) {
                min = dist(P[i], P[j]);
                p1.x = P[i].x, p1.y = P[i].y;
                p2.x = P[j].x, p2.y = P[j].y;
            }
    return min;
}

// returns minimum of two values
inline double min(double x, double y) {
    return (x < y) ? x : y;
}


// find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted by y.
double stripPoints(Point2D strip[], int size, double d, Point2D &p1, Point2D &p2) {
    double min = d;  // Initialize the minimum distance as d

    qsort(strip, size, sizeof(Point2D), compareY);

// Pick all points one by one and try the next points
// till the difference between y's is smaller than d.
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min) {
                min = dist(strip[i], strip[j]);
                p1.x = strip[i].x, p1.y = strip[i].y;
                p2.x = strip[j].x, p2.y = strip[j].y;
            }

    return min;
}

// find the smallest distance recursively.
// All point in array P are sorted by x
double ClosestPair::closest(Point2D P[], Point2D strip[], int n, Point2D &p1, Point2D &p2) {
    static Point2D ptemp1, ptemp2, ptemp3, ptemp4;

// use brute force when there are not enough points
    if (n <= 3)
        return bruteForce(P, n, p1, p2);

// mid point
    int mid = n / 2;
    Point2D midPoint = P[mid];

// calculate the smallest distance
// dl: left of mid point
// dr: right side of the mid point
    double dl = closest(P, strip, mid, ptemp1, ptemp2);
    double dr = closest(P + mid, strip, n - mid, ptemp3, ptemp4);

// assign the pair that has smaller distance

    if (dl < dr) {
        p1.x = ptemp1.x;
        p1.y = ptemp1.y;
        p2.x = ptemp2.x;
        p2.y = ptemp2.y;
    } else {
        p1.x = ptemp3.x;
        p1.y = ptemp3.y;
        p2.x = ptemp4.x;
        p2.y = ptemp4.y;
    }

    double dmin = min(dl, dr);

    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < dmin)
            strip[j++] = P[i];

    double dmin_strip = stripPoints(strip, j, dmin, ptemp1, ptemp2);
    double final_min = dmin;
    if (dmin_strip < dmin) {
        p1.x = ptemp1.x;
        p1.y = ptemp1.y;
        p2.x = ptemp2.x;
        p2.y = ptemp2.y;
        final_min = dmin_strip;
    }
    return final_min;
}

double ClosestPair::closest(Point2D P[], int n, Point2D &p1, Point2D &p2) {

    qsort(P, n, sizeof(Point2D), compareX);
    Point2D *strip = new Point2D[n];

    return closest(P, strip, n, p1, p2);
}
