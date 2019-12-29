/**
 * GNU General Public License Version 3.0, 29 June 2007
 * Test for HTML Parser.
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

#include <string>
#include <iostream>
#include <fstream>

#include "../../include/parser.hpp"

int main(int argc, char** argv)
{
    std::ifstream stream("../parser/content.html");
    std::string html((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

    alita::html_parser parser("spyur.am", html);
    parser.parse();

    auto set = parser.get_links();
    for(auto it = set.begin(); it != set.end(); it++) {
        std::cout << "LINK : " << *it << std::endl;
    }

    auto content = parser.get_content();
    for(auto it = content.begin(); it != content.end(); it++) {
        std::wcout << it->first << L" | " << it->second << std::endl; 
    }

    return 0;
}