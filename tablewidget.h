#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H
#include <QWidget>
#include <QStackedWidget>
#include <QGridLayout>

class tableWidget : public QWidget
{
  Q_OBJECT
  public:
    tableWidget( QWidget* parent=nullptr );
  public slots:
    void handlegoFull();
};
#endif //TABLEWIDGET_H