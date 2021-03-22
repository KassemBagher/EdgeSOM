//
// Created by Kassem Bagher on 2019-04-17.
//

#ifndef EDGESOM_CLOSESTPAIR_H
#define EDGESOM_CLOSESTPAIR_H

// A structure to represent a Point in 2D plane
struct Point2D {
    double x, y;
};

class ClosestPair {
public:
    double closest(Point2D P[], int n, Point2D &p1, Point2D &p2);

private:
    double closest(Point2D P[], Point2D strip[], int n, Point2D &p1, Point2D &p2);
};


#endif //EDGESOM_CLOSESTPAIR_H
