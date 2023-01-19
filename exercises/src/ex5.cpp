#include <iostream>
#include <utility>

enum class Score { A, B, C, D };

void set_score_GSSI_student(const std::string &name, Score score = Score::A);

void set_score_GSSI_student(const std::string &name, Score score) {
  auto student_score = std::make_pair(name, score);
  switch (score) {
  case Score::A:
    std::cout << student_score.first << " scored A\n";
    break;
  default:
    std::cout << "grade not found\n";
  }
}

int main() {
  set_score_GSSI_student("Ermenegildo Bottiglione");
  return EXIT_SUCCESS;
}
