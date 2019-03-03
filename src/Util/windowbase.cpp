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
#include "windowbase.h"
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QtMath>
#include <QBitmap>
namespace qq_like
{
WindowBase::WindowBase(QWidget *parent) : QMainWindow(parent), m_isPressed(false)
{
}

void WindowBase::paintEventForRoundAndBorder(int roundRadius, int borderWidth)
{
    // 绘制圆角窗口
    QBitmap maskBmp(this->size());
    maskBmp.fill();
    QPainter maskBmpPainter(&maskBmp);
    maskBmpPainter.setPen(Qt::NoPen);
    maskBmpPainter.setBrush(Qt::black);
    maskBmpPainter.setRenderHint(QPainter::Antialiasing, true); //抗锯齿
    maskBmpPainter.drawRoundedRect(this->rect(), roundRadius, roundRadius);
    setMask(maskBmp);

    // 绘制边框阴影
    QPainter painter(this);
    QPixmap border(":/loginwnd/win_border");
    QRect topRect(0, 0, this->rect().width(), borderWidth);
    QRect topRectSource(5, 0, border.width()-10, 5);
    QRect leftRect(0, 0, borderWidth, this->rect().height());
    QRect leftRectSource(0, 5, 5, border.height()-10);
    QRect rightRect(this->rect().width()-borderWidth, 0, borderWidth, this->rect().height());
    QRect rightRectSource(border.width()-5, 5, 5, border.height()-10);
    QRect bottomRect(0, this->rect().height()-borderWidth, this->rect().width(), borderWidth);
    QRect bottomRectSource(5, border.height()-5, border.width()-10, 5);

    painter.drawPixmap(topRect, border, topRectSource);
    painter.drawPixmap(leftRect, border, leftRectSource);
    painter.drawPixmap(rightRect, border, rightRectSource);
    painter.drawPixmap(bottomRect, border, bottomRectSource);

}

void WindowBase::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_pressedPoint = event->globalPos() - this->pos();
        m_isPressed = true;
        event->accept();
    }
}

void WindowBase::mouseReleaseEvent(QMouseEvent *event)
{
    m_isPressed = false;
    event->accept();
}

void WindowBase::mouseMoveEvent(QMouseEvent *event)
{
    if((event->buttons()&(Qt::LeftButton)) && m_isPressed == true)
    {
        move(event->globalPos() - m_pressedPoint);
        event->accept();
    }
}

void WindowBase::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        this->close();
        event->accept();
    }
}
}//namespace qq_like
