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

// $Revision: 13841 $ $Date:: 2020-09-25 #$ $Author: serge $

#include "config_reader/config_reader.h"    // config_reader::ConfigReader
#include "config.h"                         // Config

namespace user_reg_email {

void init_config( Config * cfg, const std::string & section_name, const config_reader::ConfigReader & cr );
void init_credentials( Config * cfg, const std::string & section_name, const config_reader::ConfigReader & cr );

} // namespace user_reg_email
