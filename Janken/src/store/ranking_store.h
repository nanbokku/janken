#pragma once

#include "../filestream/csv_stream.h"

class RankingStore
{
public:
	RankingStore();
	~RankingStore() = default;

	std::vector<std::vector<std::string>> update(const std::string&, int);

private:
	CsvStream csv_;
	std::vector<std::vector<std::string>> ranking_;

	const int maxCount = 10;
	const std::string filename = "ranking";
};