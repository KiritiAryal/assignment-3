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
  This application is built to encrypt/decrypt a given file using the basic
    ROT13 encryption algorithm then print the newly formed string to stdout.

  This application is for experimentation and testing only. This algorithm
    is an incredibly weak encryption algorithm and should in no way ever
    be used a production environment.
*/

#include <fstream>
#include <iostream>
using namespace std;

string rot13(string input) {
  string output = "";
  for (char c : input) {
    if (isalpha(c)) {
      if (isupper(c)) {
        output += 'A' + ((c - 'A' + 13) % 26);
      } else {
        output += 'a' + ((c - 'a' + 13) % 26);
      }
    } else {
      output += c;
    }
  }
  return output;
}

string decryptFile(string filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    return "Error: Unable to open file " + filename;
  }
  string input = "";
  string line = "";
  while (getline(file, line)) {
    input += line;
  }
  file.close();
  return rot13(input);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
    return 1;
  }
  ifstream inputFile(argv[1]);
  if (!inputFile.is_open()) {
    cout << "Error: Unable to open file " << argv[1] << endl;
    return 1;
  }

  inputFile.close();

  string decryptedText = decryptFile(argv[1]);
  cout << decryptedText << endl;

  return 0;
}