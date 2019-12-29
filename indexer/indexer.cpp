/**
 * GNU General Public License Version 3.0, 29 June 2007
 * Source file for indexer.
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

#include <unordered_map>

#include "../include/indexer.hpp"

alita::indexer::indexer(std::string subscribe_url, alita::db_connection_info info)
    : _subscriber(subscribe_url), _db(info)
{
    this->_subscriber.subsribe("Link ID");
}

void alita::indexer::start()
{
    auto message = std::string("");
    auto id = 0;

    while(true) {
        try
        {
            message = this->_subscriber.get_message("Link ID");
            std::cerr << "Message From Publisher : " << message << std::endl;
            if(message.empty())
                continue;

            id = std::stoi(message);
            std::cerr << "ID From Publisher : " << id << std::endl;
            if(id == 0)
                continue;
            
            auto cache = this->_db.get_cache_by_id(id);
            std::cerr << "Cache Read..." << std::endl
                      << "ID : " << cache._id << std::endl
                      << "Created : " << cache._created << std::endl
                      << "Modified : " << cache._modified << std::endl
                      << "State : " << cache._process_state << std::endl;
            if(id == 0 || cache._process_state != 0)
                continue;

            this->_db.set_cache_state(id, 1);    
            this->index(cache._link, cache._content);
            this->_db.set_cache_state(id, 2);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }        
    }
}

void alita::indexer::index(std::wstring& link, std::wstring& content)
{
    std::unordered_map<std::wstring, int> words;
    std::wstring word;

    for(auto it = content.begin(); it != content.end(); it++) {
        
    }
    
    for(auto it = words.begin(); it != words.end(); it++) {
        this->_db.add_index(it->first, link, it->second);
    }
}