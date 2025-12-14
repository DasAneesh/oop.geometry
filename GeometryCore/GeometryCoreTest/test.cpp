#include<gtest/gtest.h>
#include "../GeometryCore/Shapes.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

TEST(VectorTests, ConstructorAndGetters) {
    Vector v(3.5, -2.0);
    EXPECT_DOUBLE_EQ(v.getX(), 3.5);
    EXPECT_DOUBLE_EQ(v.getY(), -2.0);
}

TEST(VectorTests, ArithmeticOperations) {
    Vector v1(1, 2);
    Vector v2(3, 4);

    Vector sum = v1 + v2;
    EXPECT_DOUBLE_EQ(sum.getX(), 4.0);
    EXPECT_DOUBLE_EQ(sum.getY(), 6.0);

    Vector diff = v2 - v1;
    EXPECT_DOUBLE_EQ(diff.getX(), 2.0);
    EXPECT_DOUBLE_EQ(diff.getY(), 2.0);

    Vector scaled = v1 * 3.0;
    EXPECT_DOUBLE_EQ(scaled.getX(), 3.0);
    EXPECT_DOUBLE_EQ(scaled.getY(), 6.0);
}

TEST(PointTests, Distance) {
    Point p1(0, 0);
    Point p2(10, 0);
    EXPECT_DOUBLE_EQ(p1.distanceTo(p2), 10.0);
}

TEST(PointTests, Operations) {
    Point p(1, 1);
    Vector v(2, 3);

    Point newP = p + v;
    EXPECT_DOUBLE_EQ(newP.getX(), 3.0);
    EXPECT_DOUBLE_EQ(newP.getY(), 4.0);

    Vector diff = newP - p;
    EXPECT_DOUBLE_EQ(diff.getX(), 2.0);
    EXPECT_DOUBLE_EQ(diff.getY(), 3.0);
}

TEST(CircleTests, AreaAndPerimeter) {
    Circle c(Point(0, 0), 10.0);

    EXPECT_NEAR(c.area(), 314.159265, 1e-5);
    EXPECT_NEAR(c.perimeter(), 62.831853, 1e-5);
}

TEST(CircleTests, ContainsPoint) {
    Circle c(Point(0, 0), 5.0);

    EXPECT_TRUE(c.containsPoint(Point(3, 4)));  
    EXPECT_TRUE(c.containsPoint(Point(0, 0)));  
    EXPECT_FALSE(c.containsPoint(Point(6, 0)));
}

TEST(RectangleTests, Logic) {
    Rectangle r(Point(0, 0), 10, 5); 

    EXPECT_DOUBLE_EQ(r.area(), 50.0);
    EXPECT_DOUBLE_EQ(r.perimeter(), 30.0);

    EXPECT_TRUE(r.containsPoint(Point(5, 2))); 
    EXPECT_TRUE(r.containsPoint(Point(10, 5))); 
    EXPECT_FALSE(r.containsPoint(Point(11, 5))); 
}

TEST(TriangleTests, NormalTriangle) {
    Triangle t(Point(0, 0), Point(4, 0), Point(0, 3));

    EXPECT_DOUBLE_EQ(t.area(), 6.0);    
    EXPECT_DOUBLE_EQ(t.perimeter(), 12.0); 

    EXPECT_TRUE(t.containsPoint(Point(1, 1))); 
    EXPECT_FALSE(t.containsPoint(Point(4, 4))); 
}

TEST(TriangleTests, DegenerateException) {

    EXPECT_THROW({
        Triangle t(Point(0, 0), Point(1, 1), Point(2, 2));
        }, std::invalid_argument);
}