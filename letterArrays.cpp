#include "letterArrays.h"

int[] letterArrays::createArray(String inputStr){
	int outArr[];

	//first go through and calculate the length
	//then initialize the array to that length
	//then append the images together

	for (int i = 0; i < inputStr.length; i++) { 
		char thisChar = inputStr.charAt(i) - 33; //first character starts at 33
    int getOffset = getSum(thisChar)
    int getLength = lengths(thisChar)
    
	}
}

int getSum(int idx){
  int sumOut = 0;
  for (int i = 0; i<=idx; i++){
    sumOut += lengths(i)
  }

  return sumOut;
}

byte all[] PROGMEM = {
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

//\
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
} 

int lengths[] = {2,5,6,6,6,6,3,5,5,5,6,2,6,2,6,6,6,6,6,6,6,6,6,6,6,2,2,5,6,5,6,7,6,6,6,6,6,6,6,6,4,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,4,6,4,6,6,3,6,6,6,6,6,5,6,6,2,6,5,3,6,6,6,6,6,6,6,4,6,6,6,6,6,6,5,2,5,6}