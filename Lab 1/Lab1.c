#include <stdio.h>
#include <string.h>
#include "fixed.h"
// const will place these structures in ROM
const struct outTestCase{       // used to test routines
  long InNumber;       // test input number
  char OutBuffer[10];           // Output String  
};
typedef const struct outTestCase outTestCaseType;
outTestCaseType outTests3[16]={ 
{     0,  "  0.00" }, //      0/256 = 0.00  
{     4,  "  0.01" }, //      4/256 = 0.01  
{    10,  "  0.03" }, //     10/256 = 0.03
{   200,  "  0.78" }, //    200/256 = 0.78
{   254,  "  0.99" }, //    254/256 = 0.99
{   505,  "  1.97" }, //    505/256 = 1.97
{  1070,  "  4.17" }, //   1070/256 = 4.17
{  5120,  " 20.00" }, //   5120/256 = 20.00
{ 12184,  " 47.59" }, //  12184/256 = 47.59
{ 26000,  "101.56" }, //  26000/256 = 101.56
{ 32767,  "127.99" }, //  32767/256 = 127.99
{ 32768,  "128.00" }, //  32768/256 = 128
{ 34567,  "135.02" }, //  34567/256 = 135.02
{123456,  "482.25" }, // 123456/256 = 482.25
{255998,  "999.99" }, // 255998/256 = 999.99
{256000,  "***.**" }  // error
};
unsigned int Errors,AnError,Errors1,Errors2;
char Buffer[10];
int BinOutTest(void){
	unsigned int i;
  Errors = 0;
  for(i=0; i<16; i++){
    Fixed_uBinOut8s(outTests3[i].InNumber,Buffer);
    if(strcmp(Buffer, outTests3[i].OutBuffer)){
      Errors++;
      AnError = i;
    }
  }
	return Errors;
}

outTestCaseType outTests1[10] = {
{     1,  "  0.01" }, //   1/100 = 0.01
{  5120,  " 51.20" }, //   5120/100 = 51.20
{ 12184,  "121.84" }, //  12184/100 = 121.84
{ 26000,  "260.00" }, //  26000/100 = 260.00
{ 32767,  "327.67" }, //  32767/100 = 327.67
{ 32768,  "327.68" }, //  32768/100 = 327.68
{ 34567,  "345.67" }, //  34567/100 = 345.67
{ 55555,  "555.55" }, //  55555/100 = 555.55
{ 99999,  "999.99" }, //  99999/100 = 999.99
{100000,  "***.**" }  // error
};
int uDecOut2sTest(void){
	unsigned int k;
	Errors1 = 0;
	for(k=0; k<10; k++){
		Fixed_uDecOut2s(outTests1[k].InNumber, Buffer);
		if(strcmp(Buffer, outTests1[k].OutBuffer)){
			Errors1++;
		}
	}
	return Errors1;
}

outTestCaseType outTests2[10] = {
{     1,  " 0.001" }, //   1/1000 = 0.001
{  5120,  " 5.120" }, //   5120/1000 = 5.120
{ -5120,  "-5.120" }, //  -5120/1000 = -5.120
{  2345,  " 2.345" }, //   2345/1000 = 2.345
{ -2345,  "-2.345" }, //  -2345/1000 = -2.345
{  3232,  " 3.232" }, //   3232/1000 = 3.232
{ -3232,  "-3.232" }, //  -3232/1000 = -3.232
{   123,  " 0.123" }, //   123/1000 = 0.123
{  9999,  " 9.999" }, //  9999/1000 = 9.999
{100000,  "**.***" }  // error
};

int sDecOut3sTest(void){
	unsigned int k;
	Errors2 = 0;
	for(k=0; k<10; k++){
		Fixed_sDecOut3s(outTests2[k].InNumber, Buffer);
		if(strcmp(Buffer, outTests2[k].OutBuffer)){
			Errors2++;
		}
	}
	return Errors2;
}

void main(void){ // possible main program that tests your functions
	int err1 = uDecOut2sTest();
	int err2 = sDecOut3sTest();
	int err3 = BinOutTest();
  for(;;) {} /* wait forever */
}
