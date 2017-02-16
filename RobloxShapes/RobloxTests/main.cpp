#include<QtTest>
#include "rectangletests.h"
#include "triangletests.h"
#include "squaretests.h"
#include "circletests.h"
#include "rectanglecircletests.h"
#include "squarecircletests.h"
#include "trianglecircletests.h"
#include "shapemanagertests.h"
#include "rectanglesquaretests.h"
#include "trianglesquaretests.h"

int main(int argc, char *argv[])
{
   int status = 0;

   {
       RectangleTests rectangleTests;
       status |= QTest::qExec(&rectangleTests, argc, argv);
   }

   {
       TriangleTests triangleTests;
       status |= QTest::qExec(&triangleTests, argc, argv);
   }

   {
       SquareTests squareTests;
       status |= QTest::qExec(&squareTests, argc, argv);
   }

   {
       CircleTests circleTests;
       status |= QTest::qExec(&circleTests, argc, argv);
   }

   {
       RectangleCircleTests rectangleCircleTests;
       status |= QTest::qExec(&rectangleCircleTests, argc, argv);
   }

   {
       SquareCircleTests squareCircleTests;
       status |= QTest::qExec(&squareCircleTests, argc, argv);
   }

   {
       TriangleCircleTests triangleCircleTests;
       status |= QTest::qExec(&triangleCircleTests, argc, argv);
   }

   {
       RectangleSquareTests rectangleSquareTests;
       status |= QTest::qExec(&rectangleSquareTests, argc, argv);
   }

   {
       TriangleSquareTests triangleSquareTests;
       status |= QTest::qExec(&triangleSquareTests, argc, argv);
   }


   {
        ShapeManagerTests shapeManagerTests;
        status |= QTest::qExec(&shapeManagerTests, argc, argv);
   }

   return status;
}
