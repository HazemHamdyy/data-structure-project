#include "linenumberarea.h"
#include "mainwindow.h"

LineNumberArea::LineNumberArea(QTextEdit *editor) : QWidget(editor)
{
    codeEditor = editor;
}

QSize LineNumberArea::sizeHint() const
{
    return QSize(((QTextEdit *)codeEditor)->document()->documentMargin(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event)
{
    ((MainWindow *)codeEditor)->lineNumberAreaPaintEvent(event);
}


//LineNumberArea::LineNumberArea(QTextEdit *editor) : QWidget(editor) {
//    codeEditor = editor;
//}

//QSize LineNumberArea::sizeHint() const {
//    return QSize(((QTextEditHighlighter *)codeEditor)->lineNumberAreaWidth(), 0);
//}

//void LineNumberArea::paintEvent(QPaintEvent *event) {
//    ((QTextEditHighlighter *)codeEditor)->lineNumberAreaPaintEvent(event);
//}
