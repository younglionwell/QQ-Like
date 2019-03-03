/****************************************************************************
**
** Copyright 2019 yanglingwell@sina.com
**
** QQ-Like 实现窗口常用的功能
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

#ifndef WINDOWBASE_H
#define WINDOWBASE_H

#include <QMainWindow>
namespace qq_like
{
class WindowBase : public QMainWindow
{
    Q_OBJECT
public:
    explicit WindowBase(QWidget *parent = nullptr);
protected:
    // 绘制窗口的圆角和边框阴影
    void paintEventForRoundAndBorder(int roundRadius = 0, int borderWidth = 1);

    // 重写鼠标操作以实现移动窗口
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

    // ESC 按下后关闭窗口
    virtual void keyPressEvent(QKeyEvent *event) override;
signals:

public slots:

private:
    QPoint m_pressedPoint; // for moving window
    bool   m_isPressed;
};
}//namespace qq_like
#endif // WINDOWBASE_H
