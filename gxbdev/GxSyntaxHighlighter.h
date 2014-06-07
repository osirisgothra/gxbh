#ifndef GXSYNTAXHIGHLIGHTER_H
#define GXSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class GxSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit GxSyntaxHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text);

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp hereDocumentStartExpression;
    QRegExp hereDocumentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat delimitersFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat hereDocumentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
    QTextCharFormat builtinsFormat;
    QTextCharFormat numericFormat;

};

#endif // GXSYNTAXHIGHLIGHTER_H
