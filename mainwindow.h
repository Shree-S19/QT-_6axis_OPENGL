#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWindow>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include "ui_mainwindow.h"

class MainWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    MainWindow(QWindow *parent = nullptr);
    ~MainWindow();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

protected:
    void exposeEvent(QExposeEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QOpenGLContext *context;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

//#include <QOpenGLWidget>//for versions before qt6--- #include <QOpenGLWindow>
