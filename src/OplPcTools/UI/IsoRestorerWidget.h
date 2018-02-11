/***********************************************************************************************
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

#ifndef __OPLPCTOOLS_ISORESTORERWIDGET__
#define __OPLPCTOOLS_ISORESTORERWIDGET__

#include <QWidget>
#include <QSharedPointer>
#include <OplPcTools/Core/Game.h>
#include <OplPcTools/UI/Intent.h>
#include "ui_IsoRestorerWidget.h"

namespace OplPcTools {
namespace UI {

class IsoRestorerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit IsoRestorerWidget(QWidget * _parent = nullptr);
    ~IsoRestorerWidget() override;
    void restore(const OplPcTools::Core::Game & _game);

    static QSharedPointer<Intent> createIntent(const OplPcTools::Core::Game & _game);

private:
    Ui::IsoRestorerWidget * mp_ui;
};

} // namespace UI
} // namespace OplPcTools

#endif // __OPLPCTOOLS_ISORESTORERWIDGET__