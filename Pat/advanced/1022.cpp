#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Book
{
    long id_;
    string title_;
    string author_;
    string keywords_;
    string publisher_;
    string pubtime_;
};

map<string, set<long> > queryList1;
map<string, set<long> > queryList2;
map<string, set<long> > queryList3;
map<string, set<long> > queryList4;
map<string, set<long> > queryList5;

int main()
{

    //freopen("1022data.txt", "r", stdin);

    Book book;
    int n;
    string str_n;
    //cin >> n;
    getline(cin, str_n);
    n = atoi(str_n.c_str());
    string tmpid;
    for (int i = 0; i < n; ++i)
    {
        getline(cin, tmpid);
        book.id_ = atol(tmpid.c_str());
        getline(cin, book.title_);
        getline(cin, book.author_);
        getline(cin, book.keywords_);
        getline(cin, book.publisher_);
        getline(cin, book.pubtime_);

#if 0
        cout << "book info begin" << endl;
        cout << book.id_ << endl;
        cout << book.title_ << endl;
        cout << book.author_ << endl;
        cout << book.keywords_ << endl;
        cout << book.publisher_ << endl;
        cout << book.pubtime_ << endl;
        cout << "book info end " << endl;
#endif
        queryList1[book.title_].insert(book.id_);
        queryList2[book.author_].insert(book.id_);
        
        istringstream iss(book.keywords_);
        string word;
        while (iss >> word)
        {
            queryList3[word].insert(book.id_);
        }

        queryList4[book.publisher_].insert(book.id_);
        queryList5[book.pubtime_].insert(book.id_);
    }

#if 0
    cout << "list1 size: " << queryList1.size() << endl;
    for (auto it = queryList1.begin(); it != queryList1.end(); ++it)
    {
        cout << it->first << endl;
    }
#endif

    int m = 0;
    string str_m;
    getline (cin, str_m);
    m = atoi(str_m.c_str());
    //cin >> m;
    string queryInfo;
    for (int i = 0; i < m; ++i)
    {
        getline(cin, queryInfo);
        cout << queryInfo << endl;
        string usefulInfo = queryInfo.substr(3); 
        switch (queryInfo[0])
        {
            case '1': 
                      for (auto it = queryList1[usefulInfo].begin();
                                it != queryList1[usefulInfo].end();
                                ++it)
                      {
                          printf("%07ld\n", *it);
                      }
                      if (queryList1[usefulInfo].size() == 0)
                      {
                          printf("Not Found\n");
                      }
                      break;
            case '2': 
                      for (auto it = queryList2[usefulInfo].begin();
                                it != queryList2[usefulInfo].end();
                                ++it)
                      {
                          printf("%07ld\n", *it);
                      }
                      if (queryList2[usefulInfo].size() == 0)
                      {
                          printf("Not Found\n");
                      }
                      break;
            case '3': 
                      for (auto it = queryList3[usefulInfo].begin();
                                it != queryList3[usefulInfo].end();
                                ++it)
                      {
                          printf("%07ld\n", *it);
                      }
                      if (queryList3[usefulInfo].size() == 0)
                      {
                          printf("Not Found\n");
                      }
                      break;
            case '4': 
                      for (auto it = queryList4[usefulInfo].begin();
                                it != queryList4[usefulInfo].end();
                                ++it)
                      {
                          printf("%07ld\n", *it);
                      }
                      if (queryList4[usefulInfo].size() == 0)
                      {
                          printf("Not Found\n");
                      }
                      break;
            case '5':   
                      for (auto it = queryList5[usefulInfo].begin();
                                it != queryList5[usefulInfo].end();
                                ++it)
                      {
                          printf("%07ld\n", *it);
                      }
                      if (queryList5[usefulInfo].size() == 0)
                      {
                          printf("Not Found\n");
                      }
                      break;
        }
    }

    return 0;
}
