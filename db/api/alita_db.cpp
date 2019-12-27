/**
 * GNU General Public License Version 3.0, 29 June 2007
 * Header file for database client interface.
 * Copyright (C) <2019>
 *      Authors: <amirkhaniansev>  <amirkhanyan.sevak@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Full notice : https://github.com/amirkhaniansev/search-engine/tree/master/LICENSE
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#include <exception>
#include <locale>
#include <codecvt>

#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include "../../include/db.hpp"

alita::alita_db::alita_db(const alita::db_connection_info& db_connection_info)
{
    if(db_connection_info._host.empty())
        throw std::invalid_argument("Invalid Host.");

    if(db_connection_info._username.empty())
        throw std::invalid_argument("Invalid Username.");

    if(db_connection_info._password.empty())
        throw std::invalid_argument("Invalid Password.");

    if(db_connection_info._scheme.empty())
        throw std::invalid_argument("Invalid Scheme.");

    this->_log = db_connection_info._log;
    this->driver = get_driver_instance();
    this->connection = this->driver->connect(
        db_connection_info._host,
        db_connection_info._username,
        db_connection_info._password);

    this->connection->setSchema(db_connection_info._scheme);  
    this->connection->setAutoCommit(false);
}

alita::alita_db::~alita_db()
{
    delete this->connection;
}

int alita::alita_db::add_cache(std::wstring link, std::wstring content)
{
    int id = 0;
    
    try
    {
        std::unique_ptr<sql::Statement> stmt;
        std::unique_ptr<sql::PreparedStatement> pstmt;
        std::unique_ptr<sql::ResultSet> res;

        stmt.reset(this->connection->createStatement());
        pstmt.reset(this->connection->prepareStatement("CALL usp_AddCache(?, ?, @_linkId)"));

        pstmt->setString(1, std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(link));
        pstmt->setString(2, std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(content));
        
        pstmt->execute();
        pstmt->clearParameters();
        res.reset(pstmt -> getResultSet());
        while(res->next());
        
        res.reset(pstmt->executeQuery("SELECT @_linkId AS Id"));
        while (res->next()) {
            id = std::stoi(res->getString("Id"));   
        }    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return id;
}

void alita::alita_db::log(std::string message)
{
    if(this->_log)
        std::cerr << message << std::endl;
}