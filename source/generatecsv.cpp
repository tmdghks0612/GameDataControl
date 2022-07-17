#include <iostream>
#include <fstream>
#include "generatecsv.h"

using namespace std;

bool jsonToCsv(shared_ptr<Json::Value> jsonInput, const char* input, const char* output)
{
	Json::Reader jsonReader;
	ifstream ifs(input);

	// input file path validation check
	if (ifs.is_open())
	{
		istream& istream = ifs;
		if (false == jsonReader.parse(istream, *jsonInput))
		{
			cout << "[jsonToCsv Fail] jsonReader parse failed" << endl;
			ifs.close();
			return false;
		}
	}
	else
	{
		cout << "[jsonToCsv Fail] no input file path : " << input << endl;
		return false;
	}

	// close file io streams
	ifs.close();
	return true;
}

objects_t jsonToDicts(shared_ptr<Json::Value> jsonInput)
{
	objects_t objects = make_shared<json_column_plist>();
	return objects;
}

shared_ptr<lines_t> dictsToCsv(objects_t o)
{
	auto lines = make_shared<lines_t>();
	return lines;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "2 arguments required. argument count : " << argc << endl;
		exit(1);
	}

	// json input file pointer
	shared_ptr<Json::Value> jsonInput = make_shared<Json::Value>();

	bool ok = jsonToCsv(jsonInput, argv[1], argv[2]);
	if (!ok)
	{
		cout << "json to csv failed";
		exit(1);
	}

	objects_t objects = jsonToDicts(jsonInput);

	shared_ptr<lines_t> csv = dictsToCsv(objects);

	ofstream ofs;
	ofs.open(argv[2]);
	for (const auto& e : *csv)
	{
		int len = e.get()->size();
		int counter = 0;
		for (const auto& g : *e)
		{
			// write for all json columns in input json file
			ofs << *g << (counter < len - 1 ? "," : "");
			counter++;
		}
		ofs << "\n";
	}
	ofs.close();

	return 0;
}
