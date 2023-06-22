#include "Functions.h"

void clearLine(string& line) {
  for (unsigned int i = 0; i < line.length(); i++) {
    if (isupper(line[i])) {
      line[i] = tolower(line[i]); // Convert capital letters to lowercase
    } else if (!isalpha(line[i])) {
      line[i] = ' '; // Replace non-alphanumeric characters with spaces
    }
  }

  // Collapse consecutive spaces into a single space
  for (int i = line.length() - 1; i >= 1; i--) {
    if (line[i] == ' ' && line[i - 1] == ' ') {
      line.erase(i, 1);
    }
  }
}
