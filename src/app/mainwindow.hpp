#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "models/PointModel.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    virtual ~MainWindow() = default;

private:
    void setConnections();

private:
    std::shared_ptr<Ui::MainWindow> ui;
    std::shared_ptr<PointModel> pointModel;
};

#endif // MAINWINDOW_HPP
