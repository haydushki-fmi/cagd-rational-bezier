#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
          ui(std::make_shared<Ui::MainWindow>()),
          pointModel(std::make_shared<PointModel>()) {
    ui->setupUi(this);

    ui->widget_Canvas->setPointModel(this->pointModel);
    ui->pointsWidget->setModel(this->pointModel.get());

    this->setConnections();
}

void MainWindow::setConnections() {
    connect(ui->widget_Canvas, &Canvas::pointAdded, this->pointModel.get(), &PointModel::addPoint);
    connect(ui->pushButtonClear, &QPushButton::clicked, ui->widget_Canvas, &Canvas::clear);
}
