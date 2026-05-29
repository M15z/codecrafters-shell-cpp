#include <iostream>
#include <sstream>
#include <string>
#include <ranges>
#include <string>
#include <unistd.h>

using namespace std;
bool isBuiltInCommand(string command) {
    string arr[3] = {"exit", "echo", "type"};

    for (int i = 0; i < arr->length(); i++) {
      if (command == arr[i])
        return true;
    };

    return false;
}

bool printPathOfCommand(string command) {
  string pathEnv = getenv("PATH");
  stringstream ssPath(pathEnv);

  string path;
  while (getline(ssPath, path, ':')) {
    string fullPath = path + '/' + command;

    if (access(fullPath.c_str(), X_OK) == 0) {
      cout << command << " is " << fullPath << endl;
      return true;
    }
  }

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
          else if(!isBuiltInCommand(input.substr(5))) {
            if (!printPathOfCommand(input.substr(5)))
              std::cout << input.substr(5) << ": not found" << std::endl;

          }

        }
    else {
      std::cout << input << ": command not found" << std::endl;
    }
  }
 }
