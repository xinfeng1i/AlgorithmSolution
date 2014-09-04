#include <iostream>
#include <string>
#include <vector>
using namespace std;

string to_chinese(char ch)
{
	switch(ch)
	{
		case '0':
			return "ling";
			break;
		case '1':
			return "yi";
			break;
		case '2':
			return "er";
			break;
		case '3':
			return "san";
			break;
		case '4':
			return "si";
			break;
		case '5':
			return "wu";
			break;
		case '6':
			return "liu";
			break;
		case '7':
			return "qi";
			break;
		case '8':
			return "ba";
			break;
		case '9':
			return "jiu";
			break;
	}
}

string read4num(string s)
{
	int pos = 0;
	while (s[pos] == '0') pos++;
	string ans;
	switch(pos)
	{
		case 0:
			ans += to_chinese(s[0]) + " Qian";
			if (s.substr(1)  == "000") return ans;

			if (s[1] == '0') ans += " " + to_chinese('0');
			else ans += " " + to_chinese(s[1]) + " Bai";
			if (s.substr(2) == "00") return ans;

			if (s[1] == '0' && s[2] == '0') ans += "";
			else if (s[1] != '0' && s[2] == '0') ans += " " + to_chinese('0');
			else ans += " " + to_chinese(s[2]) + " Shi";
			if (s.substr(3) == "0") return ans;

			ans += " " + to_chinese(s[3]);
			return ans;
		case 1:
			ans += to_chinese(s[1]) + " Bai";
			if (s.substr(2) == "00") return ans;

			if (s[2] == '0') 
			{
				ans += " ling " + to_chinese(s[3]);
				return ans;
			}
			else 
			{
				ans += " " + to_chinese(s[2]) + " Shi";
				if (s[3] == '0') return ans;
				else
				{
					ans += " " + to_chinese(s[3]);
					return ans;
				}
			}
		case 2:
			if (s[3] == '0')
			{
				ans += to_chinese(s[2]) + " Shi";
			}
			else
			{
				ans += to_chinese(s[2]) + " Shi " + to_chinese(s[3]);
			}
			return ans;
		case 3:
			ans += to_chinese(s[3]);
			return ans;
		default:
			return "Not done";
	}
}


int main()
{
	string s;
	cin >> s;
	bool flag = true;
	if (s[0] == '-')
	{
		flag = false;
		s = s.substr(1);
	}
	
	if (!flag)
	{
		cout << "Fu ";
	}


	if (s.size() <= 4)
	{
		if (s == "0000" || s == "000" || s == "00" || s == "0")
		{
			cout << "ling" << endl;
			return 0;
		}
		else
		{
			while (s.size() < 4) s = "0" + s;
			cout << read4num(s) << endl;
			return 0;
		}
	}
	else if (s.size() <= 8)
	{
		string qian4wei = s.substr(0, s.size() - 4);
		string hou4wei  = s.substr(s.size() - 4);

		if (qian4wei == "0000" || qian4wei == "000" || qian4wei == "00" || qian4wei == "0")
		{
			if (hou4wei == "0000")
			{
				cout << "ling" << endl;
			}
			else
			{
				cout << read4num(hou4wei) << endl;
			}
			return 0;
		}
		else
		{
			string ans;
			while (qian4wei.size() < 4) qian4wei = "0" + qian4wei;
			ans += read4num(qian4wei) + " Wan";
			if (hou4wei == "0000")
			{
                cout << ans << endl;
				return 0;
			}
			else
			{
				int pos = 0;
				while (hou4wei[pos] == '0') pos++;
				if (pos >= 1) ans += " ling";
				ans += " " + read4num(hou4wei);
                cout << ans << endl;
				return 0;
			}
		}
	}
	else if (s.size() <= 9)
	{
        string ans;
        string q4wei = s.substr(0, s.size() - 8);
        string z4wei = s.substr(s.size() - 8, 4);
        string h4wei = s.substr(s.size() - 4, 4);
        if (q4wei == "0000" || q4wei == "000" || q4wei == "00" || q4wei == "0")
        {
            if (z4wei == "0000" && h4wei == "0000")
            {
                cout << "ling" << endl;
                return 0;
            }
            else if (z4wei == "0000" && h4wei != "0000")
            {
                cout << read4num(h4wei) << endl;
                return 0;
            }
            else if (z4wei != "0000" && h4wei == "0000")
            {
                cout << read4num(z4wei) << " Wan" << endl;
                return 0;
            }
            else if (z4wei != "0000" && h4wei != "0000")
            {
                ans += read4num(z4wei) + " Wan";
                int pos = 0; 
                while (h4wei[pos] == '0') pos++;
                if (pos >= 1) ans += " ling";
                ans += " " + read4num(h4wei);
                cout << ans << endl;
                return 0;
            }
        }
        else
        {
            while (q4wei.size() < 4) q4wei = "0" + q4wei;
            ans += read4num(q4wei) + " Yi";
            if (z4wei == "0000" && h4wei == "0000")
            {
                cout << ans << endl;
                return 0;
            }
            else if (z4wei == "0000" && h4wei != "0000")
            {
                ans += " ling";
                ans += " " + read4num(h4wei);
                cout << ans << endl;
                return 0;
            }
            else if (z4wei != "0000" && h4wei == "0000")
            {
                int pos = 0;
                while (z4wei[pos] == '0') pos++;
                if (pos >= 1) ans += " ling";
                ans += " " + read4num(z4wei) + " Wan";
                cout << ans << endl;
                return 0;
            }
            else if (z4wei != "0000" && h4wei != "0000")
            {
                int pos1 = 0;
                while (z4wei[pos1] == '0') pos1++;
                if (pos1 >= 1) ans += " ling";
                ans += " " + read4num(z4wei) + " Wan";
                int pos2 = 0;
                while (h4wei[pos2] == '0') pos2++;
                if (pos2 >= 1) ans += " ling";
                ans += " " + read4num(h4wei);
                cout << ans << endl;
                return 0;
            }
        }
	}

	
}
