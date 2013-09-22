#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
    string id_;
    int grade_;
    int location_;
    int rank_;
public:
    // constructor
    Student(string name, int marks, int location=0):id_(name),
                                                     grade_(marks),
                                                     location_(location),
                                                     rank_(0)
    {}
    
    // destructor
    ~Student()
    {}

    // overload operator< in order to sort the students
    bool operator<(const Student& other) const;

    friend ostream& operator<<(ostream& os, const Student& s);

    friend istream& operator>>(istream& is, const Student& s);

    inline int getGrade() const
    {
        return grade_;
    }
    inline void setRank(int r)
    {
        rank_ = r;
    }
    
    inline void setLocation(int l)
    {
        location_ = l;
    }
};

// overload operator<
bool Student::operator<(const Student& other) const
{
    if (grade_ > other.grade_)
    {
        return true;
    }
    else if (grade_ < other.grade_)
    {
        return false;
    }
    else
    {
        if (id_ < other.id_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// overload operator<< 
ostream& operator<<(ostream& os, const Student& s)
{
    os << s.id_ << " " << s.grade_ << " " << s.location_;
    return os;
}

istream& operator>>(istream& is, const Student& s)
{
    is >> s.id_ >> s.grade_;
    return is;
}


typedef vector<Student> studentList;
int main()
{
    int N = 0;
    int K = 0;
    cin >> N;
    vector<studentList> allStudents(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> K;
        allStudents[i].resize(K);
        for (int j = 0; j < K; ++j)
        {
            cin >> allStudents[i][j];
            allStudents[i][j].setLocation(i + 1);
        }

    }

    for (int i = 0; i < N; ++i)
    {
        sort(allStudents[i].begin(), allStudents[i].end());
        for (int j = 0; j < allStudents[i].size(); ++j)
        {
            allStudents[i][j].getGrade();
        }
    }
}
