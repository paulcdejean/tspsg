/*!
 * \file settingsdialog.h
 * \author Copyright &copy; 2007-2014 Oleksii Serdiuk <contacts[at]oleksii[dot]name>
 *
 *  $Id: $Format:%h %ai %an$ $
 *  $URL: http://tspsg.info/ $
 *
 * \brief Defines SettingsDialog class.
 *
 *  <b>TSPSG: TSP Solver and Generator</b>
 *
 *  This file is part of TSPSG.
 *
 *  TSPSG is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  TSPSG is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with TSPSG.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "globals.h"

#include "ui_settingsdialog.h"

/*!
 * \brief Class for handling Settings Dialog UI and logic.
 * \author Copyright &copy; 2007-2014 Oleksii Serdiuk <contacts[at]oleksii[dot]name>
 */
class SettingsDialog: public QDialog, Ui::SettingsDialog
{
    Q_OBJECT
public:
    SettingsDialog(QWidget *parent = 0);
    bool colorChanged() const;
    bool fontChanged() const;
    qint8 translucencyChanged() const;

private:
    bool _fontChanged;
    bool _colorChanged;
    qint8 _translucency;

    QColor textColor, selColor, altColor, borderColor, bgColor;
    QFont font;

    QSettings *settings;
    QHBoxLayout *layoutCitiesLimit;
#ifndef HANDHELD
    QCheckBox *cbUseTranslucency;
#endif // HANDHELD
    QCheckBox *cbCheck4Updates;
    QSpinBox *spinUpdateCheckInterval;
#ifndef QT_NO_PRINTER
    QCheckBox *cbHQGraph;
#endif
#ifdef Q_OS_WINCE_WM
    QRect currentGeometry;
#elif !defined(HANDHELD)
    QCheckBox *cbSaveState;
    QLabel *imgIcon;
    QFrame *lineVertical;
    QLabel *labelHint;

#ifndef QT_NO_STATUSTIP
    bool event(QEvent *ev);
#endif // QT_NO_STATUSTIP
#endif // Q_OS_WINCE_WM

    void pickColor(QColor &where);
    void setBgColor(QWidget *widget, const QColor &color);

private slots:
    void accept();
    void buttonTextColorClicked();
    void buttonSelectedColorClicked();
    void buttonAlternateColorClicked();
    void buttonBorderColorClicked();
//    void buttonBgColorClicked();
    void buttonFontClicked();
#ifdef Q_OS_WINCE_WM
    void desktopResized(int screen);
    void showEvent(QShowEvent *ev);
#endif // Q_OS_WINCE_WM
    void spinRandMinValueChanged(int val);
};

#endif // SETTINGSDIALOG_H
