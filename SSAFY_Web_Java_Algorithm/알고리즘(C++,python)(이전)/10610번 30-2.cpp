//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//
//	string s;
//	cin >> s;
//
//	int n;
//	vector<int> vec;
//	for (int i = 0; i < s.length(); i++) {
//		n = s[i] - '0';
//		vec.push_back(n);
//	}
//
//
//	sort(vec.begin(), vec.end(), greater<int>());
//	if (vec[vec.size() - 1] != 0) {
//		printf("-1\n");
//		return 0;
//	}
//
//	int sum = 0;
//	for (int i = 0; i < vec.size(); i++) {
//		sum += vec[i];
//	}
//
//	if (sum % 3)
//		printf("-1\n");
//	else
//		for (int i = 0; i < vec.size(); i++)
//			printf("%d", vec[i]);
//
//	printf("\n");
//	return 0;
//}