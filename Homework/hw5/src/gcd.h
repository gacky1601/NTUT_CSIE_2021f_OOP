// return the (positive) greatest common divisor of two integers
// a, b may be positive or negative
#ifndef GCD_H
#define GCD_H
using namespace std;
#include <string>
int gcd(int a, int b) {
    if (a==0||b==0){
        throw string ("undefined!");
    }
    a=abs(a);
    b=abs(b);
    while(a!=0 && b!=0){
            a>b? a=a%b: b=b%a;
        }
    return a==0?b:a;
}


#endif