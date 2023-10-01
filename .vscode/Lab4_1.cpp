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

    void addition(RatNum *num) {
        m_n = num->getN() * m_m + num->getM() * m_n;
        m_m = num->getM() * m_m;
    }
    void substraction(RatNum *num) {
        m_n = num->getM() * m_n - num->getN() * m_m;
        m_m = num->getM() * m_m;
    }

    friend void multiplication(RatNum *n1, RatNum *n2){
        n1->m_n = n1->m_n * n2->m_n;
        n1->m_m = n1->m_m * n2->m_m;
    }
    friend void division(RatNum *divided, RatNum *divider){
        const int temp = divider->m_m;
        divider->m_m = divider->m_n;
        divider->m_n = temp;
        multiplication(divided, divider);
    }

    ~RatNum(){}
};

int main(){

    RatNum n1(1, 2);
    RatNum n2(3, 4);

    division(&n1, &n2);

    n1.show();
    n2.show();

    return 0;
}
