/***********************************************************************************************
 *                                                                                             *
 * This file is part of the qpcopl project, the graphical PC tools for Open PS2 Loader.        *
 *                                                                                             *
 * qpcopl is free software: you can redistribute it and/or modify it under the terms of        *
 * the GNU General Public License as published by the Free Software Foundation,                *
 * either version 3 of the License, or (at your option) any later version.                     *
 *                                                                                             *
 * qpcopl is distributed in the hope that it will be useful,  but WITHOUT ANY WARRANTY;        *
 * without even the implied warranty of  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *
 * See the GNU General Public License for more details.                                        *
 *                                                                                             *
 * You should have received a copy of the GNU General Public License along with MailUnit.      *
 * If not, see <http://www.gnu.org/licenses/>.                                                 *
 *                                                                                             *
 ***********************************************************************************************/

#include <atomic>
#include <QObject>
#include "LibCDIO.h"
#include "Exception.h"

void initLibCDIO()
{
    static std::atomic_bool cdio_initialized(false);
    static bool initialization_error = false;
    if(initialization_error)
    {
        goto libcdio_error;
    }
    if(cdio_initialized.exchange(true))
        return;
    if(!cdio_init())
    {
        initialization_error = true;
        goto libcdio_error;
    }
    return;
libcdio_error:
    throw Exception(QObject::tr("libcdio library failed initialization"));
}