#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include <cmath>
#include <sstream>
#include <iostream>
class MathVector
{
private:
    int _dim;
    double *_vec;
    void init(int dim, double *v)
    {
        this->_dim = dim;
        this->_vec = new double[this->_dim];
        for (int i = 0; i < this->_dim; i++)
        {
            this->_vec[i] = v[i];
        }
    }

public:
    // Default constructor
    MathVector()
    {
        _dim = 0;
        _vec = nullptr;
    }
    // Constructor
    MathVector(int dim, double *v)
    {
        if (dim < 0)
        {
            throw std::string("undefined.");
        }
        init(dim, v);
    }
    // Copy constructor
    MathVector(const MathVector &v)
    {
        // std::cout << "Copy is called " << std::endl;
        init(v._dim, v._vec);
    }
    // Copy assignment
    MathVector operator=(const MathVector &v)
    {
        if (this != &v)
        {
            if(this->_vec != nullptr){
                delete [] _vec;
            }
            init(v._dim, v._vec);
        }
        return *this;
    }
    /*MathVector w(dim, vec), u, v;
    u = w;
    u = (v = w);
    w = w;*/

    // Destructor
    ~MathVector()
    {
        if(_vec != nullptr){
           delete[] _vec; // avoid memory leak
        }
    }
    // Member function
    double length()
    {
        double result = 0;
        for (int i = 0; i < _dim; i++)
        {
            result += _vec[i] * _vec[i];
        }
        result = sqrt(result);
        return result;
    }
    // Getter
    double at(int index) const
    {
        return _vec[index];
    }
    // Getter
    int dimension() const
    {
        return _dim;
    }

    // Setter
    void setIndex(int index, double input)
    {
        if (index >= _dim)
        {
            throw std::string("undefined.");
        }
        _vec[index] = input;
    }

    MathVector operator+(const MathVector &v) const
    {
        if(this->dimension() == 0){
            return MathVector(v._dim, v._vec);
        }
        if(v.dimension() == 0){
            return MathVector(this->_dim, this->_vec);
        }
        double w[this->dimension()];
        for (int i = 0; i < this->dimension(); i++)
        {
            w[i] = this->at(i) + v.at(i);
        }
        return MathVector(this->dimension(), w);
    }

    MathVector operator-(const MathVector &v) const
    {
        double w[this->dimension()];
        for (int i = 0; i < this->dimension(); i++)
        {
            w[i] = this->at(i) - v.at(i);
        }
        return MathVector(this->dimension(), w);
    }

    MathVector operator/(const double a) const
    {
        double w[this->dimension()];
        for (int i = 0; i < this->dimension(); i++){
            w[i] = this->at(i) / a;
        }
        return MathVector(this->dimension(), w);
    }

    friend std::istream &operator>>( std::istream  &input, MathVector &M ) { 
        input >> M._vec[0] >> M._vec[1];
        return input;            
    }

    std::string toString() const
    {
        std::stringstream ss;
        for(int i = 0; i < _dim; i++){
            ss << _vec[i];
            if(i != _dim - 1){
                ss << " ";
            }            
        }
        return ss.str();
    }
};

class CCWBefore{
private:
    MathVector centroid;
public:
    CCWBefore(const MathVector &v){
        centroid = v;
    }   
    bool operator()(const MathVector &a, const MathVector &b){
        MathVector da = a - centroid;
        MathVector db = b - centroid;
        return (0.5 * (da.at(0) * db.at(1) - da.at(1) * db.at(0)) >= 0.000);
    }
};
#endif