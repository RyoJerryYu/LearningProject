#include <iostream>
#include <string>
using namespace std;
int pro1024() {
	string sci, res = "";
	cin >> sci;
	int i = 1;
	res += sci[i];
	i = (int)sci.find_first_of('E');
	res += sci.substr(3, i - 3);
	i++;
	int exp = stoi(sci.substr(i));
	if (exp < 0) {
		res.insert(0, "0.");
		exp++;
		res.insert(2, -exp, '0');
	}
	else if (exp < int(res.length()) - 1) {
		res.insert(exp + 1, ".");
	}
	else {
		exp -= (int)res.length() - 1;
		res.append(exp, '0');
	}
	if (sci[0] == '-')cout << '-';
	cout << res << endl;
	return 0;
}