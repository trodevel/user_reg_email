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

// $Revision: 12160 $ $Date:: 2019-10-11 #$ $Author: serge $

#ifndef USER_REG__USER_REG_EMAIL_H
#define USER_REG__USER_REG_EMAIL_H

#include <memory>               // std::unique_ptr

#include "user_reg/user_reg.h"  // UserReg
#include "utils/EMailSender.h"  // utils::EMailSender
#include "templtext/templ.h"    // templtext::Templ

namespace user_reg_email
{

using user_id_t = user_reg::user_id_t;
using group_id_t = user_reg::group_id_t;

struct Config
{
    std::string     host_name;
    uint32_t        port;
    std::string     username;
    std::string     password;
    std::string     sender_email;
    std::string     sender_name;
    std::string     subject;
    std::string     body_template;
};

class UserRegEmail
{

public:

    UserRegEmail();
    ~UserRegEmail();

    bool init(
            const Config                & config,
            user_reg::UserReg           * user_reg );

    bool register_new_user(
            user_manager::group_id_t    group_id,
            const std::string           & email,
            const std::string           & password_hash,
            user_id_t                   * user_id,
            std::string                 * error_msg );

    bool confirm_registration(
            const std::string           & registration_key,
            std::string                 * error_msg );

private:

    bool send_registration(
            const std::string           & email,
            const std::string           & registration_key,
            std::string                 * error_msg );

private:

    Config                      config_;
    std::unique_ptr<utils::EMailSender> sender_;
    std::unique_ptr<templtext::Templ>   templ_;

    user_reg::UserReg           * user_reg_;
};

} // namespace user_reg_email


#endif // USER_REG__USER_REG_EMAIL_H
