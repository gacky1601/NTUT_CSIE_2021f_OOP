#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include <cmath>

class MathVector
{
private:
    int _dim;
    double *_vec;
    void init(int dim, double* v) {
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
    MathVector& operator=(const MathVector& v) {
        init(v._dim, v._vec);
    }
    // Destructor
    ~MathVector()
    {
        delete[] _vec; //avoid memory leak
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
    double at(int index) const {
        return _vec[index];
    }
    // Getter
    int dimension() const {
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

    MathVector operator+(const MathVector& v) {
        double w[this->dimension()];
        for(int i = 0; i < this->dimension(); i++){
            w[i] = this->at(i) + v.at(i);
        }
        return MathVector(this->dimension(), w);
    }
};

#endif