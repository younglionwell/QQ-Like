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
#ifndef LOGINWNDMAINPAGE_H
#define LOGINWNDMAINPAGE_H

#include "../Util/checkbox.h"
#include "../Util/clickablelabel.h"
#include "loginlineedit.h"
#include <QCheckBox>
#include <QPushButton>
#include <QWidget>

namespace qq_like
{
class LoginWndMainPage : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWndMainPage(QWidget *parent = nullptr);

    QString getUserName() const;
    QString getPassword() const;
protected:
    virtual void showEvent(QShowEvent *) override;
    virtual void hideEvent(QHideEvent *) override;
signals:
    void loginSignal();
public slots:
    void openRegisterAccountUrl(ClickableLabel*);
    void openFindPasswordUrl(ClickableLabel*);

    void autoLoginChecked(bool isChecked);
    void loginBtnClicked(bool);

    void showNotifyMsg(QString msg);
    void hideNotifyMsg();
private:
    LoginLineEdit*  m_userNameEdit;     // 用户名
    LoginLineEdit*  m_passwordEdit;     // 密码
    CheckBox*       m_autoLogin;        // 自动登录
    CheckBox*       m_remeberPassword;  // 自动登录
    QPushButton*    m_loginBtn;         // 登录按钮

    ClickableLabel* m_findPassword;     // 找回密码
    ClickableLabel* m_registerAccount;  // 注册账号
    QLabel*         m_notifyMsg;        // 提醒信息
};
}//namespace qq_like
#endif // LOGINWNDMAINPAGE_H
