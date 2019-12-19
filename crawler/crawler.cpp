/**
 * GNU General Public License Version 3.0, 29 June 2007
 * Source file for crawler.
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

#include "../include/crawler.hpp"
#include "../include/threadpool.hpp"
#include "../include/lqueue.hpp"

alita::crawler::crawler(std::string publish_url) : _publisher(publish_url)
{
    this->_url = publish_url;
    this->_concurrency_level = 1;
    this->_publisher.declare("Link Content");
}

void alita::crawler::set_concurreny_level(const std::size_t& concurrency_level)
{
    if(concurrency_level == 0 || concurrency_level > 32)
        throw std::invalid_argument("Invalid Concurrency Level");

    this->_concurrency_level = concurrency_level;
}

void alita::crawler::set_initial_list(const std::vector<std::string>& links)
{
    if(links.empty())
        throw std::invalid_argument("List of links is empty");

    for(auto it = links.begin(); it != links.end(); it++)
        if(it->size() > 2000)
            throw std::invalid_argument("List of links contains invalid link");

    this->_links = links;
    for(auto it = this->_links.begin(); it != this->_links.end(); it++)
        alita::lqueue::instance().enqueue(*it);
}

void alita::crawler::start()
{
    auto crawl_starter = [](input_t input)
    {
        alita::output_t output;

        try
        {
            while (true)
            {
                
            }            
        }
        catch(const std::exception& e)
        {
            std::string error = "Error";
            std::string exception = e.what();
            std::string overall_error = error + exception;

            output = (alita::output_t)overall_error.c_str();
        }

        return output;        
    };
}