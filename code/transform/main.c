/*
  MIT License

  Copyright (c) 2022 Eric Rees, PhD

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
  SOFTWARE.
*/

/*
  This application is built to accept a positive integer and return a number
    between 1 and MAX_NUM based upon the recieved input.

  This application is built as part of a programming exercise and should not
    be utilized in any production environments.
*/

#include <stdio.h>
#include <stdlib.h>

const int MAX_NUM = 71;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <positive number>\n", argv[0]);
    return 1;
  }
  int num = atoi(argv[1]);
  if (num <= 0) {
    printf("Error: Input must be a positive number.\n");
    return 1;
  }
  int result = (num * 2 / 3) % MAX_NUM + 1;
  printf("%d\n", result);
  return 0;
}