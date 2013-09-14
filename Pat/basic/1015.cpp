#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

struct Student
{
public:
    long examId_;
    int character_;
    int ability_;
public:
    // constructor
    Student():examId_(10000000), character_(0), ability_(0)
    {}

    // constructor
    Student(long id, int character, int ability):examId_(id),
                                                 character_(character),
                                                 ability_(ability)
    {}

    // destructor
    ~Student()
    {}

    // overload operator<
    bool operator<(const Student& rhs) const
    {
        if (character_ + ability_ > rhs.character_ + rhs.ability_)
        {
            return true;
        }
        else if (character_ + ability_ == rhs.character_ + rhs.ability_)
        {
            if (character_ > rhs.character_)
            {
                return true;
            }
            else if (character_ < rhs.character_)
            {
                return false;
            }
            else if ( character_ == rhs.character_)
            {
                return examId_ < rhs.examId_;
            }
        }
        else
        {
            return false;
        }
    }
    
    void printStudent() const
    {
        cout << examId_ << " " << character_ << " " << ability_ << endl;
    }
};

int main()
{
    long N = 0;
    int L = 0;
    int H = 0;
#if 1
    ifstream fin("1015data.txt", ios::in);
    if (!fin.is_open())
    {
        cerr << "cannot open" << endl;
        return -1;
    }
#endif
    fin >> N >> L >> H;

    vector<Student> v(N);
    for (long i = 0; i < N; ++i)
    {
        fin >> v[i].examId_ >> v[i].character_ >> v[i].ability_;
    }

    set<Student> v1;
    set<Student> v2;
    set<Student> v3;
    set<Student> v4;
    for (long i = 0; i < N; ++i)
    {
        if (v[i].character_ < L || v[i].ability_ < L)
        {
            continue;
        }

        if (v[i].character_ >= H && v[i].ability_ >= H)
        {
            v1.insert(v[i]);
        }
        else if (v[i].character_ >= H && v[i].ability_ < H)
        {
            v2.insert(v[i]);
        }
        else if (v[i].character_ < H && v[i].ability_ < H 
                                     && v[i].character_ >= v[i].ability_)
        {
            v3.insert(v[i]);
        }
        else
        {
            v4.insert(v[i]);
        }
    }
#if 0
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    sort(v4.begin(), v4.end());
#endif

    long M = v1.size() + v2.size() + v3.size() + v4.size();
    cout << M << endl;
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        it->printStudent();
    }

    for (auto it = v2.begin(); it != v2.end(); ++it)
    {
        it->printStudent();
    }

    for (auto it = v3.begin(); it != v3.end(); ++it)
    {
        it->printStudent();
    }

    for (auto it = v4.begin(); it != v4.end(); ++it)
    {
        it->printStudent();
    }

    return 0;
}
