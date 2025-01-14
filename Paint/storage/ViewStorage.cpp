#include "ViewStorage.h"

#include <QFile>
#include <QFileInfo>
#include <QGraphicsItem>

bool ViewStorage::saveView(PaintView* view, const QString& path)
{
    QString fileExtension = QFileInfo(QFile(path)).suffix();
    if (fileExtension == "jpg" || fileExtension == "png")
    {
        ViewStorage::saveToImage(view, path);
    }

    return true;
}

void ViewStorage::openView(PaintView* view, const QString& path)
{
    QPixmap pixmap(path);
    QSize viewSize = view->size();
    pixmap = pixmap.scaled(viewSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(pixmap);
    view->scene()->clear();
    view->scene()->addItem(item);
}

void ViewStorage::saveToImage(PaintView* view, const QString& path)
{
    QPixmap pixMap = view->grab();
    pixMap.save(path);
}