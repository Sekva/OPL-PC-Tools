/***********************************************************************************************
 * Copyright © 2017-2020 Sergey Smolyannikov aka brainstream                                   *
 *                                                                                             *
 * This file is part of the OPL PC Tools project, the graphical PC tools for Open PS2 Loader.  *
 *                                                                                             *
 * OPL PC Tools is free software: you can redistribute it and/or modify it under the terms of  *
 * the GNU General Public License as published by the Free Software Foundation,                *
 * either version 3 of the License, or (at your option) any later version.                     *
 *                                                                                             *
 * OPL PC Tools is distributed in the hope that it will be useful,  but WITHOUT ANY WARRANTY;  *
 * without even the implied warranty of  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *
 * See the GNU General Public License for more details.                                        *
 *                                                                                             *
 * You should have received a copy of the GNU General Public License along with MailUnit.      *
 * If not, see <http://www.gnu.org/licenses/>.                                                 *
 *                                                                                             *
 ***********************************************************************************************/

#ifndef __OPLPCTOOLS_LIBRARY__
#define __OPLPCTOOLS_LIBRARY__

#include <OplPcTools/GameManager.h>
#include <OplPcTools/GameArtManager.h>
#include <OplPcTools/VmcManager.h>

namespace OplPcTools {

class Library final
{
public:
    Library(const QDir & _directory);
    inline const QDir & directory() const;
    bool load(const QDir & _directory);
    inline GameManager * games() const;
    inline GameArtManager * arts() const;
    inline VmcManager * vmcs() const;

private:
    static Library * sp_instance;
    QDir m_directory;
    GameManager * mp_games;
    GameArtManager * mp_game_arts;
    VmcManager * mp_vmcs;
};

const QDir & Library::directory() const
{
    return m_directory;
}

GameManager * Library::games() const
{
    return mp_games;
}

GameArtManager * Library::arts() const
{
    return mp_game_arts;
}

VmcManager * Library::vmcs() const
{
    return mp_vmcs;
}

} // namespace OplPcTools

#endif // __OPLPCTOOLS_LIBRARY__
