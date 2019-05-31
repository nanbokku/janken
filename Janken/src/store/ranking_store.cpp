#include "./ranking_store.h"

#include <string>
#include <algorithm>

using namespace std;

RankingStore::RankingStore() : csv_(filename)
{
	ranking_ = csv_.getall();
}

vector<vector<string>> RankingStore::update(const string& name, const int score)
{
	vector<string> data = { name, to_string(score) };

	// ランキングの中でスコアが更新されるものがあるか検索
	auto it = find_if(ranking_.begin(), ranking_.end(), [&](vector<string> line) {
		return data[1] >= line[1];
	});

	if (it == ranking_.end()) return vector<vector<string>>();

	ranking_.insert(it, { name, to_string(score) });

	// ランキング数の制限
	if (ranking_.size() > maxCount && ranking_[ranking_.size() - 1] != ranking_[ranking_.size() - 2]) {
		ranking_.pop_back();
	}

	// ファイルの上書き
	csv_.write(filename, ranking_);

	return ranking_;
}

vector<vector<string>> RankingStore::getall()
{
	return ranking_;
}