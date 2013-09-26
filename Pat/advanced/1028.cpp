#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Student
{
	string id_;
	string name_;
	int grade_;
};


bool compareById(const Student& lhs, const Student& rhs)
{
	return lhs.id_ < rhs.id_;
}

bool compareByName(const Student& lhs, const Student& rhs)
{
	if (lhs.name_ < rhs.name_)
	{
		return true;
	}
	else if(lhs.name_ == rhs.name_)
	{
		return lhs.id_ < rhs.id_;
	}
	else
	{
		return false;
	}
}

bool compareByGrade(const Student& lhs, const Student& rhs)
{
	if (lhs.grade_ < rhs.grade_)
	{
		return true;
	}
	else if (lhs.grade_ == rhs.grade_)
	{
		return lhs.id_ < rhs.id_;
	}
	else
	{
		return false;
	}
}

int main()
{
    ios::sync_with_stdio(false);
	long N = 0;
	int C = 0;
	cin >> N >> C;
	vector<Student> v(N);
	for (long i = 0; i < N; ++i)
	{
		cin >> v[i].id_ >> v[i].name_ >> v[i].grade_;
	}

	switch (C)
	{
		case 1: sort(v.begin(), v.end(), compareById);
				break;
		case 2: sort(v.begin(), v.end(), compareByName);
				break;
		case 3: sort(v.begin(), v.end(), compareByGrade);
				break;
		default: cerr << "Parameter wrong" << endl;
				break; 
	}

	for (long i = 0; i < N; ++i)
	{
		cout << v[i].id_ << " " << v[i].name_ << " " << v[i].grade_ << endl;
		//printf("%s %s %d", v[i].id_, v[i].name_, v[i].grade_);
	}

	return 0;
}
