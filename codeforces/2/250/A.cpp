#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int alen = (int)a.size() - 2;
	int blen = (int)b.size() - 2;
	int clen = (int)c.size() - 2;
	int dlen = (int)d.size() - 2;
	
	bool great_a = (alen >= 2 * max(blen, max(clen, dlen)) ||
					2 * alen <=  min(blen, min(clen, dlen)) );
	bool great_b = (blen >= 2 * max(alen, max(clen, dlen)) ||
					2 * blen <=  min(alen, min(clen, dlen)) );
	bool great_c = (clen >= 2 * max(blen, max(alen, dlen)) ||
					2 * clen <=  min(blen, min(alen, dlen)) );
	bool great_d = (dlen >= 2 * max(blen, max(clen, alen)) ||
					2 * dlen <=  min(blen, min(clen, alen)) );

	int cnt_great = 0;
	if (great_a) cnt_great++;
	if (great_b) cnt_great++;
	if (great_c) cnt_great++;
	if (great_d) cnt_great++;

	if (cnt_great != 1) cout << "C" << endl;
	else
	{
		if (great_a) cout << "A" << endl;
		else if (great_b) cout << "B" << endl;
		else if (great_c) cout << "C" << endl;
		else cout << "D" << endl;
	}
	return 0;
}
