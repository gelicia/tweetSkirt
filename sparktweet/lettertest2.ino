// This #include statement was automatically added by the Spark IDE.
#include "neopixel.h"

#define PIXEL_PIN D2
#define PIXEL_TYPE WS2812B

byte all[] = {
//[space]
0000, //0,0,
0000, //0,0,
0000, //0,0,
0000, //0,0,
0000, //0,0,
0000, //0,0,
0000, //0,0,
0000, //0,0,

//!
0002, //1,0,
0002, //1,0,
0002, //1,0,
0002, //1,0,
0002, //1,0,
0000, //0,0,
0002, //1,0,
0000, //0,0,

//"
0012, //0,1,0,1,0,
0012, //0,1,0,1,0,
0024, //1,0,1,0,0,
0000, //0,0,0,0,0,
0000, //0,0,0,0,0,
0000, //0,0,0,0,0,
0000, //0,0,0,0,0,
0000, //0,0,0,0,0,

//#
0024, //0,1,0,1,0,0,
0024, //0,1,0,1,0,0,
0076, //1,1,1,1,1,0,
0024, //0,1,0,1,0,0,
0076, //1,1,1,1,1,0,
0024, //0,1,0,1,0,0,
0024, //0,1,0,1,0,0,
0000, //0,0,0,0,0,0,

//$
0010, //0,0,1,0,0,0,
0036, //0,1,1,1,1,0,
0040, //1,0,0,0,0,0,
0034, //0,1,1,1,0,0,
0002, //0,0,0,0,1,0,
0074, //1,1,1,1,0,0,
0010, //0,0,1,0,0,0,
0000, //0,0,0,0,0,0,

//%
0042, //1,0,0,0,1,0,
0044, //1,0,0,1,0,0,
0004, //0,0,0,1,0,0,
0010, //0,0,1,0,0,0,
0020, //0,1,0,0,0,0,
0022, //0,1,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//&
0010, //0,0,1,0,0,0,
0024, //0,1,0,1,0,0,
0010, //0,0,1,0,0,0,
0032, //0,1,1,0,1,0,
0054, //1,0,1,1,0,0,
0044, //1,0,0,1,0,0,
0032, //0,1,1,0,1,0,
0000, //0,0,0,0,0,0,

//'
0002, //0,1,0,
0002, //0,1,0,
0004, //1,0,0,
0000, //0,0,0,
0000, //0,0,0,
0000, //0,0,0,
0000, //0,0,0,
0000, //0,0,0,

//(
0006, //0,0,1,1,0,
0010, //0,1,0,0,0,
0020, //1,0,0,0,0,
0020, //1,0,0,0,0,
0020, //1,0,0,0,0,
0010, //0,1,0,0,0,
0006, //0,0,1,1,0,
0000, //0,0,0,0,0,

//)
0030, //1,1,0,0,0,
0004, //0,0,1,0,0,
0002, //0,0,0,1,0,
0002, //0,0,0,1,0,
0002, //0,0,0,1,0,
0004, //0,0,1,0,0,
0030, //1,1,0,0,0,
0000, //0,0,0,0,0,

//*
0000, //0,0,0,0,0,
0000, //0,0,0,0,0,
0022, //1,0,0,1,0,
0014, //0,1,1,0,0,
0022, //1,0,0,1,0,
0000, //0,0,0,0,0,
0000, //0,0,0,0,0,
0000, //0,0,0,0,0,

//+
0000, //0,0,0,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0076, //1,1,1,1,1,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,

//,
0000, //0,0,
0000, //0,0,
0000, //0,0,
0000, //0,0,
0000, //0,0,
0002, //1,0,
0002, //1,0,
0002, //1,0,

//-
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0076, //1,1,1,1,1,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,

//.
0000, //0,0,
0000, //0,0,
0000, //0,0,
0000, //0,0,
0000, //0,0,
0002, //1,0,
0002, //1,0,
0000, //0,0,

///
0002, //0,0,0,0,1,0,
0004, //0,0,0,1,0,0,
0004, //0,0,0,1,0,0,
0010, //0,0,1,0,0,0,
0020, //0,1,0,0,0,0,
0020, //0,1,0,0,0,0,
0040, //1,0,0,0,0,0,
0000, //0,0,0,0,0,0,

//0
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0046, //1,0,0,1,1,0,
0052, //1,0,1,0,1,0,
0062, //1,1,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//1
0010, //0,0,1,0,0,0,
0030, //0,1,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0076, //1,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//2
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0014, //0,0,1,1,0,0,
0020, //0,1,0,0,0,0,
0042, //1,0,0,0,1,0,
0076, //1,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//3
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0014, //0,0,1,1,0,0,
0002, //0,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//4
0006, //0,0,0,1,1,0,
0012, //0,0,1,0,1,0,
0022, //0,1,0,0,1,0,
0042, //1,0,0,0,1,0,
0076, //1,1,1,1,1,0,
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//5
0076, //1,1,1,1,1,0,
0040, //1,0,0,0,0,0,
0074, //1,1,1,1,0,0,
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//6
0014, //0,0,1,1,0,0,
0020, //0,1,0,0,0,0,
0040, //1,0,0,0,0,0,
0074, //1,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//7
0076, //1,1,1,1,1,0,
0042, //1,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0004, //0,0,0,1,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0000, //0,0,0,0,0,0,

//8
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//9
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0036, //0,1,1,1,1,0,
0002, //0,0,0,0,1,0,
0004, //0,0,0,1,0,0,
0030, //0,1,1,0,0,0,
0000, //0,0,0,0,0,0,

//:
0000, //0,0,
0002, //1,0,
0002, //1,0,
0000, //0,0,
0000, //0,0,
0002, //1,0,
0002, //1,0,
0000, //0,0,

//;
0000, //0,0,
0002, //1,0,
0002, //1,0,
0000, //0,0,
0000, //0,0,
0002, //1,0,
0002, //1,0,
0002, //1,0,

//<
0002, //0,0,0,1,0,
0004, //0,0,1,0,0,
0010, //0,1,0,0,0,
0020, //1,0,0,0,0,
0010, //0,1,0,0,0,
0004, //0,0,1,0,0,
0002, //0,0,0,1,0,
0000, //0,0,0,0,0,

//=
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0076, //1,1,1,1,1,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0076, //1,1,1,1,1,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,

//>
0020, //1,0,0,0,0,
0010, //0,1,0,0,0,
0004, //0,0,1,0,0,
0002, //0,0,0,1,0,
0004, //0,0,1,0,0,
0010, //0,1,0,0,0,
0020, //1,0,0,0,0,
0000, //0,0,0,0,0,

//?
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0004, //0,0,0,1,0,0,
0010, //0,0,1,0,0,0,
0000, //0,0,0,0,0,0,
0010, //0,0,1,0,0,0,
0000, //0,0,0,0,0,0,

//@
0074, //0,1,1,1,1,0,0,
0102, //1,0,0,0,0,1,0,
0132, //1,0,1,1,0,1,0,
0132, //1,0,1,1,0,1,0,
0136, //1,0,1,1,1,1,0,
0100, //1,0,0,0,0,0,0,
0074, //0,1,1,1,1,0,0,
0000, //0,0,0,0,0,0,0,

//A
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0076, //1,1,1,1,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//B
0074, //1,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0074, //1,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0074, //1,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//C
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//D
0074, //1,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0074, //1,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//E
0076, //1,1,1,1,1,0,
0040, //1,0,0,0,0,0,
0070, //1,1,1,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0076, //1,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//F
0076, //1,1,1,1,1,0,
0040, //1,0,0,0,0,0,
0070, //1,1,1,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0000, //0,0,0,0,0,0,

//G
0036, //0,1,1,1,1,0,
0040, //1,0,0,0,0,0,
0056, //1,0,1,1,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//H
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0076, //1,1,1,1,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//I
0016, //1,1,1,0,
0004, //0,1,0,0,
0004, //0,1,0,0,
0004, //0,1,0,0,
0004, //0,1,0,0,
0004, //0,1,0,0,
0016, //1,1,1,0,
0000, //0,0,0,0,

//J
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//K
0042, //1,0,0,0,1,0,
0044, //1,0,0,1,0,0,
0070, //1,1,1,0,0,0,
0044, //1,0,0,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//L
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0076, //1,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//M
0042, //1,0,0,0,1,0,
0066, //1,1,0,1,1,0,
0052, //1,0,1,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//N
0042, //1,0,0,0,1,0,
0062, //1,1,0,0,1,0,
0052, //1,0,1,0,1,0,
0046, //1,0,0,1,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//O
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//P
0074, //1,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0074, //1,1,1,1,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0000, //0,0,0,0,0,0,

//Q
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0044, //1,0,0,1,0,0,
0032, //0,1,1,0,1,0,
0000, //0,0,0,0,0,0,

//R
0074, //1,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0074, //1,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//S
0036, //0,1,1,1,1,0,
0040, //1,0,0,0,0,0,
0034, //0,1,1,1,0,0,
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//T
0076, //1,1,1,1,1,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0000, //0,0,0,0,0,0,

//U
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//V
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0024, //0,1,0,1,0,0,
0024, //0,1,0,1,0,0,
0010, //0,0,1,0,0,0,
0000, //0,0,0,0,0,0,

//W
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0052, //1,0,1,0,1,0,
0066, //1,1,0,1,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//X
0042, //1,0,0,0,1,0,
0024, //0,1,0,1,0,0,
0010, //0,0,1,0,0,0,
0024, //0,1,0,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//Y
0042, //1,0,0,0,1,0,
0024, //0,1,0,1,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0010, //0,0,1,0,0,0,
0000, //0,0,0,0,0,0,

//Z
0076, //1,1,1,1,1,0,
0002, //0,0,0,0,1,0,
0004, //0,0,0,1,0,0,
0010, //0,0,1,0,0,0,
0020, //0,1,0,0,0,0,
0040, //1,0,0,0,0,0,
0076, //1,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//[
0016, //1,1,1,0,
0010, //1,0,0,0,
0010, //1,0,0,0,
0010, //1,0,0,0,
0010, //1,0,0,0,
0010, //1,0,0,0,
0016, //1,1,1,0,
0000, //0,0,0,0,

/* \ special comment for a special character */
0040, //1,0,0,0,0,0,
0020, //0,1,0,0,0,0,
0020, //0,1,0,0,0,0,
0010, //0,0,1,0,0,0,
0004, //0,0,0,1,0,0,
0004, //0,0,0,1,0,0,
0002, //0,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//]
0016, //1,1,1,0,
0002, //0,0,1,0,
0002, //0,0,1,0,
0002, //0,0,1,0,
0002, //0,0,1,0,
0002, //0,0,1,0,
0016, //1,1,1,0,
0000, //0,0,0,0,

//^
0010, //0,0,1,0,0,0,
0024, //0,1,0,1,0,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,

//_
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0076, //1,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//`
0004, //1,0,0,
0004, //1,0,0,
0002, //0,1,0,
0000, //0,0,0,
0000, //0,0,0,
0000, //0,0,0,
0000, //0,0,0,
0000, //0,0,0,

//a
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0034, //0,1,1,1,0,0,
0002, //0,0,0,0,1,0,
0036, //0,1,1,1,1,0,
0042, //1,0,0,0,1,0,
0036, //0,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//b
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0054, //1,0,1,1,0,0,
0062, //1,1,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0074, //1,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//c
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0040, //1,0,0,0,0,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//d
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0032, //0,1,1,0,1,0,
0046, //1,0,0,1,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0036, //0,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//e
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0076, //1,1,1,1,1,0,
0040, //1,0,0,0,0,0,
0036, //0,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//f
0006, //0,0,1,1,0,
0010, //0,1,0,0,0,
0036, //1,1,1,1,0,
0010, //0,1,0,0,0,
0010, //0,1,0,0,0,
0010, //0,1,0,0,0,
0010, //0,1,0,0,0,
0000, //0,0,0,0,0,

//g
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0036, //0,1,1,1,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0036, //0,1,1,1,1,0,
0002, //0,0,0,0,1,0,
0074, //1,1,1,1,0,0,

//h
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0054, //1,0,1,1,0,0,
0062, //1,1,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//i
0002, //1,0,
0000, //0,0,
0002, //1,0,
0002, //1,0,
0002, //1,0,
0002, //1,0,
0002, //1,0,
0000, //0,0,

//j
0002, //0,0,0,0,1,0,
0000, //0,0,0,0,0,0,
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,

//k
0020, //1,0,0,0,0,
0020, //1,0,0,0,0,
0022, //1,0,0,1,0,
0024, //1,0,1,0,0,
0030, //1,1,0,0,0,
0024, //1,0,1,0,0,
0022, //1,0,0,1,0,
0000, //0,0,0,0,0,

//l
0004, //1,0,0,
0004, //1,0,0,
0004, //1,0,0,
0004, //1,0,0,
0004, //1,0,0,
0004, //1,0,0,
0002, //0,1,0,
0000, //0,0,0,

//m
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0064, //1,1,0,1,0,0,
0052, //1,0,1,0,1,0,
0052, //1,0,1,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//n
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0074, //1,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//o
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0034, //0,1,1,1,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0034, //0,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//p
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0054, //1,0,1,1,0,0,
0062, //1,1,0,0,1,0,
0042, //1,0,0,0,1,0,
0074, //1,1,1,1,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,

//q
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0032, //0,1,1,0,1,0,
0046, //1,0,0,1,1,0,
0042, //1,0,0,0,1,0,
0036, //0,1,1,1,1,0,
0002, //0,0,0,0,1,0,
0002, //0,0,0,0,1,0,

//r
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0054, //1,0,1,1,0,0,
0062, //1,1,0,0,1,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0040, //1,0,0,0,0,0,
0000, //0,0,0,0,0,0,

//s
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0036, //0,1,1,1,1,0,
0040, //1,0,0,0,0,0,
0034, //0,1,1,1,0,0,
0002, //0,0,0,0,1,0,
0074, //1,1,1,1,0,0,
0000, //0,0,0,0,0,0,

//t
0004, //0,1,0,0,
0004, //0,1,0,0,
0016, //1,1,1,0,
0004, //0,1,0,0,
0004, //0,1,0,0,
0004, //0,1,0,0,
0002, //0,0,1,0,
0000, //0,0,0,0,

//u
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0036, //0,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//v
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0024, //0,1,0,1,0,0,
0010, //0,0,1,0,0,0,
0000, //0,0,0,0,0,0,

//w
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0052, //1,0,1,0,1,0,
0052, //1,0,1,0,1,0,
0036, //0,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//x
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0042, //1,0,0,0,1,0,
0024, //0,1,0,1,0,0,
0010, //0,0,1,0,0,0,
0024, //0,1,0,1,0,0,
0042, //1,0,0,0,1,0,
0000, //0,0,0,0,0,0,

//y
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0042, //1,0,0,0,1,0,
0036, //0,1,1,1,1,0,
0002, //0,0,0,0,1,0,
0074, //1,1,1,1,0,0,

//z
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0076, //1,1,1,1,1,0,
0004, //0,0,0,1,0,0,
0010, //0,0,1,0,0,0,
0020, //0,1,0,0,0,0,
0076, //1,1,1,1,1,0,
0000, //0,0,0,0,0,0,

//{
0006, //0,0,1,1,0,
0010, //0,1,0,0,0,
0010, //0,1,0,0,0,
0020, //1,0,0,0,0,
0010, //0,1,0,0,0,
0010, //0,1,0,0,0,
0006, //0,0,1,1,0,
0000, //0,0,0,0,0,

//|
0002, //1,0,
0002, //1,0,
0002, //1,0,
0000, //0,0,
0002, //1,0,
0002, //1,0,
0002, //1,0,
0000, //0,0,

//}
0030, //1,1,0,0,0,
0004, //0,0,1,0,0,
0004, //0,0,1,0,0,
0002, //0,0,0,1,0,
0004, //0,0,1,0,0,
0004, //0,0,1,0,0,
0030, //1,1,0,0,0,
0000, //0,0,0,0,0,

//~
0031, //0,1,1,0,0,1,
0046, //1,0,0,1,1,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
0000, //0,0,0,0,0,0,
};

int lengths[] = {2,2,5,6,6,6,6,3,5,5,5,6,2,6,2,6,6,6,6,6,6,6,6,6,6,6,2,2,5,6,5,6,7,6,6,6,6,6,6,6,6,4,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,4,6,4,6,6,3,6,6,6,6,6,5,6,6,2,6,5,3,6,6,6,6,6,6,6,4,6,6,6,6,6,6,5,2,5,6};

// Number of RGB LEDs in strand:
int LEDsW = 10;
int LEDsH = 8;

//pixel pin is D2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDsW * LEDsH, PIXEL_PIN, PIXEL_TYPE);
String displayString = "hello!";
String displayPlaceholder = displayString;

void setup() {
  Serial.begin(9600);
  Spark.function("changeString", changeString);
  strip.begin();
  strip.show();
}

int changeString(String arg) {
   displayPlaceholder = arg;
}

void loop() {
  scrollImage(displayString, 60);
  if (displayString != displayPlaceholder){
      displayString = displayPlaceholder;
  }
}

void scrollImage(String strIn, int del){
    int maxWidth = 0;
    for (int i = 0; i < strIn.length(); i++){
        char thisChar = strIn.charAt(i);
        maxWidth += lengths[thisChar-32];
    }
    
    //start at the 0th character, on the 0th row
    int charOffset = 0;
    int charColOffset = 0;
    
    for (int column = 0; column < maxWidth; column++){
        char thisChar = strIn.charAt(charOffset);
        
        //draw the window that starts at the charOffset/charColOffset
        //update the display 
        int innerCharOffset = charOffset;
        int innerCharColOffset = charColOffset;
        
        for(int x=0; x<LEDsW; x++){
          char innerThisChar = strIn.charAt(innerCharOffset);
          for(int y=0; y<LEDsH; y++){
            int pixel = getCharPixel(innerThisChar, y, innerCharColOffset);
            setLED(x, y, pixel);
          }
          
          innerCharColOffset++;
          //if the increase in the offset goes beyond the char's length, go up a char and reset the charColOffset to 0;
          if (innerCharColOffset > (lengths[innerThisChar - 32] -1)){
            innerCharOffset++;
                
            if (innerCharOffset > (strIn.length()-1)){
              innerCharOffset = 0;
            }
                
            innerCharColOffset = 0;
          }
        }
        
        charColOffset++;
        //if the increase in the offset goes beyond the char's length, go up a char and reset the charColOffset to 0;
        if (charColOffset > (lengths[thisChar - 32]-1)){
            charOffset++;
            
            if (charOffset > strIn.length()){
                charOffset = 0;
            }
            
            charColOffset = 0;
        }
        
        strip.show();
        delay(del);
    }
    
}

int getCharPixel(char thisChar, int down, int left){
    //If they somehow managed to get a character before the ascii space, make it an ascii space
    if (thisChar < 32){
        thisChar = ' ';
    }
    
    String row = String(all[((thisChar-32)*8)+down], BIN);
    
    int rowLength = row.length();
    int length = lengths[thisChar - 32];
    
    if(rowLength < length && (left < (length - rowLength))){
        return 0;
    }
    else {
        int indexOfPixel = left - (length - rowLength);
        return row.substring(indexOfPixel, indexOfPixel+1).toInt();
    }
    
}

void setLED(uint32_t x, uint32_t y, uint32_t color){
  int ledAddr = (LEDsH * ((LEDsW-1)-x)) + (((x&1)==0)?((LEDsH-1)-y):(y));
  strip.setPixelColor(ledAddr, color==0?color:Wheel(color-1));
}


uint32_t Wheel(uint16_t WheelPos)
{
  byte r, g, b;
  switch(WheelPos / 128)
  {
    case 0:
      r = 127 - WheelPos % 128;   //Red down
      g = WheelPos % 128;      // Green up
      b = 0;                  //blue off
      break; 
    case 1:
      g = 127 - WheelPos % 128;  //green down
      b = WheelPos % 128;      //blue up
      r = 0;                  //red off
      break; 
    case 2:
      b = 127 - WheelPos % 128;  //blue down 
      r = WheelPos % 128;      //red up
      g = 0;                  //green off
      break; 
  }
  return(strip.Color(r,g,b));
}