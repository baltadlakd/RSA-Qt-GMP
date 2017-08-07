#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pnqButton_clicked();

    void on_textoSinCifrar_textChanged();

    void on_cifrarButton_clicked();

    void on_actionCargar_triggered();

    void on_actionGuardar_triggered();

    void on_actionCCOB_triggered();

private:
    Ui::MainWindow *ui;
    bool puedeCifrar=false;
};

#endif // MAINWINDOW_H
