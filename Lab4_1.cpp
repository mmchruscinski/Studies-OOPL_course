//Design, implement, and test a class which represents a rational number . 𝑛/𝑚 , 𝑚 ≠ 0
//Implement the following operators: +, -, *, /, <<, >>, ==, !=, <, >. In the main()
//function write the code that demonstrates how these operators work.

#include <iostream>
#include <cassert>
using namespace std;

class RatNum
{
private:
    int m_n, m_m;

public:
    RatNum() : m_n{0}, m_m{1} {}
    RatNum(int n, int m) : m_n{n}, m_m{m} {} //assert(m != 0); }

    void show() { cout << m_n << "/" << m_m << endl; }

    void setN(int n) { m_n = n; }
    void setM(int m) { m_m = m; }

    int getN() const { return m_n; }
    int getM() const { return m_m; }

    friend RatNum operator* (const RatNum& n1, const RatNum& n2);
    friend RatNum operator/ (const RatNum& n1, const RatNum& n2);
    friend RatNum operator+ (const RatNum& n1, const RatNum& n2);
    friend RatNum operator- (const RatNum& n1, const RatNum& n2);
    friend ostream& operator<< (ostream& out, const RatNum& n);
    friend istream& operator>> (istream& in, RatNum& n);

    ~RatNum(){}
};

RatNum operator* (const RatNum& n1, const RatNum& n2){
    return RatNum(n1.m_n * n2.m_n, n1.m_m * n2.m_m);
}
RatNum operator/ (const RatNum& n1, const RatNum& n2){
    return RatNum(n1.m_n * n2.m_m, n1.m_m * n2.m_n);
}
RatNum operator+ (const RatNum& n1, const RatNum& n2){
    return RatNum(n1.m_m * n2.m_n + n2.m_m * n1.m_n, n1.m_m * n2.m_m);
}
RatNum operator- (const RatNum& n1, const RatNum& n2){
    return RatNum(n2.m_m * n1.m_n - n1.m_m * n2.m_n, n1.m_m * n2.m_m);
}
ostream& operator<< (ostream& out, const RatNum& n) {
    out << n.m_n << "/" << n.m_m;
    return out;
}
istream& operator>> (istream& in, RatNum& n) {
    in >> n.m_n;
    in >> n.m_m;
    return in;
}


int main(){

    RatNum n1(1, 2);
    RatNum n2(3, 4);

    n1.show();
    n2.show();

    RatNum n3 = n1 * n2;

    n3.show();

    RatNum n4 = n1 / n2;

    n4.show();

    RatNum n5 = n1 + n2;
    RatNum n6 = n1 - n2;

    n5.show();
    n6.show();

    cout << n6;

    cout << "Enter the rational number: ";
    RatNum n7;
    cin >> n7;
    cout << "You entered: " << n7 << endl;

    return 0;
}

