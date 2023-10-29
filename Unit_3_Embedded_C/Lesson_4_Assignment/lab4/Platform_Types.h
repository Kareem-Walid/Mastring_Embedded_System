/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *       FILE NAME ::  Platform_Types.h
 *       AUTHOR: Kareem Walid 
 *       FILE DATE :  15/7/2023
 *       VERSION:   V2.0
 *       BRIEF EXPLANATION: This file containes all platform types for ARM Cortex-M3 and Cortex-M4
 *      
 *********************************************************************************************************************/

/*File Gaurd */
#ifndef  PLATFORM_TYPES_H_
#define  PLATFORM_TYPES_H_

typedef unsigned char boolean;


typedef signed   char          sint8;
typedef unsigned char          uint8;
typedef signed   short         sint16;
typedef unsigned short         uint16;
typedef signed   long          sint32;
typedef unsigned long          uint32;
typedef signed   long long     sint64;
typedef unsigned long long     uint64;
typedef float                  float32;
typedef double                 float64;



typedef volatile signed   char          vsint8;
typedef volatile unsigned char          vuint8;
typedef volatile signed   short         vsint16;
typedef volatile unsigned short         vuint16;
typedef volatile signed   long          vsint32;
typedef volatile unsigned long          vuint32;
typedef volatile signed   long long     vsint64;
typedef volatile unsigned long long     vuint64;


#endif  /* PLATFORM_TYPES_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Platform_Types.h 
 *********************************************************************************************************************/
