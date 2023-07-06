#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWindow *parent)
    : QWindow(parent)
{
    context = new QOpenGLContext(this);
    context->setFormat(requestedFormat());
    context->create();
}

MainWindow::~MainWindow()
{
    delete context;
}

void MainWindow::exposeEvent(QExposeEvent *event)
{
    if (isExposed()) {
        context->makeCurrent(this);

        // Add your rendering code here

        context->swapBuffers(this);
    }
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    // Handle the resize event here
}
void MainWindow::initializeGL()
{
    QOpenGLContext* context = QOpenGLContext::currentContext();
    initializeOpenGLFunctions();

    // Add any additional OpenGL initialization code here
}

void MainWindow::resizeGL(int w, int h)
{
    // Add any code to handle the resize event here
}

void MainWindow::paintGL()
{
    // Add your rendering code here
}

