#include "FunctorExponent.h"

FunctorExponent::FunctorExponent(int base, int power)
    :m_base(base),
      m_power(power){}
int::FunctorExponent::operator()(){
    if(m_base == 0){
        return 0;
    }
    else if(m_base < 0){
	return 0;
    }
    else if(m_power <= 0 && m_base <= 0){
	return 0;
    }
    else if(m_base > 0 && m_power < 0){
        return 0;
    }
    else if(m_power == 0 && m_base > 0){
	return 1;
    }
    else{
        for (int i = 1; i < m_power; i++) {
             m_result *= m_base;
        }
        return m_result;
    }
}

