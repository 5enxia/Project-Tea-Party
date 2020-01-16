#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class CSV
{
private:
	string fn;
	vector <vector<string>> cells;

public:
	CSV() {};
	CSV(string fn) {
		this->fn = fn;
	};
	~CSV() {
		cells.clear();
	};

	void load() {
		_load(this->fn);
	};
	void load(string fn) {
		_load(fn);
	};

	void setCells(vector <vector<string>> cells) {
		this->cells = cells;
	}

	vector <vector<string>> getCells() {
		return cells;
	}

	void write() {
		_write(this->fn);
	};
	void write(string fn) {
		_write(fn);
	};

	void print() {
		for (int i = 0; i < cells.size(); i++) {
			stringstream ss;
			for (int j = 0; j < cells[i].size(); j++) {
				ss << cells[i][j] << ",";
			}
			cout << ss.str() << endl;
		}
	};

private:
	void _load(string fn);
	void _write(string fn);
	vector<string> _split(string& input, char delimiter);
};

void CSV::_load(string fn) {
	ifstream ifs(fn);
	unsigned int count = 0;
	string line;
	while (getline(ifs, line)) {
		cells.push_back(vector<string>());
		vector<string> row = _split(line, ',');
		for (int i = 0; i < row.size(); i++) {
			cells[count].push_back(row[i]);
		}
		count++;
	}
}

inline void CSV::_write(string fn)
{
	ofstream ofs(fn, ios::app);
	for (int i = 0; i < cells.size(); i++) {
		unsigned int len = cells[i].size();
		for (int j = 0; j < len; j++) {
			ofs << cells[i][j];
			if (j != (len - 1)) {
				ofs << ",";
			}
		}
		ofs << endl;
	}
	ofs.close();
}

vector<string> CSV::_split(string& input, char delimiter) {
	istringstream stream(input);
	string field;
	vector<string> row;
	while (getline(stream, field, delimiter)) {
		row.push_back(field);
	}
	return row;
}