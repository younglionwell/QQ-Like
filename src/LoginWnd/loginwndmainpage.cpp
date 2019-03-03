/****************************************************************************
**
** Copyright 2019 yanglingwell@sina.com
**
** QQ-Like 登录界面窗体: 登录界面显示的控件
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
#include "loginwndmainpage.h"

#include <QDesktopServices>
#include <QUrl>
namespace qq_like
{
LoginWndMainPage::LoginWndMainPage(QWidget *parent) : QWidget(parent),
    m_userNameEdit(nullptr), m_passwordEdit(nullptr),
    m_remeberPassword(nullptr), m_findPassword(nullptr), m_registerAccount(nullptr)
{
    m_userNameEdit = new LoginLineEdit(parent);
    m_userNameEdit->setBottomIcon(":/loginwnd/edit_frame_normal", ":/loginwnd/edit_frame_hover");
    m_userNameEdit->setLeftIcon(":/loginwnd/qqnum_normal", ":/loginwnd/qqnum_hover");
    m_userNameEdit->setPlaceholderText(QString::fromLocal8Bit("QQ号码/手机/邮箱"));
    m_userNameEdit->setStyleSheet("font-size: 14px;font-family:Microsoft YaHei;");
    m_userNameEdit->move(100, 170);

    m_passwordEdit = new LoginLineEdit(parent);
    m_passwordEdit->setBottomIcon(":/loginwnd/edit_frame_normal", ":/loginwnd/edit_frame_hover");
    m_passwordEdit->setLeftIcon(":/loginwnd/psw_normal", ":/loginwnd/psw_hover");
    m_passwordEdit->setPlaceholderText(QString::fromLocal8Bit("密码"));
    m_passwordEdit->setStyleSheet("font-size: 14px;font-family:Microsoft YaHei;");
    m_passwordEdit->setEchoMode(QLineEdit::Password);
    m_passwordEdit->move(100, 210);

    m_autoLogin = new CheckBox(false, parent);
    m_autoLogin->move(98, 248);
    m_autoLogin->setText(QString::fromLocal8Bit("自动登录"));
    QObject::connect(m_autoLogin, &CheckBox::statusChanged, this, &LoginWndMainPage::autoLoginChecked);

    m_remeberPassword = new CheckBox(false, parent);
    m_remeberPassword->move(192, 248);
    m_remeberPassword->setText(QString::fromLocal8Bit("记住密码"));

    m_findPassword = new ClickableLabel(parent);
    m_findPassword->setText(QString::fromLocal8Bit("找回密码"));
    m_findPassword->setStyleSheet("font-size: 12px;font-family:Microsoft YaHei; color: #a6a6a6");
    m_findPassword->setFixedSize(55, 20);
    m_findPassword->move(280, 248);
    QObject::connect(m_findPassword, &ClickableLabel::clickSignal, this, &LoginWndMainPage::openFindPasswordUrl);

    m_registerAccount = new ClickableLabel(parent);
    m_registerAccount->setText(QString::fromLocal8Bit("注册账号"));
    m_registerAccount->setStyleSheet("font-size: 12px;font-family:Microsoft YaHei; color: #a6a6a6;");
    m_registerAccount->setFixedSize(55, 20);
    m_registerAccount->move(12, 300);
    QObject::connect(m_registerAccount, &ClickableLabel::clickSignal, this, &LoginWndMainPage::openRegisterAccountUrl);

    m_loginBtn = new QPushButton(parent);
    m_loginBtn->setFixedSize(230, 35);
    m_loginBtn->move(96, 273);
    m_loginBtn->setStyleSheet("QPushButton{ border-image: url(:/loginwnd/button_login_normal); font-size: 15px;font-family:Microsoft YaHei; color: #ffffff}"
                              "QPushButton:hover:!pressed{ border-image: url(:/loginwnd/button_login_hover); }"
                              "QPushButton:hover:pressed{ border-image: url(:/loginwnd/button_login_down); border-style:none; }");
    m_loginBtn->setText(QString::fromLocal8Bit("登录"));
    QObject::connect(m_loginBtn, &QPushButton::clicked, this, &LoginWndMainPage::loginBtnClicked);

    m_notifyMsg= new QLabel(parent);
    m_notifyMsg->setFixedSize(430, 20);
    m_notifyMsg->setStyleSheet("background-color:rgba(248,46,242,150);font-size: 12px;font-family:Microsoft YaHei;");
    m_notifyMsg->hide();
}

QString LoginWndMainPage::getUserName() const
{
    return m_userNameEdit->text();
}

QString LoginWndMainPage::getPassword() const
{
    return m_passwordEdit->text();
}

void LoginWndMainPage::showEvent(QShowEvent *)
{
    if(m_userNameEdit != nullptr)
    {
        m_userNameEdit->show();
    }
    if(m_passwordEdit != nullptr)
    {
        m_passwordEdit->show();
    }
    if(m_autoLogin != nullptr)
    {
        m_autoLogin->show();
    }
    if(m_remeberPassword != nullptr)
    {
        m_remeberPassword->show();
    }
    if(m_findPassword != nullptr)
    {
        m_findPassword->show();
    }
    if(m_registerAccount != nullptr)
    {
        m_registerAccount->show();
    }
    if(m_loginBtn != nullptr)
    {
        m_loginBtn->show();
    }
}

void LoginWndMainPage::hideEvent(QHideEvent *)
{
    if(m_userNameEdit != nullptr)
    {
        m_userNameEdit->hide();
    }
    if(m_passwordEdit != nullptr)
    {
        m_passwordEdit->hide();
    }
    if(m_autoLogin != nullptr)
    {
        m_autoLogin->hide();
    }
    if(m_remeberPassword != nullptr)
    {
        m_remeberPassword->hide();
    }
    if(m_findPassword != nullptr)
    {
        m_findPassword->hide();
    }
    if(m_registerAccount != nullptr)
    {
        m_registerAccount->hide();
    }
    if(m_loginBtn != nullptr)
    {
        m_loginBtn->hide();
    }

    this->hideNotifyMsg();
}

void LoginWndMainPage::openRegisterAccountUrl(ClickableLabel *)
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://ssl.zc.qq.com/v3/index-chs.html")));
}

void LoginWndMainPage::openFindPasswordUrl(ClickableLabel *)
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://aq.qq.com/v2/uv_aq/html/reset_pwd/pc_reset_pwd_input_account.html?v=3.0")));
}

void LoginWndMainPage::autoLoginChecked(bool isChecked)
{
    if(isChecked == true)
    {
        m_remeberPassword->changeStatus(true);
    }
}

void LoginWndMainPage::loginBtnClicked(bool)
{
    emit loginSignal();
}

void LoginWndMainPage::showNotifyMsg(QString msg)
{
    QWidget* parent = reinterpret_cast<QWidget*>(this->parent());;
    parent->setFixedSize(430, 350);
    m_notifyMsg->move(0, 330);
    m_notifyMsg->setText(" " + msg);
    m_notifyMsg->show();
}

void LoginWndMainPage::hideNotifyMsg()
{
    m_notifyMsg->hide();
    QWidget* parent = reinterpret_cast<QWidget*>(this->parent());
    parent->setFixedSize(430, 330);
}
}//namespace qq_like
