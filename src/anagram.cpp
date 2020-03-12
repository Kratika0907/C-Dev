#include <vector>
#include<unordered_map>
using namespace std;

const int MAX_CHAR = 26;
void sortString(string s , unordered_map<string,vector<string>>* map) {
	int charCount[MAX_CHAR] = {0};
	for (int i = 0 ; i < s.length() ; ++i) {
		charCount[s[i]-'a']++;
	}
	string ans ="";
	for (int j = 0 ; j < MAX_CHAR ; ++j) {
			while(charCount[j]) {
				ans = ans + char('a'+j);
				charCount[j]--;
			}
	}
	if(map->find(ans) != map->end()) {
		map->at(ans).push_back(s);
	}
	else {
		vector<string> x = {s};
		(*map)[ans] = x;
	}
}

vector<vector<string>> groupAnagrams(vector<string> words) {
  // Write your code here.
	unordered_map<string,vector<string>> map;
	unordered_map<string,vector<string>> :: iterator itr;
	for (auto i : words) {
		sortString(i,&map);
	}
	vector<vector<string>> ans;
	for (itr = map.begin() ; itr != map.end() ; itr++) {
		   ans.push_back(itr->second);
	}
	
	return ans ;
	
  return {};
}
