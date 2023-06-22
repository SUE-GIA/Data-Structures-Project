#ifndef PAIR_H
#define PAIR_H

#include <string>
#include <ostream>

class Pair {
private:
  std::string first;
  std::string second;
  int occurrence;

public:
  Pair() : occurrence(1) {}
  Pair(const std::string& f, const std::string& s) : first(f), second(s), occurrence(1) {}

  std::string getFirst() const {
    return first;
  }

  std::string getSecond() const {
    return second;
  }

  int getOccurrence() const {
    return occurrence;
  }

  void incrementOccurrence() {
    occurrence++;
  }

  bool operator==(const Pair& p) const {
    return (first == p.first && second == p.second);
  }

  bool operator!=(const Pair& p) const {
    return (first != p.first || second != p.second);
  }

  bool operator<(const Pair& p) const {
    return (first < p.first || (first == p.first && second < p.second));
  }

  bool operator>(const Pair& p) const {
    return (first > p.first || (first == p.first && second > p.second));
  }
};

inline std::ostream& operator<<(std::ostream& os, const Pair& p) {
  os << p.getFirst() << " " << p.getSecond() << " (" << p.getOccurrence() << " occurrence(s))";
  return os;
}

#endif //PAIR_H
