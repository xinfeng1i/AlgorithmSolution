#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name_;
    char gender_;
    string id_;
    int grade_;
    
    Student()
    {}

    Student(string name, char gender, string id, int grade):name_(name),
                                                            gender_(gender),
                                                            id_(id),
                                                            grade_(grade)
    {}

    ~Student()
    {}
};

int main()
{
    long long N = 0;
    Student lowestMale("aaa", 'M', "001", 101);
    bool foundMale = false;
    Student highestFemale("bbb", 'F', "002", -1);
    bool foundFemale = false;

    cin >> N;
    string name;
    char gender;
    string id;
    int grade;
    for (long long i = 0; i < N; ++i)
    {
        cin >> name >> gender >> id >> grade;

        if (gender == 'M')
        {
            foundMale = true;
            if (grade < lowestMale.grade_)
            {
                lowestMale.name_ = name;
                lowestMale.id_ = id;
                lowestMale.grade_ = grade;
            }
        }
        else
        {
            foundFemale = true;
            if (grade > highestFemale.grade_)
            {
                highestFemale.name_ = name;
                highestFemale.id_ = id;
                highestFemale.grade_ = grade;
            }
        }
    }

    if (foundMale && foundFemale)
    {
        cout << highestFemale.name_ << " " << highestFemale.id_ << endl;
        cout << lowestMale.name_ << " " << lowestMale.id_ << endl;
        cout << highestFemale.grade_ - lowestMale.grade_ << endl;
    }
    else if (foundFemale && !foundMale)
    {
        cout << highestFemale.name_ << " " << highestFemale.id_ << endl;
        cout << "Absent" << endl;
        cout << "NA" << endl;
    }
    else if (!foundFemale && foundMale)
    {
        cout << "Absent" << endl;
        cout << lowestMale.name_ << " " << lowestMale.id_ << endl;
        cout << "NA" << endl;
    }
    else
    {
        cout << "Absent" << endl;
        cout << "Absent" << endl;
        cout << "NA" << endl;
    }

    return 0;

}
