//
//  GuiAngle.cpp
//  
//
//  Created by Lilly Fiorino on 2/28/17.
//
//

#include "GuiAngle.hpp"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
