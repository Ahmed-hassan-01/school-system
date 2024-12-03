/**
 * File: std_Types.h
 * Author: Eng- Mohamed Mokhtar
 * Group: Online16
 * Date: 2024,Feb
 * Description: This header file defines standard types commonly used in embedded systems.
 *              It includes typedefs for signed and unsigned integers of various sizes,
 *              as well as floating-point numbers with different precision.
 * Version: 1.0
 */

#ifndef __STD_HEADERS_STD_TYPES_H__
#define __STD_HEADERS_STD_TYPES_H__

/* Pointer Typedef *********************************************************************/
#define NULL				((void *)0)
/* Signed Number Typedef ***************************************************************/
typedef signed char 		s8;
typedef signed short int 	s16;
typedef signed long int 	s32;
typedef signed long long	s64;
/* Unsigned Number Typedef *************************************************************/
typedef unsigned char 		u8;
typedef unsigned short int 	u16;
typedef unsigned long int 	u32;
typedef unsigned long long 	u64;
/* Floating-Point Number Typedef *******************************************************/
typedef float 				f32;	// 4_Byte	6  decimal places floating point
typedef double 				f64;	// 8_Byte	14 decimal places floating point
typedef long double 		f96;	// 12_Byte	19 decimal places floating point

/* Casting Typedef *********************************************************************/
typedef signed char 		cast_s8;
typedef signed short int 	cast_s16;
typedef signed long int 	cast_s32;
typedef signed long long	cast_s64;
typedef unsigned char 		cast_u8;
typedef unsigned short int 	cast_u16;
typedef unsigned long int 	cast_u32;
typedef unsigned long long 	cast_u64;
typedef float 				cast_f32;
typedef double 				cast_f64;
typedef long double 		cast_f96;

#endif /* __STD_HEADERS_STD_TYPES_H__ */
