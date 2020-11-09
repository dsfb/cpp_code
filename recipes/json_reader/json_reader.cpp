/*
/usr/include/yajl/yajl_common.h
/usr/include/yajl/yajl_gen.h
/usr/include/yajl/yajl_parse.h
/usr/include/yajl/yajl_tree.h
/usr/include/yajl/yajl_version.h

to compile this code run
$ inst libyajl-dev
clear && g++ -o app json_reader.cpp -lyajl && ./app && rm -f app
 */

#include <yajl/yajl_gen.h>
#include <yajl/yajl_tree.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <memory>

using namespace std;

std::shared_ptr<std::string> read_text_file(const string file_name)
{
    std::shared_ptr<std::string> contents(new std::string);
    std::ifstream file_reader;

    try
    {
        file_reader.open(file_name, std::ios::in);
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
        return contents;
    }
    if (!file_reader.is_open())
    {
        cout << "the file wasn't open" << endl;
        return contents;
    }

    string line = "";
    // read until the end of a file or an error occurred
    while(std::getline(file_reader, line))
    {
        contents->append(line);
    }

    file_reader.close();
    return contents;
}

#define where() \
    cout << __FILE__ << ':' << __LINE__ << ':' << __func__ << endl; \


string get_string_value_json(yajl_val root_node, const char ** path)
{
    string value = "";
    yajl_val node = yajl_tree_get(root_node, path, yajl_type::yajl_t_string);
    if (YAJL_IS_STRING(node))
        value = node->u.string;
    return value;
}

void read_json()
{
    where();

    std::shared_ptr<string> contents = read_text_file("netmon.state");

    if (contents->empty())
        return;

    yajl_val root_node;
    char error_message[1024] = {'\0'};
    const char* xxx[]  = { "xxx", (const char *) 0 };

    root_node = yajl_tree_parse(contents->c_str(), error_message, sizeof(error_message));

    if (root_node == NULL)
        return;

    xxx = yajl_tree_get(root_node, xxx, yajl_type::yajl_t_string);
    xxx = yajl_tree_get(root_node, xxx, yajl_type::yajl_t_array);

    cout << xxx->u.string << endl;
    cout << xxx->u.array.len << endl;

    if (!YAJL_IS_ARRAY(xxx))
    {
        cout << "no, this is not an array" << endl;
        return;
    }

    list<xxx*> networks;
    for (int i = 0; i < xxx->u.array.len; i++)
    {
        yajl_val networks_item = xxx->u.array.values[i];

        yajl_val ips_array = yajl_tree_get(networks_item, xxx, yajl_type::yajl_t_array);

        if (!YAJL_IS_ARRAY(xxx))
        {
            cout << "this is not an array" << endl;
            return;
        }

        for (int j = 0; j < xxx->u.array.len; j++)
        {
            yajl_val xxx = xxx->u.array.values[j];
            xxx->xxx.push_back(xxx->u.string);
        }
    }

    yajl_tree_free(root_node);
}

int main()
{
    read_json();
    return 0;
}