//Design, implement, and test a class which represents a rational number . The 𝑛/𝑚 , 𝑚 ≠ 0
//class should provide methods which implement simple arithmetic operations on rational
//numbers (e. g. addition, subtraction, multiplication, division). Implement addition and
//subtraction as standard member methods and multiplication as well as division as friend
//functions. In the main() function write the code that demonstrates the use of the class.

#include <iostream>
#include <cassert>
using namespace std;

class RatNum
{
private:
    int m_n, m_m;

public:
    RatNum() : m_n{0}, m_m{1} {}
    RatNum(int n, int m) : m_n{n}, m_m{m} {assert(m != 0); }

    void show() { cout << m_n << "/" << m_m << endl; }

    void setN(int n) { m_n = n; }
    void setM(int m) { m_m = m; }

    int getN() const { return m_n; }
    int getM() const { return m_m; }

    void addition(RatNum& num) {
        m_m = num.getM() * m_m;
        m_n = num.getN() * m_m + num.getM() * m_n;
    }

    friend void division(){}
    friend void multiplication(){}

    ~RatNum(){}
};

int main(){

    RatNum n1(1, 2);
    RatNum n2(3, 4);

    n1.show();
    //n2.show();


    return 0;
}

