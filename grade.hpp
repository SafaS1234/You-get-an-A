#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Assignment
{
    public:
       string assignment_name;
       int actual_grade;
};

class Student
{
    public:
       string first_name;
       string last_name;
       string student_ID;
       vector <Assignment> grade;
};

class Gradebook
{
    private:
      vector<Student> student;
      vector<string> assignment_name;
    
    public:
       int points_possible;

       void add_student(string firstName, string lastName, 
                        string studentID)
       {
            Student new_student;

            new_student.first_name = firstName;
            new_student.last_name = lastName;
            new_student.student_ID = studentID;
            new_student.grade = {};

            student.push_back(new_student);
       }

       void add_assignment(string assignmentName, int pointsPossible)
       {
            Assignment new_assignment;

            assignment_name.push_back(assignmentName);

            for(int i = 0; i < student.size(); i++)
            {
                new_assignment.assignment_name = assignmentName;
                new_assignment.actual_grade = pointsPossible;

                vector<Assignment>& student_grade = student[i].grade;
                student_grade.push_back(new_assignment);
            }
       }

       void enter_grade(string firstName, string assignmentName, 
                        int actualGrade)
       {
            for(size_t i = 0; i < student.size(); i++)
            {
                Student& currentStudent = student[i];
                if (currentStudent.first_name == firstName)
                {
                    vector<Assignment>& grades = currentStudent.grade;
                    for(size_t j=0; j <grades.size(); j++)
                    {
                        Assignment& currentAssignment = grades[j];
                        if(currentAssignment.assignment_name == assignmentName)
                        {
                            currentAssignment.actual_grade = actualGrade;
                            return; 
                        }
                    }
                }
            }
    
       }

       string report()
       {
            string message;
            size_t numStudents = student.size();

            for (size_t i = 0; i < student.size(); i++)
            {
                const Student& student1 = student[i];

                message += student1.last_name + ", " + student1.first_name 
                        + ", " + student1.student_ID;

                for (size_t j = 0; j < assignment_name.size(); j++)
                {
                    const string& assignment = assignment_name[j];

                    bool grade_entered = false; 

                    for (size_t k = 0; k < student1.grade.size(); k++)//hererere
                    {
                        const Assignment& assign1 = student1.grade[k];

                        if (assign1.assignment_name == assignment)
                        {
                            message += ", ";
                            message += static_cast<char>(assign1.actual_grade / 10) + '0';
                            message += static_cast<char>(assign1.actual_grade % 10) + '0';
                            grade_entered = true;
                            break;
                        }
                    }

                    if (!grade_entered)
                    {
                        message += ", none";
                    }
                }

                message += "\n";
            }

            return message;
        }

};
