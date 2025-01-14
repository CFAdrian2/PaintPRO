#include "PaintView.h"

#include <QMouseEvent>'

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

QGraphicsLineItem* PaintView::createLine(const QLineF& line)
{
	return _scene->addLine(line, _pen);
}

QGraphicsRectItem* PaintView::createRectangle(const QRectF& rectangle)
{
	return _scene->addRect(rectangle, _pen, _brush);
}

QGraphicsEllipseItem* PaintView::createEllipse(const QRectF& ellipse)
{
	return _scene->addEllipse(ellipse, _pen, _brush);
}

QGraphicsPolygonItem* PaintView::createTriangle(const QPolygonF& triangle)
{
	return _scene->addPolygon(triangle, _pen, _brush);
}


QGraphicsItem* PaintView::itemAt(const QPointF& pos)
{
	return _scene->itemAt(pos, QTransform());
}

void PaintView::onColorSelected(const QColor& color)
{
	_pen.setColor(color);
	_brush.setColor(color);
}

void PaintView::onActionLineThicknessTriggered(const QString& lineThickness)
{
	_pen.setWidth(lineThickness.toInt());
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