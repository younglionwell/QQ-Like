/****************************************************************************
**
** Copyright 2019 yanglingwell@sina.com
**
** QQ-Like 登录窗口登录中界面
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
#include "loginwndloginingpage.h"

#include <QTimer>
namespace qq_like
{
LoginWndLoginingPage::LoginWndLoginingPage(QWidget *parent) : QWidget(parent),
    m_loginingLabel(nullptr), m_cancelBtn(nullptr), m_loginingTimer(nullptr)
{
    m_loginingLabel = new QLabel(parent);
    m_loginingLabel->setText(QString::fromLocal8Bit("登录中")+m_points);
    m_loginingLabel->move(168, 175);
    m_loginingLabel->setFixedSize(100, 35);
    m_loginingLabel->setAlignment(Qt::AlignCenter);
    m_loginingLabel->setStyleSheet("font-size: 18px;font-family:Microsoft YaHei; color: #ffffff");

    m_cancelBtn = new QPushButton(parent);
    m_cancelBtn->move(168, 270);
    m_cancelBtn->setFixedSize(100, 35);
    m_cancelBtn->setText(QString::fromLocal8Bit("取消"));
    m_cancelBtn->setStyleSheet("QPushButton{ background-color:rgba(49,195,255,45);border-color:#96d5fd; "
                               "border-width:1px; border-radius:2px; border-style: solid;"
                               "font-size: 16px;font-family:Microsoft YaHei; color: #ffffff}"
                               "QPushButton:hover:!pressed{ background-color:rgba(111,221,255,45);"
                               "border-color:#96d5fd; border-width:1px; border-radius:2px; border-style: solid;}"
                               "QPushButton:hover:pressed{ background-color:rgba(147,238,255,45);border-color:#96d5fd;"
                               "border-width:1px; border-radius:2px; border-style: solid;}");
    QObject::connect(m_cancelBtn, &QPushButton::clicked, this, &LoginWndLoginingPage::cancelButtonClicked);

    m_loginingTimer = new QTimer(this);
    QObject::connect(m_loginingTimer, &QTimer::timeout, this, &LoginWndLoginingPage::changePoints);
    m_loginingTimer->start(1000);
}

void LoginWndLoginingPage::showEvent(QShowEvent *)
{
    if(m_loginingLabel != nullptr)
    {
        m_loginingLabel->show();
    }
    if(m_cancelBtn != nullptr)
    {
        m_cancelBtn->show();
    }
    if(m_loginingTimer != nullptr)
    {
        m_loginingTimer->start(1000);
    }
}

void LoginWndLoginingPage::hideEvent(QHideEvent *)
{
    if(m_loginingLabel != nullptr)
    {
        m_loginingLabel->hide();
    }
    if(m_cancelBtn != nullptr)
    {
        m_cancelBtn->hide();
    }
    if(m_loginingTimer != nullptr)
    {
        m_loginingTimer->stop();
    }
}

void LoginWndLoginingPage::changePoints()
{
    m_points.append('.');
    if(m_points.size() > 3)
    {
        m_points.clear();
    }
    m_loginingLabel->setText(QString::fromLocal8Bit("登录中")+m_points);
}

void LoginWndLoginingPage::cancelButtonClicked(bool)
{
    emit cancelSignal();
}
}//namespace qq_like
