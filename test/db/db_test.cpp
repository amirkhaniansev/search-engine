#include <iostream>
#include <string>

#include "../../include/db.hpp"

void test_add_cache(alita::alita_db& db)
{
    std::wstring link, content, input;

    std::wcout << L"Link : ";
    std::wcin >> link;
    std::wcout << "Content : ";
    std::wcin >> content;

    std::wcout << std::endl;

    int id = db.add_cache(link, content);

    std::wcout << "ID : " << id << std::endl;
}

int main(int argc, char** argv)
{
    alita::db_connection_info info;
    info._host = "tcp://127.0.0.1:3306";
    info._username = "sev";
    info._password = "password";
    info._scheme = "Alita";

    alita::alita_db db(info);

    test_add_cache(db);

    return 0;
}