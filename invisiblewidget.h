#ifndef INVISIBLEWIDGET_H
#define INVISIBLEWIDGET_H
#include <QWidget>
#include <QStackedWidget>
#include <QGridLayout>
#include <QFrame>
#include "custombutton.h"

class customButton;

class invisibleWidget : public QWidget
{
  Q_OBJECT
  public: 
    invisibleWidget( QWidget *parent = nullptr, QWidget *widget = nullptr, QStackedWidget *stackedWidget = nullptr, QHBoxLayout *fullScreenLayout = nullptr, QHBoxLayout *placeholderLayout = nullptr );
  public slots:
    void handleButtonClicked();
  signals:
    void goFull(bool isFull);
  private:
    QWidget* m_widget;
    customButton* m_button;
    QStackedWidget* m_stackedWidget;
    QHBoxLayout* m_fullScreenLayout;
    QHBoxLayout* m_placeholderLayout;
    bool isFullScreen;
    QWidget* placeholder;
};
#endif //INVISIBLEWIDGET_H