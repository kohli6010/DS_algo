#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Solution{
	public:
	vector<int> anagram(const string &str, const string &pattern){
		int matched = 0;
		int windowStart = 0;
		vector<int> resultIndices;
		unordered_map<char, int> characterFrequency;
		for(auto ch:pattern){
			characterFrequency[ch]++;
		}

		for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
			char ch = str[windowEnd];
			auto it = characterFrequency.find(ch);
			if(it != characterFrequency.end()){
				characterFrequency[ch]--;
				if(characterFrequency[ch] == 0){
					matched++;
				}
			}

			if(matched == (int)characterFrequency.size()){
				resultIndices.push_back(windowStart);
			}

			if(windowEnd >= pattern.size() - 1){
				char leftChar = str[windowStart++];
				if(characterFrequency.find(leftChar) != characterFrequency.end()){
					if(characterFrequency[leftChar] == 0){
						matched--;
					}

					characterFrequency[leftChar]++;
				}
			}
		}

		return resultIndices;
	}
};

int main(){
	Solution s;
	auto vec1 = s.anagram("ppqp", "pq");
	auto vec2 = s.anagram("abbcabc", "abc");

	for(auto num:vec1){
		cout << num << " ";
	}

	cout << endl;

	for(auto num:vec2){
		cout << num << " ";
	}

	return 0;
}