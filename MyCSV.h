#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class CSV_Loader
{
public:
	CSV_Loader(string fn){
		this->fn;
	};
	~CSV_Loader() {
		data.clear();
	};

	bool load();
	bool load(int num);
	void print();
	vector<vector<float>> getData() {
		return this->data;
	}

	
private:
	string fn;
	vector<string> split(string& input, char delimiter);

private:
	vector<vector<float>> data;
	void func(string line);
};


bool CSV_Loader::load()
{
	ifstream ifs(this->fn);
	string line;
	while (getline(ifs, line)) {
		this->func(line);
	}
	return true;
}

inline bool CSV_Loader::load(int num)
{
	ifstream ifs(this->fn);
	string line;
	for (int j = 0; j < num; j++)
	{
		this->func(line);
	}
	return true;
}

void CSV_Loader::func(string line) {
	data.push_back(vector<float>());
	vector<string> strvec = split(line, ',');
	for (int i = 0; i < strvec.size(); i++) {
		data[data.size() - 1].push_back(stof(strvec[i]));
	}
};

vector<string> CSV_Loader::split(string& input, char delimiter) {
	istringstream stream(input);
	string field;
	vector<string> result;
	while (getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

void CSV_Loader::print() {
	for (int i = 0; i < data.size(); i++)
	{
		stringstream ss;
		for (int j = 0; j < data[i].size(); j++)
		{
			ss << data[i][j];
			ss << ', ';
		}
		cout << ss.str() << endl;
	}
}