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
#ifndef LOGINWNDLOGININGPAGE_H
#define LOGINWNDLOGININGPAGE_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>

namespace qq_like
{
class LoginWndLoginingPage : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWndLoginingPage(QWidget *parent = nullptr);
protected:
    virtual void showEvent(QShowEvent *) override;
    virtual void hideEvent(QHideEvent *) override;
signals:
    void cancelSignal();
public slots:
    void changePoints();
    void cancelButtonClicked(bool);
private:
    QLabel*          m_loginingLabel;    // 正在登录中标签
    QPushButton*     m_cancelBtn;        // 取消登录按钮
    QTimer*          m_loginingTimer;    // 登录中动画计时器
    QString          m_points;           // 登录中后面的小点
};
}//namespace qq_like
#endif // LOGINWNDLOGININGPAGE_H
