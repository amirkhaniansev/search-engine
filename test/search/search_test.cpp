#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

#include "../../include/search.hpp"

int main(int argc, char** argv)
{
    alita::db_connection_info info;
    info._host = "tcp://127.0.0.1:3306";
    info._scheme = "Alita";
    info._username = "sev";
    info._password = "password";
    info._log = true;

    alita::search s(info);
    
    std::wstring input;
    alita::query query;

    try
    {
        std::wcout << L"Search Query : ";
        std::wcin >> input;

        std::wcout << L"Executing Search : " << std::endl; 
        query._query = input;
        query._last_id = 0;
        auto result = s.query(query);
        std::wcout << L"Search Executed..." << std::endl;

        std::wcout << "Reading..." << std::endl;
        for(auto it = result.begin(); it != result.end(); it++) {
            std::wcout << "Index ID : " << it->second._index_id << '\n'
                       << "Frequency : " << it->second._frequency << '\n'
                       << "Page : " << it->second._page << '\n'
                       << "Word : " << it->second._word << '\n'
                       << "Last Indexed : " 
                       << std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().from_bytes(it->second._last_indexed)
                       << '\n';
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
