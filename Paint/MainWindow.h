#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qcolordialog.h>
#include <QtWidgets/QToolBar>
#include <QAction>
#include "ui_MainWindow.h"

#include "PaintView.h"
#include "controllers/PaintController.h"
#include "tools/Tool.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
	void onColorSelected(const QColor& colors);
	void onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons);
	void onToolSelected(const ToolType type);

private:
	void initView();
	void initController();
	
	void initLeftToolbar();
	void initTopToolBar();

private:
    Ui::MainWindowClass _ui;
	PaintView*			_view;
	PaintController*	_controller;
	QToolBar*			_topToolBar;
	QToolBar*			_leftToolBar;
	QColorDialog*		_colorDialog;
	QAction*			_colorAction;
	QAction*			_lineAction;
	QAction*			_penAction;
	QAction*			_selectAction;
	QAction*			_rectangleAction;
	QAction*			_ellipseAction;
	QAction*			_triangleAction;
	QAction*			_eraserAction;
};
