#pragma once
#include <vector>
#include <fstream>
#include <string>

#include "shape.h"
#include "triangle.h"
#include "math_vector.h"

std::vector<Shape *> shapesFromFile(std::string fileName) {
    std::ifstream ifs(fileName);
    std::string name;
    std::vector<Shape *> shapes;

    ifs >> name;
    
    MathVector _u[3];
    for(int i = 0; i < 3; i++) {
        ifs >> _u[i];
    }

    shapes.push_back(new Triangle(_u[0], _u[1], _u[2], "triangle"));

    Triangle *triangle = new Triangle();
    ifs >> *triangle;
    shapes.push_back(triangle);

    // Following is wrong because tri disappears after line 33.
    // Triangle tri;
    // ifs >> tri;
    // shapes.push_back(&tri);

    return shapes;
}
