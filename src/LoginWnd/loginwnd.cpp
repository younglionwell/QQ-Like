/****************************************************************************
**
** Copyright 2019 yanglingwell@sina.com
**
** QQ-Like 登录界面窗体
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

#include "loginwnd.h"
#include <QBitmap>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <QtMath>

namespace qq_like
{

const QString LoginWnd::LW_BACKGOUND_PREFIX = ":/loginwnd/login_bkg_";
const quint8 LoginWnd::LW_BACKGOUND_NUM     = 5;

LoginWnd::LoginWnd(QWidget *parent) : WindowBase(parent), m_bkgOpacity(0),
    m_bkgOpacityInterval(0.005), m_currentBkgIdx(0), m_increasing(true), m_bkgTimer(nullptr),
    m_menuCloseBtn(nullptr), m_menuMinBtn(nullptr), m_headLabel(nullptr), m_mainPage(nullptr),
    m_loginingPage(nullptr), m_currentPage(LWPT_MAINPAGE)
{
    this->setFixedSize(430, 330);
    this->setWindowFlags(Qt::FramelessWindowHint);

    m_menuCloseBtn = new QPushButton(this);
    m_menuCloseBtn->setFlat(true);
    m_menuCloseBtn->setFixedSize(30, 32);
    m_menuCloseBtn->move(400, 0);
    m_menuCloseBtn->setStyleSheet("QPushButton{ border-image: url(:/loginwnd/close_normal); }"
                                  "QPushButton:hover:!pressed{ border-image: url(:/loginwnd/close_hover); }"
                                  "QPushButton:hover:pressed{ border-image: url(:/loginwnd/close_press); border-style:none; }");
    QObject::connect(m_menuCloseBtn, &QPushButton::pressed, this, &LoginWnd::close);

    m_menuMinBtn = new QPushButton(this);
    m_menuMinBtn->setFlat(true);
    m_menuMinBtn->setFixedSize(30, 32);
    m_menuMinBtn->move(370, 0);
    m_menuMinBtn->setStyleSheet("QPushButton{ border-image: url(:/loginwnd/min_normal); }"
                                "QPushButton:hover:!pressed{ border-image: url(:/loginwnd/min_hover); }"
                                "QPushButton:hover:pressed{ border-image: url(:/loginwnd/min_press); border-style:none; }");
    QObject::connect(m_menuMinBtn, &QPushButton::pressed, this, &LoginWnd::showMinimized);

    m_headLabel = new HeadLabel(this, ":/loginwnd/defalut_head", ":/loginwnd/head_bkg_shadow", ":/loginwnd/head_bkg_highlight");
    m_headLabel->setFixedSize(98, 98);
    m_headLabel->move(166, 75);

    m_mainPage = new LoginWndMainPage(this);
    m_loginingPage = new LoginWndLoginingPage(this);

    m_bkgTimer = new QTimer(this);
    QObject::connect(m_bkgTimer, &QTimer::timeout, this, &LoginWnd::changeBackground);
    m_bkgTimer->start(10);

    QObject::connect(m_mainPage, &LoginWndMainPage::loginSignal, this, &LoginWnd::loginButtonPressed);
    QObject::connect(m_loginingPage, &LoginWndLoginingPage::cancelSignal, this, &LoginWnd::cancelButtonPressed);
    QObject::connect(this, &LoginWnd::notifyMsgSignal, m_mainPage, &LoginWndMainPage::showNotifyMsg);
    QObject::connect(this, &LoginWnd::hideNotifyMsgSignal, m_mainPage, &LoginWndMainPage::hideNotifyMsg);
}

void LoginWnd::paintEvent(QPaintEvent *event)
{
    qint8 nextBkgIdx = getNextBkgIdx();
    paintBackground(m_currentBkgIdx, 1);
    paintBackground(nextBkgIdx, m_bkgOpacity);

    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/loginwnd/logo-QQ"));
    if(m_currentPage == LWPT_MAINPAGE)
    {
        painter.drawPixmap(0, 130, QPixmap(":/loginwnd/bk_shadow"));
    }

    this->paintEventForRoundAndBorder(2, 1);
    WindowBase::paintEvent(event);
}

void LoginWnd::showEvent(QShowEvent *event)
{
    this->changeLoginWndPage(m_currentPage);
    return WindowBase::showEvent(event);
}

void LoginWnd::changeBackground()
{
    m_bkgOpacity = m_bkgOpacity + m_bkgOpacityInterval;
    if(m_bkgOpacity > 1.0)
    {
        m_currentBkgIdx = getNextBkgIdx();
        m_bkgOpacity = 0;
    }

    this->update();
}

void LoginWnd::changeLoginWndPage(LoginWnd::LoginWndPageType pageType)
{
    m_currentPage = pageType;

    if(m_currentPage == LWPT_MAINPAGE)
    {
        m_mainPage->show();
        m_loginingPage->hide();
        m_headLabel->move(166, 75);
    }
    else if(m_currentPage == LWPT_LOGINING)
    {
        m_mainPage->hide();
        m_loginingPage->show();
        m_headLabel->move(166, 90);
    }
}

void LoginWnd::loginButtonPressed()
{
    if(m_mainPage->getUserName().isEmpty() == true)
    {
        emit notifyMsgSignal(QString::fromLocal8Bit("注意: 请您输入用户名后再登录"));
    }
    else if(m_mainPage->getPassword().isEmpty() == true)
    {
        emit notifyMsgSignal(QString::fromLocal8Bit("注意: 请您输入密码后再登录"));
    }
    else
    {
        this->changeLoginWndPage(LWPT_LOGINING);
    }
}

void LoginWnd::cancelButtonPressed()
{
    this->changeLoginWndPage(LWPT_MAINPAGE);
}

qint8 LoginWnd::getNextBkgIdx()
{
    qint8 nextBkgIdx = m_currentBkgIdx;
    if(m_increasing == true)
    {
        if(++nextBkgIdx >= LW_BACKGOUND_NUM && m_currentBkgIdx-1 >= 0)
        {
            m_increasing = false;
            nextBkgIdx = m_currentBkgIdx-1;
        }
    }
    else if(m_increasing == false)
    {
        if(--nextBkgIdx  < 0 && m_currentBkgIdx+1 < LW_BACKGOUND_NUM)
        {
            m_increasing = true;
            nextBkgIdx = m_currentBkgIdx+1;
        }
    }
    return nextBkgIdx;
}

void LoginWnd::paintBackground(qint8 bkgIdx, qreal bkgOpacity)
{
    QPainter painter(this);
    QPixmap background;
    background.load(QString("%1%2").arg(LW_BACKGOUND_PREFIX).arg(bkgIdx));
    painter.setOpacity(bkgOpacity);
    painter.drawPixmap(0, 0, background);
}
}//namespace qq_like
