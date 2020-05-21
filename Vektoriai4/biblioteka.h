#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <iterator>
#include "vector.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::sort;
using std::setprecision;
using std::setw;
using std::left;

class Person
{

protected:
    string Name_;
    string Surname_;

public:
    Person(string, string);
    Person();
    ~Person();
    virtual void setName(string) = 0;
    virtual void setSurname(string) = 0;
    string getName() const;
    string getSurname() const;
};

class Student: public Person
{

public:
    Student();
    ~Student();
    void setName(string);
    void setSurname(string);
    void setHomework(vector <double>);
    void setExam(int);
    string getName() const;
    string getSurname() const;
    int getExam() const;
    double getFinalMedian() const;
    double getFinalAverange() const;
    Student& operator=(const Student& stud);
    bool operator<(const Student& s2);		//lyginami studentu vardai ir pavardes
    bool operator>(const Student& s2);
    bool operator!=(const Student& s2);
    bool operator==(const Student& s2);
    void Calculation();
    Student(const Student&);
private:
    vector<double> Homework;
    int Exam;
    double Averange;
    double Median;
    double FMedian;
    double FAverange;
};
void GenerateFiles (std::size_t i);
void Filereading(vector<Student>& Stud, string filename);
void DataImport(vector <Student>& Stud);
void Calculations(vector <Student>& Stud);
bool Failed1(Student& Stud);
bool Failed2(Student& Stud);
void GenerateOutputFiles (vector <Student>& Stud, vector <Student>& Failed, vector <Student>& Passed, int t);
void Print(vector <Student>& Stud, int t, string text);
bool Digits (const std::string & str);
int Choice();
bool IfPassed (double averange);
bool IfFailed (double averange);
double FinalResult (double averange, int exam);
