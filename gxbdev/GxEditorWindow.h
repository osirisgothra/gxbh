#ifndef GXEDITORWINDOW_H
#define GXEDITORWINDOW_H

#include <QTextEdit>

class GxEditorWindow : public QTextEdit
{
    Q_OBJECT
public:
    explicit GxEditorWindow(QTextDocument* source, QWidget *parent = 0);

signals:

public slots:

};

#endif // GXEDITORWINDOW_H
