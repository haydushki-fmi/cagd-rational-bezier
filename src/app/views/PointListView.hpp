#ifndef CAGD_RATIONAL_BEZIER_POINTLISTVIEW_HPP
#define CAGD_RATIONAL_BEZIER_POINTLISTVIEW_HPP


#include <QListView>
#include <QKeyEvent>

class PointListView : public QListView {
public:
    explicit PointListView(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event);

    void mouseDoubleClickEvent(QMouseEvent *event) override;
};


#endif //CAGD_RATIONAL_BEZIER_POINTLISTVIEW_HPP
