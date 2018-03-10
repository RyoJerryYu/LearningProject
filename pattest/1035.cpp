#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
bool isInsSort(const vector<int>&, const vector<int>&);
vector<int> onceInsSort(const vector<int>&);
vector<int> onceMerSort(const vector<int>&);
int pro1035() {
	int N;
	cin >> N;
	vector<int> oriseq(N), midseq(N), finseq(N);
	for (int& x : oriseq) cin >> x;
	for (int& x : midseq) cin >> x;
	bool typ = isInsSort(oriseq, midseq);
	cout << (typ ? "Insertion Sort" : "Merge Sort") << endl;
	if (typ) finseq = onceInsSort(midseq);
	else finseq = onceMerSort(midseq);
	for (auto i = finseq.begin(); i + 1 < finseq.end(); i++)cout << *i << " ";
	cout << *(finseq.end() - 1) << endl;
	return 0;
}
bool isInsSort(const vector<int>& oriseq, const vector<int>& midseq) {
	auto orip = oriseq.end(), midp = midseq.end();
	while (*(--orip) == *(--midp));
	while (midp != midseq.begin()) {
		if (*midp < *(midp - 1))return false;
		midp--;
	}
	return true;
}
vector<int> onceInsSort(const vector<int>& midseq) {
	auto midp = midseq.begin();
	vector<int> res;
	while (*midp <= *(midp + 1))res.push_back(*(midp++));//res前缀部分有序
	res.push_back(*(midp++));
	res.insert(upper_bound(res.begin(), res.end(), *midp), *midp);//将前缀后第一个元素有序地插入前缀
	midp++;
	const auto mide = midseq.end();
	while (midp != mide)res.push_back(*(midp++));//后缀部分原样插入
	return res;
}
vector<int> onceMerSort(const vector<int>& midseq) {
	vector<int> res;
	auto midp = midseq.begin(), sqend = midseq.end() - 1;
	back_insert_iterator<vector<int> > resbak(res);
	int step = 1, shortest = (int)midseq.size();//shortest即为已合并的长度
	for (midp = midseq.begin(); midp < sqend; midp++) {//`midp<sqend` means `midp+1<end`
		if (*midp <= *(midp + 1)) step++;
		else {
			if (step < shortest) shortest = step;//shortest不包括最后一step
			step = 1;
		}
	}
	step = shortest << 1;//下一轮迭代
	sqend = midseq.end() - step;//then `midp<sqend` means `midp+step<end`
	for (midp = midseq.begin(); midp < sqend; midp += step) {
		merge(midp, midp + shortest, midp + shortest, midp + step, resbak);//不合并最后一step
	}
	if (midp + shortest < midseq.end()) merge(midp, midp + shortest, midp + shortest, midseq.end(), resbak);//合并最后一step
	else copy(midp, midseq.end(), resbak);
	return res;
}
