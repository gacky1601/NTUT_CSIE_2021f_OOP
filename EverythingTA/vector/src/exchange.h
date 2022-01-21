// void exchange(double &a, double &b) {
//     double temp = a;
//     a = b;
//     b = temp;
// }

// void exchange(int &a, int &b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

template<typename T>  
void exchange(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T, typename Compare> 
void exchange(T &a, T &b, Compare cmp) {
    if(cmp(a, b)) {
        T temp = a;
        a = b;
        b = temp;
    }
}