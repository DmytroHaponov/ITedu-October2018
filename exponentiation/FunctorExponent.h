#ifndef FUNCTOREXPONENT_H
#define FUNCTOREXPONENT_H


class FunctorExponent{
private:
    int m_base;
    int m_power;
    int m_result = m_base;
public:
    FunctorExponent(int base, int power);
    int operator()();
};

#endif // FUNCTOREXPONENT_H
