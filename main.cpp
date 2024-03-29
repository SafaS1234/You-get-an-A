#include "grade.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  Gradebook gradebook;

gradebook.add_student("Bob", "Bobberson", "ABC123");
gradebook.add_student("Sam", "Sammerson", "DEF456");
gradebook.add_student("Jess", "Jesserson", "HIJ789");

gradebook.add_assignment("Quiz 1", 100);
gradebook.add_assignment("Lab 1", 50);

gradebook.enter_grade("Sam", "Quiz 1", 95);
gradebook.enter_grade("Bob", "Quiz 1", 85);
gradebook.enter_grade("Jess", "Lab 1", 49);
gradebook.enter_grade("Jess", "Quiz 1", 93);
gradebook.enter_grade("Bob", "Lab 1", 0);

cout << gradebook.report();

}
