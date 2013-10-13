#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct cmp_str
{
    bool operator()(const char* a, const char* b) const
    {
        return strcmp(a, b) < 0;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    long n;
    int k;
    //cin >> n >> k;
    scanf("%ld %d", &n, &k);

    map<const char*, long, cmp_str> table;
    //string id;
    char id[19];
    long x;
    for (long i = 0; i < n; ++i)
    {
        //cin >> id >> x;
        scanf("%s %ld", id, &x); 
        if (x < 500)
        {
            x = 500;
        }
        table[id] += x;
    }
#ifdef MYDEBUG
    for (auto it = table.begin(); it != table.end(); ++it)
    {
        printf("%s %ld\n", it->first, it->second);
    }
#endif

    long m;
    //cin >> m;
    scanf("%ld", &m);
    char queryId[19];
    for (long i = 0; i < m; ++i)
    {
        //cin >> id;
        scanf("%s", queryId);
        if (table.count(queryId) != 0)
        {
            //cout << table[id] << endl; 
            printf("%ld\n", table[queryId]);
        }
        else
        {
            //cout << "No Info" << endl;
            printf("No Info\n");
        }
    }

    return 0;
}

// Summary: Not use char* as the map_key
// 1. char* is a address not the content of a string, so if you do like this:
//
//    char name[20];
//    for (int i = 0; i < n; ++i)
//    {
//        scanf("%s %d", name, &k);
//        myMap[name].insert(k);
//    }
//
//    it it WRONG, because every time you put something in name, the address 
//    of name is not changed. the key of map is always the same address, you
//    are inserting value in the same key repeatedlly.
//
//    you can change the way of comparing address, compare the contents the 
//    address pointed to, customize your own compare fuctional object like:
//
//    struct char_cmp
//    {
//        bool operator()(const char* a, const char* b) const
//        {
//            return strcmp(a, b) < 0;
//        }
//    };
//
//    But it still have some problems. See item 2.
//
// 2. the char* will not allocate memory for itself, so you have allocate and
//    dellocate the memory yourself !!!
//
//    char name[20];
//    for (int i = 0; i < n; ++i)
//    {
//        scanf("%s %d", name, &k);
//        myMap[name].insert(k);
//    }
//
//    this time it know to compare the content of the pointer, but, Dude, name
//    has is only one address, first you give a content "hello", second, you
//    give the content "world", it covered "hello". So the comparion always occured 
//    between the "world" and "world".
//
// 3. DO NOT USE char* as the key of map
