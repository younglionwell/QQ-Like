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
#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QLabel>
#include <QWidget>

namespace qq_like
{
class CheckBox : public QWidget
{
    Q_OBJECT
public:
    explicit CheckBox(bool checked = false, QWidget *parent = nullptr);
public:
    void setText(QString text);
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void enterEvent(QEvent *) override;
    virtual void leaveEvent(QEvent *) override;
signals:
    void statusChanged(bool isChecked);
public slots:
    void changeStatus(bool isChecked);
private:
    bool     m_isChecked;
    QLabel*  m_leftIcon;    // CheckBox 左边的图标
    QLabel*  m_textLabel;   // CheckBox 右边的文字

    const static QString CHECKBOX_NORMAL_ICON_PATHS[2];
    const static QString CHECKBOX_HOVER_ICON_PATHS[2];
    const static QString CHECKBOX_PRESS_ICON_PATHS[2];
};
}//namespace qq_like

#endif // CHECKBOX_H
