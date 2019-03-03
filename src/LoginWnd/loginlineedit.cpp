/****************************************************************************
**
** Copyright 2019 yanglingwell@sina.com
**
** QQ-Like 登录界面的用户名密码输入框
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

#include "loginlineedit.h"

namespace qq_like
{
LoginLineEdit::LoginLineEdit(QWidget *parent) : QWidget(parent), m_lineEdit(nullptr),
    m_leftIcon(nullptr), m_rightIcon(nullptr), m_bottomLine(nullptr)
{
    this->setFixedSize(230, 30);

    m_lineEdit = new LineEditEx(this);
    m_lineEdit->setFixedSize(200, 30);
    m_lineEdit->move(20, 0);
    m_lineEdit->setStyleSheet("border-width:0;border-style:outset");
    QObject::connect(m_lineEdit, &LineEditEx::focusInSignal, this, &LoginLineEdit::focusIn);
    QObject::connect(m_lineEdit, &LineEditEx::focusOutSignal, this, &LoginLineEdit::focusOut);

    m_leftIcon = new QLabel(this);
    m_leftIcon->setFixedSize(12, 16);
    m_leftIcon->move(1, 7);

    m_rightIcon = new QLabel(this);
    m_rightIcon->setFixedSize(12, 16);
    m_rightIcon->move(247, 7);

    m_bottomLine = new QLabel(this);
    m_bottomLine->setFixedSize(230, 2);
    m_bottomLine->move(0, 28);
}

void LoginLineEdit::setLeftIcon(QString leftIconPathNormal, QString leftIconPathHover)
{
    m_leftIconPathNormal = leftIconPathNormal;
    m_leftIconPathHover = leftIconPathHover;

    if(m_leftIcon != nullptr)
    {
        m_leftIcon->setPixmap(QPixmap(m_leftIconPathNormal));
    }
}

void LoginLineEdit::setBottomIcon(QString bottomLinePathNormal, QString bottomLinePathHover)
{
    m_bottomLinePathNormal = bottomLinePathNormal;
    m_bottomLinePathHover = bottomLinePathHover;

    if(m_bottomLine != nullptr)
    {
        m_bottomLine->setPixmap(QPixmap(m_bottomLinePathNormal));
    }
}

void LoginLineEdit::setLineEditStyleSheet(QString styleSheet)
{
    if(m_lineEdit != nullptr)
    {
        m_lineEdit->setStyleSheet(styleSheet);
    }
}

void LoginLineEdit::setPlaceholderText(QString placeholderText)
{
    if(m_lineEdit != nullptr)
    {
        m_lineEdit->setPlaceholderText(placeholderText);
    }
}

void LoginLineEdit::setEchoMode(QLineEdit::EchoMode echoMode)
{
    if(m_lineEdit != nullptr)
    {
        m_lineEdit->setEchoMode(echoMode);
    }
}

QString LoginLineEdit::text() const
{
    return m_lineEdit->text();
}

void LoginLineEdit::focusIn()
{
    if(m_leftIcon != nullptr)
    {
        m_leftIcon->setPixmap(QPixmap(m_leftIconPathHover));
    }
    if(m_bottomLine != nullptr)
    {
        m_bottomLine->setPixmap(QPixmap(m_bottomLinePathHover));
    }
}

void LoginLineEdit::focusOut()
{
    if(m_leftIcon != nullptr)
    {
        m_leftIcon->setPixmap(QPixmap(m_leftIconPathNormal));
    }
    if(m_bottomLine != nullptr)
    {
        m_bottomLine->setPixmap(QPixmap(m_bottomLinePathNormal));
    }
}

} //namespace qq_like
