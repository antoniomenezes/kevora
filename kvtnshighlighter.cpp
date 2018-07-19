/****************************************************************************
**
** Author: Antonio Marcio A Menezes.
**
** This file is part of the Kevora IDE.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include <QtGui>

#include "kvtnshighlighter.h"

KvTnsHighlighter::KvTnsHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    // KeyWords
    keywordFormat.setForeground(Qt::black);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bdescription\\b" << "\\bdescription_list\\b" << "\\baddress_list\\b" << "\\baddress\\b" 
            << "\\bsid_list_listener\\b" << "\\bsid_list\\b" << "\\bsid_desc\\b" << "\\bsid_name\\b" << "\\bsid\\b"
            << "\\boracle_home\\b" << "\\bprogram\\b" << "\\bpresentation\\b" << "\\bkey\\b"
            << "\\bprotocol\\b" << "\\bhost\\b" << "\\bdefault_service_listener\\b"
            << "\\bport\\b" << "\\bconnect_data\\b" << "\\bservice_name\\b" << "\\bserver\\b"
            << "\\blistener\\b" << "\\bsqlnet\\b";

    foreach (QString pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        rule.pattern.setCaseSensitivity ( Qt::CaseInsensitive );
        highlightingRules.append(rule);
    }

    // Reserved Words
    reservedFormat.setForeground(Qt::blue);
    reservedFormat.setFontWeight(QFont::Bold);
    QStringList reservedPatterns;
    reservedPatterns 	<< "\\btcp\\b" << "\\bdedicated\\b" << "\\bipc\\b" << "\\bextproc_for_xe\\b"
            << "\\bextproc\\b" << "\\bnts\\b";

    foreach (QString pattern, reservedPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = reservedFormat;
        rule.pattern.setCaseSensitivity ( Qt::CaseInsensitive );
        highlightingRules.append(rule);
    }
    
    // Types
    typeFormat.setForeground(Qt::blue);
    QStringList typePatterns;
    typePatterns << "\\bnumber\\b" << "\\bnumeric\\b" << "\\binteger\\b" 
            << "\\bvarchar2\\b" << "\\bchar\\b" << "\\bnvarchar2\\b"
            << "\\blong\\b" << "\\bblob\\b" << "\\bclob\\b" << "\\bnblob\\b"
            << "\\bdate\\b" << "\\bboolean\\b";

    foreach (QString pattern, typePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = typeFormat;
        rule.pattern.setCaseSensitivity ( Qt::CaseInsensitive );
        highlightingRules.append(rule);
    }


    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegExp("\\b[A-Za-z]_PK+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::gray);
    singleLineCommentFormat.setFontItalic(true);
    rule.pattern = QRegExp("--[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::gray);
    multiLineCommentFormat.setFontItalic(true);

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    // Types
    functionFormat.setForeground(Qt::darkGreen);
    QStringList functionPatterns;
    functionPatterns << "\\bauthentication_services\\b";

    foreach (QString pattern, functionPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = functionFormat;
        rule.pattern.setCaseSensitivity ( Qt::CaseInsensitive );
        highlightingRules.append(rule);
    }

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

void KvTnsHighlighter::highlightBlock(const QString &text)
{
    foreach (HighlightingRule rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = text.indexOf(expression);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = text.indexOf(expression, index + length);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while (startIndex >= 0) {
        int endIndex = text.indexOf(commentEndExpression, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression,
                                  startIndex + commentLength);
    }
}
