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

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;

};

#endif // GXSYNTAXHIGHLIGHTER_H
