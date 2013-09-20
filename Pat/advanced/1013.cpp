#include <iostream>
#include <string>
using namespace std;


int main()
{
    int N = 0;
    long M = 0;
    int K = 0;
    cin >> N >> M >> K;
    vector<pair<int, int> > edges(M, pair<int, int>(0, 0));
    for (long i = 0; i < M; ++i)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> checkNodes(K, 0);
    for (int i = 0; i < K; ++i)
    {
        cin >> checkNodes[i];
    }
}
