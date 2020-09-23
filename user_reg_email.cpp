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

// $Revision: 13828 $ $Date:: 2020-09-23 #$ $Author: serge $

#include "user_reg_email.h"             // self

#include "utils/dummy_logger.h"         // dummy_log
#include "utils/utils_assert.h"         // ASSERT
#include "utils/read_text_file.h"       // read_text_file

#define MODULENAME      "UserRegEmail"

#define DEBUG

namespace user_reg_email
{

UserRegEmail::UserRegEmail():
        user_reg_( nullptr )
{
}

UserRegEmail::~UserRegEmail()
{
}

bool UserRegEmail::init(
        const Config            & config,
        user_reg::UserReg       * user_reg )
{
    assert( user_reg );

    config_         = config;
    user_reg_       = user_reg;

    auto body_template = utils::read_text_file( config_.body_template_filename );

    sender_.reset( new utils::EMailSender( config.host_name, config.port, config.username, config.password ) );
    templ_.reset( new templtext::Templ( body_template ) );

    return true;
}

bool UserRegEmail::register_new_user(
        user_reg::group_id_t        group_id,
        const std::string           & email,
        const std::string           & password_hash,
        user_id_t                   * user_id,
        std::string                 * error_msg )
{

    std::string registration_key;

    auto res = user_reg_->register_new_user( group_id, email, password_hash, user_id, & registration_key, error_msg );

    if( res == false )
    {
        dummy_log_error( MODULENAME, "register_new_user: failed - ", * error_msg );
        return false;
    }

    res = send_registration( email, registration_key, error_msg );

    if( res == false )
    {
        dummy_log_error( MODULENAME, "register_new_user: failed to send email - ", * error_msg );
        return false;
    }

    dummy_log_info( MODULENAME, "register_new_user: id %u, registration_key %s, expiration %s (%u)", * user_id, registration_key.c_str() );

    return res;
}

bool UserRegEmail::confirm_registration(
        const std::string           & registration_key,
        std::string                 * error_msg )
{
    dummy_log_trace( MODULENAME, "confirm_registration: registration_key %s", registration_key.c_str() );

    return user_reg_->confirm_registration( registration_key, error_msg );
}

bool UserRegEmail::send_registration(
        const std::string           & email,
        const std::string           & registration_key,
        std::string                 * error_msg )
{
    templtext::Templ::MapKeyValue par =
    {
            { "REGISTRATION_KEY", registration_key }
    };

    auto body = templ_->format( par );

    auto res = sender_->send(
            error_msg,
            utils::EMailSender::EMailWithName{ config_.sender_email, config_.sender_name },
            utils::EMailSender::EMailWithName{ email, "" },
            utils::EMailSender::EMailWithName{ "", "" },
            utils::EMailSender::EMailWithName{ "", "" },
            config_.subject,
            body );

    return res;
}

} // namespace user_reg_email
