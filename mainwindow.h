#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirIterator>
#include <QStandardItemModel>
#include <QItemSelection>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void createTreeView();
    ~MainWindow();
private slots:
    void selectionChangedSlot(const QItemSelection);

private:
    Ui::MainWindow *ui;
    QStandardItemModel model;
    //QDirIterator *dirIt;
};
#endif // MAINWINDOW_H
