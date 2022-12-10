#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  // contents of 3 rucksacsk
  string contents1, contents2, contents3;
  // priority
  int priority = 0, total_priority = 0;

  // read input
  while (!cin.eof()) {
    cin >> contents1;
    cin >> contents2;
    cin >> contents3;

    map<char, int> letters;

    for (string::iterator it = contents1.begin(); it != contents1.end(); it++) {
      letters[*it] = 1;
    }

    for (string::iterator it = contents2.begin(); it != contents2.end(); it++) {
      if (letters[*it] == 1) {
        letters[*it] = 2;
      }
    }

    for (string::iterator it = contents3.begin(); it != contents3.end(); it++) {
      if (letters[*it] == 2) {
        // found same letter in all 3 rucksacks

        letters[*it] = 3;

        // calculating priority of letter
        priority = (int)*it;
        if (isupper(*it)) {
          priority -= 38;
        } else {
          priority -= 96;
        }
        total_priority += priority;
        break;
      }
    }

    cin.get();   // reads in the new line character \n after the input (on the same line)
    cin.peek();  // reads first character of the next line
  }

  cout << "total priority: " << total_priority << endl;
  return 0;
}
