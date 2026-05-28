#include <iostream>
#include <string>

using namespace std;
bool isBuiltInCommand(string command) {
    string arr[3] = {"exit", "echo", "type"};

    for (int i = 0; i < 3; i++) {
      if (command == arr[i])
        return true;
    };

    return false;
}

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    cout << "$ ";
    string input;
    getline(cin, input); 

    if (input == "exit") {
      break;
    } else if (input.substr(0, 5) == "echo ") {
      std::cout << input.substr(5) << std::endl;
    } else if (input.substr(0, 5) == "type ") {
          if (isBuiltInCommand(input.substr(5)))
              cout << input.substr(5) << " is a shell builtin" << endl;
          else
              std::cout << input.substr(5) << ": command not found" << std::endl;
    }
    else {
      std::cout << input << ": command not found" << std::endl;
    }
  }
 }
