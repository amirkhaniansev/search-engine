/**
 * GNU General Public License Version 3.0, 29 June 2007
 * Implementation for HTTP(S) client.
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

#include <stdexcept>
#include <iostream>
#include <string>

#include "../include/httpsc.hpp"

std::string se::httpsc::get(const std::string url)
{
    std::string base = url.substr(4, url.length() - 4);
    auto response = base[0] != 's'  
        ? httplib::Client(base.substr(4, base.length() - 4).c_str(), 80).Get("/")
        : httplib::SSLClient(base.substr(3, base.length() - 3).c_str(), 443).Get("/");

    if(response->status != 200)
        throw std::runtime_error("Invalid status...");

    return response->body;
}