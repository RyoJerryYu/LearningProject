#include <iostream>
using namespace std;
struct stu {
	int id, de, cai;
};
void sortres(stu* res, int lo, int hi) {
	if (hi - lo<2)return;
	int mi = (lo + hi) >> 1;//归并排序
	sortres(res, lo, mi);
	sortres(res, mi, hi);
	stu* before = new stu[mi - lo];
	int i = 0, j = mi, k = lo;
	for (; i<(mi - lo); i++) {
		before[i] = res[i + lo];
	}
	i = 0;
	while (i<(mi - lo) && j<hi) {
		if ((before[i].de + before[i].cai)>(res[j].de + res[j].cai)) {
			res[k] = before[i];
			k++; i++;
		}
		else if ((before[i].de + before[i].cai)<(res[j].de + res[j].cai)) {
			res[k] = res[j];
			k++; j++;
		}
		else {
			if (before[i].de>res[j].de) {
				res[k] = before[i];
				k++; i++;
			}
			else if (before[i].de<res[j].de) {
				res[k] = res[j];
				k++; j++;
			}
			else {
				if (before[i].id<res[j].id) {
					res[k] = before[i];
					k++; i++;
				}
				else {
					res[k] = res[j];
					k++; j++;
				}
			}
		}
	}
	while (i<(mi - lo)) {
		res[k] = before[i];
		k++; i++;
	}
	delete[] before;
}
int pro1005() {
	int N = 0, L = 60, H = 60;
	int M = 0;
	int i, j = 0, k = 0;
	cin >> N >> L >> H;
	stu* student = new stu[N];
	stu* result = new stu[N];
	for (i = 0; i<N; i++) {
		cin >> student[i].id >> student[i].de >> student[i].cai;
	}
	for (i = 0; i<N; i++) {//德才全尽
		if (student[i].de >= H && student[i].cai >= H) {
			result[j] = student[i];
			j++; M++;
		}
	}
	sortres(result, k, j);
	k = j;
	for (i = 0; i<N; i++) {//德胜才
		if (student[i].de >= H && L <= student[i].cai && student[i].cai <H) {
			result[j] = student[i];
			j++; M++;
		}
	}
	sortres(result, k, j);
	k = j;
	for (i = 0; i<N; i++) {//才德兼亡
		if (L <= student[i].de && student[i].de<H && L <= student[i].cai && student[i].cai <= student[i].de) {
			result[j] = student[i];
			j++; M++;
		}
	}
	sortres(result, k, j);
	k = j;
	for (i = 0; i<N; i++) {//才胜德
		if (L <= student[i].de && student[i].de < student[i].cai && student[i].de<H) {
			result[j] = student[i];
			j++; M++;
		}
	}
	sortres(result, k, j);
	cout << M << endl;
	for (i = 0; i<j; i++) {
		cout << result[i].id << " " << result[i].de << " " << result[i].cai << endl;
	}
	delete[] student;
	delete[] result;
	return 0;
}