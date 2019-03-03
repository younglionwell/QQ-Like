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

#ifndef LOGINEDITLINE_H
#define LOGINEDITLINE_H

#include "../Util/lineeditex.h"
#include <QLabel>
#include <QLineEdit>
#include <QWidget>

namespace qq_like
{
class LoginLineEdit : public QWidget
{
    Q_OBJECT
public:
    explicit LoginLineEdit(QWidget *parent = nullptr);

public:
    void setLeftIcon(QString leftIconPathNormal, QString leftIconPathHover);
    void setBottomIcon(QString bottomLinePathNormal, QString bottomLinePathHover);
    void setLineEditStyleSheet(QString styleSheet);
    void setPlaceholderText(QString placeholderText);
    void setEchoMode(QLineEdit::EchoMode echoMode);

    QString text() const;
signals:

public slots:
    void focusIn();
    void focusOut();
private:
    LineEditEx*  m_lineEdit;   // 编辑框
    QLabel*      m_leftIcon;   // 编辑框左边的图标
    QLabel*      m_rightIcon;  // 编辑框右边的图标
    QLabel*      m_bottomLine; // 编辑框下方的线条

    QString     m_leftIconPathNormal;
    QString     m_leftIconPathHover;
    QString     m_bottomLinePathNormal;
    QString     m_bottomLinePathHover;
};
}//namespace qq_like
#endif // LOGINEDITLINE_H
