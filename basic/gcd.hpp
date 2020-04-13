#ifndef __GCD_HPP__
#define __GCD_HPP__ 
#include <iostream> 
// gcd is a funtion to find the largest common division of two positive integral numbers.
typedef unsigned int uint;
uint gcd(uint m, uint n)
{
    
    uint temp;
    if(m<n) std::swap(m, n);
    temp=m%n;
    return temp==0? n: gcd(n, temp);
}
#endif
