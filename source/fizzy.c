/* fizzy.c

MIT License

Copyright (C) 2022 Stefanos "Steven" Tsakiris

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#include <stdio.h>

typedef unsigned int uint;

const char *programName;
const char *string;
uint n;
uint counter;
uint check1;
uint check2;

int main(const int argumentAmount, const char *const *argument){
	programName = *argument;
	if(argumentAmount != 2){
		goto printUsage;
	}
	string = *(argument + 1);
	n = 0;
	getString:{
		if(*string < '0' || *string > '9'){
			goto printUsage;
		}
		n = n * 10 + *string - 48;
		if(*(++string)){
			goto getString;
		}
	}
	if(!n){
		n = 1;
	}
	check1  = 1;
	check2  = 1;
	counter = 1;
	loop:{
		if(check1 == 3){
			fprintf(stdout, "fizz");
			check1 = 0;
		}
		if(check2 == 5){
			fprintf(stdout, "buzz");
			check2 = 0;
		}
		if(check1 && check2){
			fprintf(stdout, "%u", counter);
		}
		fprintf(stdout, "\n");
		if(++counter <= n){
			++check1;
			++check2;
			goto loop;
		}
	}
	return 0;
	printUsage:{
		fprintf(stderr, "%s: usage: %s [n] \n", programName, programName);
		return 1;
	}
}
