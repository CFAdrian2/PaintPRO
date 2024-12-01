#include "PaintView.h"

#include <QMouseEvent>'
#include <qdebug.h>

static const int	kWindowWidth = 1000;
static const int	kWindowHeight = 1000;

PaintView::PaintView(QWidget* parent)
	: QGraphicsView(parent),
	_pen(QBrush(Qt::black), 1)
{
	initScene();

	this->setMouseTracking(true);
	this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

QGraphicsPathItem* PaintView::createPath(const QPainterPath& path)
{
	return _scene->addPath(path, _pen);
}

QGraphicsItem* PaintView::itemAt(const QPointF& pos)
{
	return _scene->itemAt(pos, QTransform());
}

void PaintView::onColorSelected(const QColor& color)
{
	qDebug() << "action Color triggered";
	_pen.setColor(color);
	_brush.setColor(color);
}

void PaintView::initScene()
{
	_scene = new QGraphicsScene(this);
	_scene->setSceneRect(QRectF(0, 0, kWindowWidth, kWindowHeight));
	this->setScene(_scene);
	this->centerOn(0, 0);
}

void PaintView::mousePressEvent(QMouseEvent* event)
{
	const QPointF pos = mapToScene(event->pos());
	const Qt::MouseButtons buttons = event->buttons();
	emit mousePress(pos, buttons);
}

void PaintView::mouseMoveEvent(QMouseEvent* event)
{
	const QPointF pos = mapToScene(event->pos());
	const Qt::MouseButtons buttons = event->buttons();
	emit mouseMove(pos, buttons);
}

void PaintView::mouseReleaseEvent(QMouseEvent* event)
{
	const QPointF pos = mapToScene(event->pos());
	const Qt::MouseButtons buttons = event->buttons();
	emit mouseRelease(pos, buttons);
}