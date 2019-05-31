#include "./ranking_store.h"

#include <string>
#include <algorithm>

using namespace std;

const string RankingStore::filename = "ranking";

RankingStore::RankingStore() : csv_(filename)
{
	ranking_ = csv_.getall();
}

vector<vector<string>> RankingStore::update(const string& name, const int score)
{
	vector<string> data = { name, to_string(score) };

	if (ranking_.size() < maxCount) {
		ranking_.push_back(data);
	}
	else {
		// �����L���O�̒��ŃX�R�A���X�V�������̂����邩����
		auto it = find_if(ranking_.begin(), ranking_.end(), [&](vector<string> line) {
			return score > stoi(line[1]);
		});

		if (it == ranking_.end()) return vector<vector<string>>();

		ranking_.insert(it, data);

		// �����L���O���̐���
		if (ranking_.size() > maxCount && ranking_[ranking_.size() - 1] != ranking_[ranking_.size() - 2]) {
			ranking_.pop_back();
		}
	}

	// �t�@�C���̏㏑��
	csv_.write(filename, ranking_);

	return ranking_;
}

vector<vector<string>> RankingStore::getall()
{
	return ranking_;
}

bool RankingStore::needUpdate(const int score)
{
	if (ranking_.size() < maxCount) return true;

	// �����L���O�̒��ŃX�R�A���X�V�������̂����邩����
	auto it = find_if(ranking_.begin(), ranking_.end(), [&](vector<string> line) {
		return score > stoi(line[1]);
	});

	if (it == ranking_.end()) return false;

	return true;
}