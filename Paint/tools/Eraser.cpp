#include "tools/Eraser.h"
#include "PaintView.h"
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsEllipseItem>
#include <QtGui/QPainterPath>

EraserTool::EraserTool(PaintView* view)
    : Tool(view)
{}

void EraserTool::onMousePress(const QPointF& pos) {
    QGraphicsRectItem* eraserItem = new QGraphicsRectItem();
    eraserItem->setRect(pos.x() - 15, pos.y() - 15, 30, 30);
    eraserItem->setBrush(Qt::transparent);
    _view->scene()->addItem(eraserItem);


    QList<QGraphicsItem*> itemsToErase = _view->scene()->items(eraserItem->boundingRect());
    for (QGraphicsItem* item : itemsToErase) {
        if (item->collidesWithItem(eraserItem)) {
            _view->scene()->removeItem(item);
            delete item;
        }
    }

    Tool::onMousePress(pos);
}

void EraserTool::onMouseMove(const QPointF& pos) {
    QGraphicsEllipseItem* eraserItem = new QGraphicsEllipseItem();
    eraserItem->setRect(pos.x() - 15, pos.y() - 15, 30, 30);
    eraserItem->setBrush(Qt::transparent);

    QList<QGraphicsItem*> itemsToErase = _view->scene()->items(eraserItem->boundingRect());
    for (QGraphicsItem* item : itemsToErase) {
        if (item->collidesWithItem(eraserItem)) {
            _view->scene()->removeItem(item);
            delete item;
        }
    }

    Tool::onMouseMove(pos);
}
