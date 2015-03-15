#ifndef GXWEBVIEW_H
#define GXWEBVIEW_H

#include "ui_GxWebView.h"

class GxWebView : public QMainWindow, private Ui::GxWebView
{
    Q_OBJECT
    
public:
    explicit GxWebView(QWidget *parent = 0);
};

#endif // GXWEBVIEW_H
