#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct Hog
{
    long galleon_;
    int sickle_;
    int knut_;
};

int main()
{
    Hog a, b, c;
    scanf("%ld.%d.%d", &a.galleon_, &a.sickle_, &a.knut_);
    scanf("%ld.%d.%d", &b.galleon_, &b.sickle_, &b.knut_);

    c.knut_ = a.knut_ + b.knut_;
    c.sickle_ = a.sickle_ + b.sickle_;
    c.galleon_ = a.galleon_ + b.galleon_;

    if (c.knut_ >= 29)
    {
        c.sickle_ += c.knut_ / 29;
        c.knut_ %= 29;
    }

    if (c.sickle_ >= 17)
    {
        c.galleon_ += c.sickle_ / 17;
        c.sickle_ %= 17;
    }

    printf("%ld.%d.%d\n", c.galleon_, c.sickle_, c.knut_);
    return 0;
}

