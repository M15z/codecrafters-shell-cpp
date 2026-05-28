#include <iostream>
#include <string>

using namespace std;
int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    cout << "$ ";
    string prompt;
    cin >> prompt;
    cout << prompt << ": command not found" << endl;
  }
 }
