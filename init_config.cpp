/*

Init Config.

Copyright (C) 2020 Sergey Kolevatov

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

// $Revision: 13844 $ $Date:: 2020-09-26 #$ $Author: serge $

#include "init_config.h"       // self

#include "config_reader/get_value.h"

namespace user_reg_email
{

void init_config( Config * cfg, const std::string & section_name, const config_reader::ConfigReader & cr )
{
    GET_VALUE( cr, cfg, host_name, section_name, true );
    GET_VALUE_CONVERTED( cr, cfg, port, section_name, true );
    GET_VALUE( cr, cfg, subject, section_name, true );
    GET_VALUE( cr, cfg, body_template_filename, section_name, true );
}

void init_credentials( Config * cfg, const std::string & section_name, const config_reader::ConfigReader & cr )
{
    GET_VALUE( cr, cfg, sender_name, section_name, true );
    GET_VALUE( cr, cfg, sender_email, section_name, true );
    GET_VALUE( cr, cfg, username, section_name, true );
    GET_VALUE( cr, cfg, password, section_name, true );
}

} // namespace shopndrop
