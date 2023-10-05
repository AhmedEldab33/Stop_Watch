/*
 * Std_types.h
 *
 *  Created on: Aug 1, 2023
 *      Author: Ahmed Eldab3
 */

#ifndef ATMEGA32_SERVICES_STD_TYPES_H_
#define ATMEGA32_SERVICES_STD_TYPES_H_


typedef    void (*ptr) (void);

/*  Unsigned Type  */

typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned long int   u32;
typedef unsigned long long  u64;


/* Signed Type */

typedef signed char         s8;
typedef signed short int    s16;
typedef signed long int     s32;
typedef signed long long    s64;



/*  Unsigned Type  */

typedef unsigned char*       pu8;
typedef unsigned short int*  pu16;
typedef unsigned long int*   pu32;
typedef unsigned long long*  pu64;


/* Signed Type */

typedef signed char*         ps8;
typedef signed short int*    ps16;
typedef signed long int*     ps32;
typedef signed long long*    ps64;


/*  Float Type */

typedef float              f32;
typedef double             f64;
typedef long double        f128;

/*NULL MACRO */
#define Null				 0


#endif /* ATMEGA32_SERVICES_STD_TYPES_H_ */
