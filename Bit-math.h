#ifndef  BIT_MATH_H
#define  BIT_MATH_H


#define SET_BIT(x,n)     ( x  |=   (1<<n) )
#define CLR_BIT(x,n)     ( x  &=  ~(1<<n) )
#define GET_BIT(x,n)     ( (x >> n) & 0x1 )
#define TOGGLE_BIT(x,n)  ( x  ^= (1 << n) )



#endif
