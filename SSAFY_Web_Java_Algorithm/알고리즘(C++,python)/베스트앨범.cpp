#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, string>> mapToVec(map<string, int> BG)
{
	vector<pair<int, string>> VbestGenres;
	for (auto elem : BG)
	{
		VbestGenres.push_back(make_pair(elem.second, elem.first));
	}

	return VbestGenres;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> bestGenres;
	vector<pair<int, string>> VbestGenres;
	map<string, vector<pair<int, int>>> idxNplayOfGenres;
	vector<pair<int, int>> playsNIdx;

	for (int i = 0; i < genres.size(); i++)
	{
		if (bestGenres.find(genres[i]) != bestGenres.end())
		{
			bestGenres[genres[i]] += plays[i];
		}
		else
		{
			bestGenres.insert(make_pair(genres[i], plays[i]));
		}

		idxNplayOfGenres[genres[i]].push_back(make_pair(plays[i], i));
	}

	// 여기까지 장르별 총 플레이 수를 알 수 있다.
	// 이때 bestGenres를 sort하면 key값을 기준으로 정렬이 되기때문에 value값을 기준으로 하는 sort가 필요하다
	// 때문에 map을 vector로 옮기는 작업을 해준다.

	VbestGenres = mapToVec(bestGenres);
	sort(VbestGenres.rbegin(), VbestGenres.rend());
	// 베스트 '장르' 순서는 확보됐다.
	// 장르별 인덱스와 플레이횟수가 필요한데 이 중에서도 플레이 횟수에 따른 정렬이 있었음 좋겠다

	for (auto elem : VbestGenres)
	{
		playsNIdx = idxNplayOfGenres[elem.second];
		sort(playsNIdx.rbegin(), playsNIdx.rend());
		
		for (int i = 0; i < playsNIdx.size(); i++)
		{
			if (i == 2)
				break;
			answer.push_back(playsNIdx[i].second);
		}

		if (playsNIdx[0].first == playsNIdx[1].first)
		{
			int temp = answer[answer.size() - 2];
			answer[answer.size() - 2] = answer[answer.size() - 1];
			answer[answer.size() - 1] = temp;
		}
	}
	return answer;
}

int main()
{
	vector<string> genres;
	vector<int> plays;
	
	genres.push_back("classic");   
	genres.push_back("pop");	
	genres.push_back("classic");
	genres.push_back("classic");
	genres.push_back("pop");	
	
	plays.push_back(800);          
	plays.push_back(600);		
	plays.push_back(150);		
	plays.push_back(800);		
	plays.push_back(2500);		

	vector<int> answer = solution(genres, plays);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

}