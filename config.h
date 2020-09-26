/*

User Reg via Email.

Copyright (C) 2019 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 13852 $ $Date:: 2020-09-26 #$ $Author: serge $

#ifndef USER_REG_EMAIL__CONFIG_H
#define USER_REG_EMAIL__CONFIG_H

#include <string>               // std::unique_ptr

namespace user_reg_email
{

struct Config
{
    std::string     host_name;
    uint32_t        port;
    std::string     username;
    std::string     password;
    std::string     sender_email;
    std::string     sender_name;
    std::string     subject;
    std::string     body_template_filename;
};

} // namespace user_reg_email


#endif // USER_REG_EMAIL__CONFIG_H
