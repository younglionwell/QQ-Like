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

#ifndef HEADLABEL_H
#define HEADLABEL_H

#include <QLabel>

namespace qq_like
{
class HeadLabel : public QLabel
{
    Q_OBJECT
public:
    explicit HeadLabel(QWidget *parent = nullptr, QString headPhotoPath = "",
                       QString headPhotoShadowPath = "", QString headPhotoHighlightPath = "");
    ~HeadLabel() override;
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;
signals:

public slots:

private:
    QPixmap* m_headPhoto;           // 头像原图
    QPixmap* m_headPhotoRound;      // 显示的头像图
    QPixmap* m_headPhotoShadow;     // 边框阴影
    QPixmap* m_headPhotoHighlight;  // 高亮边框

    QSize    m_headPhotoSize;             // 显示头像的大小
    QSize    m_headPhotoHighlightSize;     // 显示头像高亮边框的大小
};
}//namespace qq_like
#endif // HEADLABEL_H
