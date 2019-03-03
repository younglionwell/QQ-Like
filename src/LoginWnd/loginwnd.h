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

#ifndef LOGINWND_H
#define LOGINWND_H

#include "../Util/windowbase.h"
#include "../Util/headlabel.h"
#include "loginwndmainpage.h"
#include "loginwndloginingpage.h"
#include <QMainWindow>
#include <QPushButton>

namespace qq_like
{
class LoginWnd : public WindowBase
{
    Q_OBJECT
public:
    enum LoginWndPageType
    {
        LWPT_MAINPAGE,      // 登录主界面
        LWPT_LOGINING,      // 登录中界面
    };
public:
    explicit LoginWnd(QWidget *parent = nullptr);
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void showEvent(QShowEvent *event) override;
signals:
    void notifyMsgSignal(QString msg);
    void hideNotifyMsgSignal();
public slots:
    void changeBackground();
    void changeLoginWndPage(LoginWndPageType pageType = LWPT_MAINPAGE);
    void loginButtonPressed();
    void cancelButtonPressed();
private:
    qint8 getNextBkgIdx();
    void  paintBackground(qint8 bkgIdx, qreal bkgOpacity);
private:
    qreal    m_bkgOpacity;         // 下一张背景图的不透明度
    qreal    m_bkgOpacityInterval; // 每次改变背景图的不透明度
    qint8    m_currentBkgIdx;      // 当前背景图的索引
    bool     m_increasing;         // 当前背景图的值正在递增
    QTimer*  m_bkgTimer;           // 背景图动画的计时器

    QPushButton* m_menuCloseBtn;         // 菜单栏关闭按钮
    QPushButton* m_menuMinBtn;           // 菜单栏最小化按钮
    HeadLabel*   m_headLabel;            // 头像

    LoginWndMainPage*      m_mainPage;
    LoginWndLoginingPage*  m_loginingPage;

    LoginWndPageType m_currentPage;      // 当前界面
private:
    const static QString LW_BACKGOUND_PREFIX;   // 背景图的前缀
    const static quint8  LW_BACKGOUND_NUM;      // 背景图数量
};
}//namespace qq_like
#endif // LOGINWND_H
