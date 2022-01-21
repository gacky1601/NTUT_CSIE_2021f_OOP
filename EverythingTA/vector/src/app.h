#ifndef APP_H
#define APP_H
#include <vector>
#include "shape.h"
#include <algorithm>

class App {

private:
    std::vector<Shape *> _shapes;
public:
    
    //default constructor
    App() {

    }
    ~App(){
        // for(int i = 0; i < _shapes.size(); i++) {
        //     delete _shapes[i];
        // }
        for(Shape * s : _shapes) {
            delete s;
        }
    }
    void add(Shape* s) {
        _shapes.push_back(s);
    }
    void sort() {
        std::sort(_shapes.begin(), _shapes.end(), 
        [](Shape* a, Shape* b){ //anonymous function, a.k.a lambda function
            return a->area() < b->area();
        });
    }
    Shape * at(int index) const {
        return _shapes[index];
    }
};
#endif