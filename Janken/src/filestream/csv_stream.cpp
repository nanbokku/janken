#include "./csv_stream.h"

#include <fstream>
#include <string>

using namespace std;

bool CsvStream::load(const string& name)
{
	ifstream ifs;
	ifs.open(name + extension, ios::in);

	string line;
	while (std::getline(ifs, line)) {
		auto linevec = split(line, comma);

		csvFile_.push_back(linevec);
	}

	ifs.close();

	return true;
}

bool CsvStream::write(const string& name, const vector<vector<string>>& lines)
{
	ofstream ofs;

	ofs.open(name + extension, ios::trunc);

	for (auto line : lines) {
		for (int i = 0; i < line.size(); i++) {
			ofs << line[i];
			if (i != line.size() - 1) ofs << comma;
		}

		ofs << endl;
	}

	ofs.close();

	return true;
}

vector<string> CsvStream::split(const string& line, const char delimiter)
{
	int first = 0;
	int last = line.find_first_of(delimiter);
	vector<string> result;

	while (first < line.size()) {
		string cell(line, first, last - first);

		result.push_back(cell);

		first = last + 1;
		last = line.find_first_of(delimiter, first);

		if (last == std::string::npos) {
			last = line.size();
		}
	}

	return result;
}

vector<vector<string>> CsvStream::getall()
{
	return csvFile_;
}

vector<string> CsvStream::getline(const int index)
{
	return csvFile_[index];
}