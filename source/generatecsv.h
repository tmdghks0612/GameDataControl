#include <memory>
#include <json/json.h>

using namespace std;

typedef std::vector<std::pair<string, string>> json_column;

typedef shared_ptr<json_column> object_t;
typedef shared_ptr<std::vector<object_t>> objects_t;
typedef vector<unique_ptr<string>> line_t;
typedef vector<shared_ptr<line_t>> lines_t;


bool jsonToCsv(shared_ptr<Json::Value> jsonInput, const char* input, const char* output);
objects_t jsonToDicts(shared_ptr<Json::Value> jsonInput);
shared_ptr<lines_t> dictsToCsv(objects_t o); 
