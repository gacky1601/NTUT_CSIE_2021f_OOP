#ifndef Binary_H
#define Binary_H
#include <string>
#include <vector>
using namespace std;

class Binary
{
public:
    Binary()
    {
        _size=0;
    }
    Binary(int input[], int s)
    {
        for (int i = 0; i < s;i++){
            if(input[i]<0){
                throw string("undefined!");
            }
        }
            _size = s;
        _input = vector<int>(input, input + s);
    }

    Binary(const Binary &b)
    {
        _input = b._input;
        _size = b._size;
    }

    ~Binary() {}

    Binary &operator=(Binary const &b)
    {
        return *this;
    }
    Binary operator+(Binary const &b)
    {
        int result = this->toInt() + b.toInt();
        int size = _size >b._size ? size : b._size;
        int num[size + 1];
        for (int i = size; i >= 0; i--, result >>= 1)
        {
            num[i] = result % 2;
        }
        if(num[0]==1){
            return Binary(num, ++size);
        }
        else{
            int tmp[size];
            for (int i = size - 1; i >= 0;i--){
                tmp[i] = num[i + 1];
            }
            return Binary(num, size);
        }
    }
    Binary operator-(Binary const &b) {
        int result = this->toInt() - b.toInt();
        int size = _size>b._size ? _size : b._size;
        int num[size];
        for (int i = size-1; i >= 0; i--, result >>= 1)
        {
            num[i] = result % 2;
        }

            return Binary(num, size);
    
    }
    Binary operator>>(int a)
    {
        int tmp[_size];
        for (int i = _size - 1; i >= 0; i--)
        {
            tmp[i] = i - a >= 0 ? _input[i - a] : 0;
        }
        // Binary this-> (tmp, _size);
        return Binary (tmp, _size);
    }
    Binary operator<<(int a)
    {
        int tmp[_size];
        for (int i = 0; i<_size ; i--)
        {
            tmp[i] = i + a < _size ? _input[i + a] : 0;
        }
        // Binary this-> (tmp, _size);
        return Binary (tmp, _size);
    }

    void resize(int new_size)
    {
        for (int i = 0; i < new_size - _size; i++)
        {
            _input.insert(_input.begin(), 0);
        }
    }
    void setBit(int pos, int a)
    {
        _input[pos] = a;
    }
    int toInt() const
    {
        int u = 0;
        for (int i = _size - 1, n = 1; i >= 0; i--, n *= 2)
        {
            u = u + (_input[i] * n);
        }
        return u;
    }
    std::string toString() const
    {
        string u ;
        for (int i = 0; i <_size; i++)
        {
            u.push_back(to_string(_input[i])[0]);
        }
        return u;
    }

private:
    vector<int> _input;
    int _size;
};

#endif
