/****************************************************************************
**
** Copyright 2019 yanglingwell@sina.com
**
** QQ-Like 自定义的 CheckBox
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
****************************************************************************/
#include "checkbox.h"

#include <QMouseEvent>

namespace qq_like
{
const QString CheckBox::CHECKBOX_NORMAL_ICON_PATHS[2] = {":/loginwnd/checkbox_normal", ":/loginwnd/checkbox_tick_normal"};
const QString CheckBox::CHECKBOX_HOVER_ICON_PATHS[2] = {":/loginwnd/checkbox_hover", ":/loginwnd/checkbox_tick_highlight"};
const QString CheckBox::CHECKBOX_PRESS_ICON_PATHS[2] = {":/loginwnd/checkbox_press", ":/loginwnd/checkbox_tick_pushed"};

CheckBox::CheckBox(bool checked, QWidget *parent) : QWidget(parent), m_isChecked(checked),
    m_leftIcon(nullptr), m_textLabel(nullptr)
{
    m_leftIcon = new QLabel(this);
    m_leftIcon->setPixmap(QPixmap(CHECKBOX_NORMAL_ICON_PATHS[m_isChecked]));
    m_leftIcon->setFixedSize(14, 14);
    m_leftIcon->move(3, 3);

    m_textLabel = new QLabel(this);
    m_textLabel->setStyleSheet("font-size: 12px;font-family:Microsoft YaHei; color: #a6a6a6");
    m_textLabel->setFixedSize(55, 20);
    m_textLabel->move(20, 0);
}

void CheckBox::setText(QString text)
{
    m_textLabel->setText(text);
}

void CheckBox::mousePressEvent(QMouseEvent *event)
{
    m_isChecked = !m_isChecked;
    emit statusChanged(m_isChecked);

    event->accept();
    m_leftIcon->setPixmap(QPixmap(CHECKBOX_PRESS_ICON_PATHS[m_isChecked]));
}

void CheckBox::mouseReleaseEvent(QMouseEvent *event)
{
    event->accept();
    m_leftIcon->setPixmap(QPixmap(CHECKBOX_NORMAL_ICON_PATHS[m_isChecked]));
}

void CheckBox::enterEvent(QEvent *)
{
    m_leftIcon->setPixmap(QPixmap(CHECKBOX_HOVER_ICON_PATHS[m_isChecked]));
}

void CheckBox::leaveEvent(QEvent *)
{
    m_leftIcon->setPixmap(QPixmap(CHECKBOX_NORMAL_ICON_PATHS[m_isChecked]));
}

void CheckBox::changeStatus(bool isChecked)
{
    m_isChecked = isChecked;
    m_leftIcon->setPixmap(QPixmap(CHECKBOX_NORMAL_ICON_PATHS[m_isChecked]));
}
}//namespace qq_like
