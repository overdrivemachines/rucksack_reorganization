#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  string contents, compartment1, compartment2;
  int contents_length;
  int priority = 0, total_priority = 0;

  // read input
  while (!cin.eof()) {
    cin >> contents;

    map<char, bool> letters;

    contents_length = contents.size();

    compartment1 = contents.substr(0, contents_length / 2);
    compartment2 = contents.substr(contents_length / 2, contents_length / 2);

    // cout << contents << " : " << compartment1 << " - " << compartment2 << " ";

    for (string::iterator it = compartment1.begin(); it != compartment1.end(); it++) {
      letters[*it] = true;
    }

    for (string::iterator it = compartment2.begin(); it != compartment2.end(); it++) {
      if (letters[*it] == true) {
        priority = (int)*it;
        if (isupper(*it)) {
          priority -= 38;
        } else {
          priority -= 96;
        }
        // cout << priority << " ";
        total_priority += priority;
        break;
      }
    }

    // cout << "\n";

    cin.get();   // reads in the new line character \n after the input (on the same line)
    cin.peek();  // reads first character of the next line
  }

  cout << "total priority: " << total_priority << endl;
  return 0;
}
