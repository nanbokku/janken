#pragma once

#include <vector>

class CsvStream
{
public:
	CsvStream() = default;
	CsvStream(const std::string& name)
	{
		load(name);
	}
	~CsvStream() = default;

	bool load(const std::string&);
	bool write(const std::string&, const std::vector<std::vector<std::string>>&);
	std::vector<std::vector<std::string>> getall();
	std::vector<std::string> getline(int);

private:
	std::vector<std::string> split(const std::string&, char);

	std::vector<std::vector<std::string>> csvFile_;
	
	const char comma = ',';
	const std::string extension = ".csv";
};