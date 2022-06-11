#include <iostream>
#include <fstream>
#include "generatecsv.h"

using namespace std;

bool jsonToCsv(shared_ptr<Json::Value> jsonInput, const char* input, const char* output)
{
		return true;
}

objects_t jsonToDicts(shared_ptr<Json::Value> jsonInput)
{
		auto objects = objects_t();
		return objects;
}

shared_ptr<lines_t> dictsToCsv(objects_t o)
{
		auto lines = make_shared<lines_t>();
		return lines;
}

int main(int argc, char *argv[])
{
		if(argc != 2)
		{
				cout << "2 arguments required";
				exit(1);
		}

		// json input file pointer
		auto jsonInput = make_shared<Json::Value>();

		auto ok = jsonToCsv(jsonInput, argv[1], argv[2]);
		if(!ok)
		{
				cout << "json to csv failed";
				exit(1);
		}

		auto objects = jsonToDicts(jsonInput);

		auto csv = dictsToCsv(objects);

		ofstream ofs;
		ofs.open(argv[2]);
		for(const auto&e : *csv)
		{
				int len = e.get()->size();
				int counter = 0;
				for(const auto&g : *e)
				{
						// write for all json columns in input json file
						ofs << *g << (counter < len-1?",":"");
						counter++;
				}
				ofs << "\n";
		}
		ofs.close();

		return 0;
}
