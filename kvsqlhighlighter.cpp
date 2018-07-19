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

#include "kvsqlhighlighter.h"

KvSqlHighlighter::KvSqlHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
    KvColorScheme colorScheme = KvSettings::getCurrentColorScheme();

    // KeyWords
    keywordFormat.setForeground(colorScheme.textColors.at(1));
    keywordFormat.setBackground(colorScheme.backgroundColors.at(1));
    keywordFormat.setFontFamily(colorScheme.fonts.at(1).family());
    keywordFormat.setFontItalic(colorScheme.fonts.at(1).italic());
    keywordFormat.setFontWeight(colorScheme.fonts.at(1).weight());
    //keywordFormat.setFont(colorScheme.fonts.at(1));
    QStringList keywordPatterns;
    keywordPatterns << "\\bbyte\\b"
            << "\\bchar\\b" << "\\bcount\\b"
            << "\\bdate\\b"
            << "\\bexecute\\b"
            << "\\bfunction\\b"
            << "\\blong\\b"
            << "\\bmodify\\b"
            << "\\brename\\b" << "\\brollback\\b" << "\\brow\\b"
            << "\\btype\\b";

    foreach (QString pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        rule.pattern.setCaseSensitivity ( Qt::CaseInsensitive );
        highlightingRules.append(rule);
    }

    // Reserved Words
    //reservedFormat.setForeground(Qt::black);
    //reservedFormat.setFontWeight(QFont::Bold);
    reservedFormat.setForeground(colorScheme.textColors.at(2));
    reservedFormat.setBackground(colorScheme.backgroundColors.at(2));
    reservedFormat.setFontFamily(colorScheme.fonts.at(2).family());
    reservedFormat.setFontItalic(colorScheme.fonts.at(2).italic());
    reservedFormat.setFontWeight(colorScheme.fonts.at(2).weight());
    //reservedFormat.setFont(colorScheme.fonts.at(2));
    QStringList reservedPatterns;
    reservedPatterns << "\\ball\\b" << "\\balter\\b" << "\\band\\b" << "\\bany\\b" << "\\bas\\b" << "\\basc\\b"
            << "\\bbetween\\b" << "\\bby\\b"
            << "\\bcheck\\b" << "\\bcreate\\b"
            << "\\bdecimal\\b" << "\\bdefault\\b" << "\\bdelete\\b" << "\\bdesc\\b" << "\\bdistinct\\b" << "\\bdrop\\b"
            << "\\bexists\\b"
            << "\\bfrom\\b"
            << "\\bgrant\\b" << "\\bgroup\\b"
            << "\\bhaving\\b"
            << "\\bidentified\\b" << "\\bindex\\b" << "\\binsert\\b" << "\\bintersect\\b" << "\\binto\\b" << "\\bis\\b"
            << "\\blike\\b" << "\\block\\b"
            << "\\bminus\\b"
            << "\\bnot\\b" << "\\bnull\\b"
            << "\\bof\\b" << "\\bon\\b" << "\\bor\\b" << "\\border\\b"
            << "\\brevoke\\b"
            << "\\bselect\\b"
            << "\\btable\\b" << "\\bto\\b" << "\\btype\\b"
            << "\\bunion\\b" << "\\bunique\\b" << "\\bupdate\\b"
            << "\\bvalues\\b" << "\\bview\\b"
            << "\\bwhere\\b";

    foreach (QString pattern, reservedPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = reservedFormat;
        rule.pattern.setCaseSensitivity ( Qt::CaseInsensitive );
        highlightingRules.append(rule);
    }
    
    // Types
    //typeFormat.setForeground(Qt::blue);
    typeFormat.setForeground(colorScheme.textColors.at(3));
    typeFormat.setBackground(colorScheme.backgroundColors.at(3));
    typeFormat.setFontFamily(colorScheme.fonts.at(3).family());
    typeFormat.setFontItalic(colorScheme.fonts.at(3).italic());
    typeFormat.setFontWeight(colorScheme.fonts.at(3).weight());
    //typeFormat.setFont(colorScheme.fonts.at(3));
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

    

    // Functions
    //functionFormat.setForeground(Qt::darkGreen);
    functionFormat.setForeground(colorScheme.textColors.at(4));
    functionFormat.setBackground(colorScheme.backgroundColors.at(4));
    functionFormat.setFontFamily(colorScheme.fonts.at(4).family());
    functionFormat.setFontItalic(colorScheme.fonts.at(4).italic());
    functionFormat.setFontWeight(colorScheme.fonts.at(4).weight());
    //functionFormat.setFont(colorScheme.fonts.at(4));
    QStringList functionPatterns;
    functionPatterns << "\\babs\\b" << "\\bacos\\b" << "\\bascii\\b" << "\\basin\\b" << "\\batan\\b" << "\\batan2\\b" << "\\bavg\\b"
            << "\\bbetween\\b"
            << "\\bceil\\b" << "\\bchr\\b" << "\\bcos\\b" << "\\bcosh\\b" << "\\bcount\\b"
            << "\\bexists\\b" << "\\bexp\\b"
            << "\\bfloor\\b"
            << "\\bgreatest\\b"
            << "\\bleast\\b" << "\\blength\\b" << "\\blike\\b" << "\\bln\\b" << "\\blog\\b" << "\\blower\\b" << "\\blpad\\b" << "\\bltrim\\b"
            << "\\bmax\\b" << "\\bmin\\b" << "\\bmod\\b"
            << "\\bpower\\b"
            << "\\bround\\b" << "\\brpad\\b" << "\\brtrim\\b"
            << "\\bsin\\b" << "\\bsinh\\b" << "\\bsqrt\\b" << "\\bsubstr\\b" << "\\bsum\\b"
            << "\\btan\\b" << "\\btanh\\b" << "\\btrim\\b" << "\\btrunc\\b"
            << "\\bupper\\b"
            << "\\bvariance\\b";

    foreach (QString pattern, functionPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = functionFormat;
        rule.pattern.setCaseSensitivity ( Qt::CaseInsensitive );
        highlightingRules.append(rule);
    }
    
    singleLineCommentFormat.setForeground(colorScheme.textColors.at(5));
    singleLineCommentFormat.setBackground(colorScheme.backgroundColors.at(5));
    singleLineCommentFormat.setFontFamily(colorScheme.fonts.at(5).family());
    singleLineCommentFormat.setFontItalic(colorScheme.fonts.at(5).italic());
    singleLineCommentFormat.setFontWeight(colorScheme.fonts.at(5).weight());
    //singleLineCommentFormat.setFont(colorScheme.fonts.at(5));
    //singleLineCommentFormat.setForeground(Qt::gray);
    //singleLineCommentFormat.setFontItalic(true);
    rule.pattern = QRegExp("--[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(colorScheme.textColors.at(6));
    multiLineCommentFormat.setBackground(colorScheme.backgroundColors.at(6));
    multiLineCommentFormat.setFontFamily(colorScheme.fonts.at(6).family());
    multiLineCommentFormat.setFontItalic(colorScheme.fonts.at(6).italic());
    multiLineCommentFormat.setFontWeight(colorScheme.fonts.at(6).weight());
    //multiLineCommentFormat.setFont(colorScheme.fonts.at(6));
    //multiLineCommentFormat.setForeground(Qt::gray);
    //multiLineCommentFormat.setFontItalic(true);

    quotationFormat.setForeground(colorScheme.textColors.at(7));
    quotationFormat.setBackground(colorScheme.backgroundColors.at(7));
    quotationFormat.setFontFamily(colorScheme.fonts.at(7).family());
    quotationFormat.setFontItalic(colorScheme.fonts.at(7).italic());
    quotationFormat.setFontWeight(colorScheme.fonts.at(7).weight());
    //quotationFormat.setFont(colorScheme.fonts.at(7));
    //quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

void KvSqlHighlighter::highlightBlock(const QString &text)
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
