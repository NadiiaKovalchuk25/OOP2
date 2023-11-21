#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void numbers();

    void on_pushButton_clear_clicked();
    void on_pushButton_to2_clicked();
    void on_pushButton_to8_clicked();
    void on_pushButton_to16_clicked();

    void on_pushButton2_to_10_clicked();
    void on_pushButton8_to_10_clicked();
    void on_pushButton16_to_10_clicked();
};
#endif // MAINWINDOW_H
