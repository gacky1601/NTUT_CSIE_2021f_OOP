#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include "math_vector.h"
#include "shape.h"

MathVector centroid(int numberOfVertex, MathVector* vertex)
{
    MathVector centroid;
    //double x, y;
    for(int i = 0; i < numberOfVertex; i++){
        centroid = centroid + vertex[i];
    }
    // std::cout << centroid.at(0) << " " << centroid.at(1) << std::endl;
    return centroid / (double)(numberOfVertex);
    //return MathVector(x, y);
}
class Factory; //forward declaration

// Derived class of shape.
class Polygon : public Shape{
friend class Factory;
friend Polygon createPolygonSA(int numberOfVertex, MathVector* vertex);
public:

    static Polygon createPolygon(int numberOfVertex, MathVector* vertex){ // simple factory (smart constructor)
        MathVector c = centroid(numberOfVertex, vertex);
        CCWBefore ccwb(c);
        std::sort(vertex, vertex+numberOfVertex, ccwb);
        return Polygon(numberOfVertex, vertex);
    }
    Polygon(){

    }
	/*static bool ccwb(const MathVector &a, const MathVector &b){ //to do
		// (0, 0)
		// where is the centroid? if using _centroid, what will happen?
	}*/
    
    double perimeter() const override
    {
        double sum = 0;
        for(int i = 0; i < _vertex.size(); i++){
            //std::cout << _vertex.at(i).at(0) << ", " << _vertex.at(i).at(1) << std::endl;
            sum += (_vertex.at((i + 1) % (_vertex.size())) - _vertex.at(i)).length();
        }
        //sum += (_vertex[0] - _vertex[_vertex.size()-1]).length();
        return sum;
    }

    double area() const override
    {
        double area = 0;
        int n = (int) _vertex.size();
        for(int i = 0; i < n-2; i++){ // < 2,  = 0, 1
            Triangle T(_vertex[0], _vertex[i + 1], _vertex[(i + 2)]); // 0, 1, 2 -> 0, 2, 3
            area += T.area();
            //aka area += Triangle(_vertex[0], _vertex[i + 1], _vertex[(i + 2)]).area();
        }
        return area;
    }
	
    bool operator<(const Polygon &rhs) const
    {
        return (this->perimeter() < rhs.perimeter());
    }

    bool operator>(const Polygon &rhs) const
    {
        return (this->perimeter() > rhs.perimeter());
    }
    std::string toString() const override
    {
        return "";
    }
private:
    std::vector<MathVector> _vertex;
    //MathVector* _vertex;
	//MathVector _centroid; //to do
    Polygon(int numberOfVertex, MathVector* vertex){
        /*for(int i = 0; i < numberOfVertex; i++){
            _vertex.push_back(vertex[i]);
        }*/
        /*_vertex = new MathVector[numberOfVertex];
        for(int i = 0; i < numberOfVertex; i++){
            _vertex[i] = vertex[i];
        }*/
        _vertex = std::vector<MathVector>(vertex, vertex + numberOfVertex);
    }
};

Polygon createPolygonSA(int numberOfVertex, MathVector* vertex){
    MathVector c = centroid(numberOfVertex, vertex);
    CCWBefore ccwb(c);
    std::sort(vertex, vertex+numberOfVertex, ccwb);
    return Polygon(numberOfVertex, vertex);
}

class Factory
{
public:
    Polygon createPolygon(int numberOfVertex, MathVector* vertex){
        MathVector c = centroid(numberOfVertex, vertex);
        CCWBefore ccwb(c);
        std::sort(vertex, vertex+numberOfVertex, ccwb);
        return Polygon(numberOfVertex, vertex);
    }
};

#endif