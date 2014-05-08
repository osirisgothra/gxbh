#include "GxEditorWindow.h"

GxEditorWindow::GxEditorWindow(QTextDocument *source, QWidget *parent) :
    QTextEdit(parent)
{
    this->setDocument(source);

}
