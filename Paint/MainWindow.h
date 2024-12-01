#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qcolordialog.h>
#include <QtWidgets/QToolBar>
#include <QAction>
#include "ui_MainWindow.h"

#include "PaintView.h"
#include "PaintController.h"
#include "Pen.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected slots:
	void onColorSelected(const QColor& colors);

private:
	void initView();
	void initController();
	void initPen();
		 
	void initTopToolBar();

private:
    Ui::MainWindowClass ui;
	PaintView* _view;
	PaintController* _controller;
	QAction* _colorAction;
	Pen* _pen;
	QToolBar* _topToolBar;
	QColorDialog* _colorDialog;

};
