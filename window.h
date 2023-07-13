#ifndef WINDOW_H
#define WINDOW_H
#include<QLabel>
#include<QFrame>
#include<QPushButton>
#include<QWidget>
#include<QStackedWidget>
#include<QGridLayout>
#include<QMainWindow>

class MainWindow : public QMainWindow 
{
  Q_OBJECT
public:
  MainWindow( QWidget *parent = nullptr);
};
#endif //WINDOW_H