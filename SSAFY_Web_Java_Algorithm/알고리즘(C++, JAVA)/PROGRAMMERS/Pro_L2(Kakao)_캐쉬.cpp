#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

deque<string> cache;
map<string, int> list;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int len = cities.size();

	if (cacheSize == 0)
	{
		return cities.size() * 5;
	}

	for (int i = 0; i < cities.size(); i++)
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);


	for (int i = 0; i < len; i++)
	{
		if (list[cities[i]] == 0) {
			list[cities[i]] = 1;
			if (cache.size() == cacheSize) {
				string front = cache.front();
				cache.pop_front();
				list[front] = 0;
			}
			cache.push_back(cities[i]);
			answer += 5;
		}
		else {
			deque<string> tempCache;
			while (!cache.empty()) {
				if (cache.front() != cities[i]) {
					tempCache.push_back(cache.front());
				}
				cache.pop_front();
			}
			tempCache.push_back(cities[i]);
			cache = tempCache;
			answer += 1;
		}
	}
	return answer;
}

int main()
{
	int cacheSize = 0;
	//vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork","LA" };
	vector<string> cities = { "Jeju", "Pangyo", "NewYork", "newYork" };

	cout << solution(cacheSize, cities);
	return 0;
}