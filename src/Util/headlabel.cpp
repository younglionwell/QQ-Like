/****************************************************************************
**
** Copyright 2019 yanglingwell@sina.com
**
** QQ-Like 头像显示 Label
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

#include "headlabel.h"
#include <QBitmap>
#include <QPainter>

namespace qq_like
{

HeadLabel::HeadLabel(QWidget *parent, QString headPhotoPath, QString headPhotoShadowPath, QString headPhotoHighlightPath)
    : QLabel(parent), m_headPhoto(nullptr), m_headPhotoRound(nullptr),
      m_headPhotoShadow(nullptr), m_headPhotoHighlight(nullptr)
{
    if(headPhotoPath.isEmpty() == false)
    {
        m_headPhoto = new QPixmap(headPhotoPath);
    }
    if(headPhotoShadowPath.isEmpty() == false)
    {
        m_headPhotoShadow = new QPixmap(headPhotoShadowPath);
    }
    if(headPhotoHighlightPath.isEmpty() == false)
    {
        m_headPhotoHighlight = new QPixmap(headPhotoHighlightPath);
    }
}

HeadLabel::~HeadLabel()
{
    if(m_headPhoto != nullptr)
    {
        delete  m_headPhoto;
    }
    if(m_headPhotoRound != nullptr)
    {
        delete  m_headPhotoRound;
    }
    if(m_headPhotoShadow != nullptr)
    {
        delete  m_headPhotoShadow;
    }
    if(m_headPhotoHighlight != nullptr)
    {
        delete  m_headPhotoHighlight;
    }
}

void HeadLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if(m_headPhotoRound != nullptr)
    {
        int tx = (this->width()-m_headPhotoSize.width())/2;
        int ty = (this->height()-m_headPhotoSize.height())/2;
        painter.drawPixmap(tx, ty, *m_headPhotoRound);
    }
    if(m_headPhotoHighlight != nullptr)
    {
        int tx = (this->width()-m_headPhotoHighlightSize.width())/2;
        int ty = (this->height()-m_headPhotoHighlightSize.height())/2;
        painter.drawPixmap(tx, ty, m_headPhotoHighlightSize.width(), m_headPhotoHighlightSize.height(), *m_headPhotoHighlight);
    }
    if(m_headPhotoShadow != nullptr)
    {
        painter.drawPixmap(0, 0, *m_headPhotoShadow);
    }

    return QLabel::paintEvent(event);
}

void HeadLabel::resizeEvent(QResizeEvent *event)
{
    // 创建圆形头像
    if(m_headPhoto != nullptr)
    {
        if(m_headPhotoRound != nullptr)
        {
            delete m_headPhotoRound;
        }

        m_headPhotoSize = {this->size().width()*31/49, this->size().height()*31/49};
        QBitmap mask(m_headPhotoSize);
        QPainter maskPainter(&mask);
        maskPainter.setRenderHint(QPainter::Antialiasing);
        maskPainter.setRenderHint(QPainter::SmoothPixmapTransform);
        maskPainter.fillRect(0, 0, m_headPhotoSize.width(), m_headPhotoSize.height(), Qt::white);
        maskPainter.setBrush(QColor(0, 0, 0));
        maskPainter.drawRoundedRect(0, 0, m_headPhotoSize.width(), m_headPhotoSize.height(), 100, 100);
        m_headPhotoRound = new QPixmap(m_headPhoto->scaled(m_headPhotoSize));
        m_headPhotoRound->setMask(mask);
    }

    if(m_headPhotoHighlight != nullptr)
    {
        m_headPhotoHighlightSize = {this->size().width()*65/98, this->size().height()*65/98};
    }

    return QLabel::resizeEvent(event);
}
}// namespace qq_like
