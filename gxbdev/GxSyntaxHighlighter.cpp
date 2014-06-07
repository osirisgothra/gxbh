#include "GxSyntaxHighlighter.h"
#include <QTextDocument>

GxSyntaxHighlighter::GxSyntaxHighlighter(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
     HighlightingRule rule;

     QTextFormat fmt;
     fmt.setBackground(QColor(0,0,0));
     fmt.setForeground(QColor(128,138,148));

     parent->setDefaultStyleSheet("* { background-color: black; color: white; }");


     keywordFormat.setForeground(Qt::cyan);
     keywordFormat.setFontWeight(QFont::Bold);
     QStringList keywordPatterns;
     keywordPatterns << "\\!" << "case" << "do" << "done" << "elif" << "else" << "esac" << "fi" << "for" << "function" << "if" << "in" << "select" << "then" << "until" << "while" << "\\{" << "\\}" << "time" << "\\[" << "\\]" << "\\;";

     foreach (const QString &pattern, keywordPatterns)
     {
         rule.pattern = QRegExp("\\b" + pattern + "\\b");
         rule.format = keywordFormat;
         highlightingRules.append(rule);
     }

     builtinsFormat.setForeground(Qt::yellow);
     builtinsFormat.setFontItalic(true);
     QStringList builtinList;
     builtinList << "\\:" << "\\." << "alias" << "bg" << "bind" << "break" << "builtin" << "cd" << "command" <<
             "compgen" << "complete" << "continue" << "declare" << "dirs" << "disown" << "echo" << "enable" << "eval" << "exec" << "exit" << "export" << "fc" << "fg" << "getopts" <<
             "hash" << "help" << "history" << "jobs" << "kill" << "let" << "local" << "logout" << "popd" << "printf" << "pushd" << "pwd" << "read" << "readonly" << "return" <<
             "set" << "shift" << "shopt" << "source" << "suspend" << "test" << "times" << "trap" << "type" << "typeset" << "ulimit" << "umask" << "unalias" << "unset" <<
             "wait";

     foreach (const QString &pattern, builtinList)
     {
         rule.pattern = QRegExp("\\b" + pattern + "\\b");
         rule.format = builtinsFormat;
         highlightingRules.append(rule);
     }


     delimitersFormat.setFontWeight(QFont::Bold);
     delimitersFormat.setForeground(QColor(92,92,192));
     rule.pattern = QRegExp("[\\(\\)\\{\\}\\\"\\'\\<\\>\\|\\`\\*\\-\\+\\=\\%\\$\\^\\&]");
     rule.format = delimitersFormat;
     highlightingRules.append(rule);

     numericFormat.setFontFixedPitch(true);
     numericFormat.setForeground(QColor(255,224,255));
     rule.pattern = QRegExp("\\b[0-9]+\\b");
     rule.format = numericFormat;
     highlightingRules.append(rule);

     singleLineCommentFormat.setForeground(QColor(128,192,128));
     rule.pattern = QRegExp("#[^\n]*");
     rule.format = singleLineCommentFormat;
     highlightingRules.append(rule);

     hereDocumentFormat.setForeground(Qt::red);

     quotationFormat.setForeground(Qt::darkGreen);
     rule.pattern = QRegExp("([\"][^\"]*[\"]|[\'][^\']*[\'])");
     rule.format = quotationFormat;
     highlightingRules.append(rule);

     functionFormat.setFontItalic(true);
     functionFormat.setForeground(Qt::blue);
     rule.pattern = QRegExp("function \\b[A-Za-z0-9_]+");      // originally "function \\b[A-Za-z0-9_]+(?=\\()"
     rule.format = functionFormat;
     highlightingRules.append(rule);

     hereDocumentStartExpression = QRegExp("\\[<]{1,2}[-]{0,1}");
     hereDocumentEndExpression = QRegExp("^.*$");
 }

 void GxSyntaxHighlighter::highlightBlock(const QString &text)
 {
     foreach (const HighlightingRule &rule, highlightingRules) {
         QRegExp expression(rule.pattern);
         int index = expression.indexIn(text);
         while (index >= 0) {
             int length = expression.matchedLength();
             setFormat(index, length, rule.format);
             index = expression.indexIn(text, index + length);
         }
     }
     setCurrentBlockState(0);

     int startIndex = 0;
     if (previousBlockState() != 1)
         startIndex = hereDocumentStartExpression.indexIn(text);

     while (startIndex >= 0) {
         int endIndex = hereDocumentEndExpression.indexIn(text, startIndex);
         int commentLength;
         if (endIndex == -1) {
             setCurrentBlockState(1);
             commentLength = text.length() - startIndex;
         } else {
             commentLength = endIndex - startIndex
                             + hereDocumentEndExpression.matchedLength();
         }
         setFormat(startIndex, commentLength, hereDocumentFormat);
         startIndex = hereDocumentStartExpression.indexIn(text, startIndex + commentLength);
     }
 }
