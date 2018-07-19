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

#include "kvoraclehighlighter.h"

KvOracleHighlighter::KvOracleHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    // KeyWords
    keywordFormat.setForeground(Qt::black);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\ba\\b" << "\\badd\\b" << "\\bagent\\b" << "\\baggregate\\b" << "\\barray\\b" << "\\battribute\\b" << "\\bauthid\\b" << "\\bavg\\b"
            << "\\bbfile_base\\b" << "\\bbinary\\b" << "\\bblob_base\\b" << "\\bblock\\b" << "\\bbody\\b" << "\\bboth\\b" << "\\bbound\\b" << "\\bbulk\\b" << "\\bbyte\\b"
            << "\\bc\\b" << "\\bcall\\b" << "\\bcalling\\b" << "\\bcascade\\b" << "\\bchar\\b" << "\\bchar_base\\b" << "\\bcharacter\\b" << "\\bcharsetform\\b" << "\\bcharsetid\\b" << "\\bcharset\\b" << "\\bclob_base\\b" << "\\bclose\\b" << "\\bcollect\\b" << "\\bcomment\\b" << "\\bcommit\\b" << "\\bcommitted\\b" << "\\bcompiled\\b" << "\\bconstant\\b" << "\\bconstructor\\b" << "\\bcontext\\b" << "\\bconvert\\b" << "\\bcount\\b" << "\\bcursor\\b" << "\\bcustomdatum\\b"
            << "\\bdangling\\b" << "\\bdata\\b" << "\\bdate\\b" << "\\bdate_base\\b" << "\\bday\\b" << "\\bdefine\\b" << "\\bdeterministic\\b" << "\\bdouble\\b" << "\\bduration\\b"
            << "\\belement\\b" << "\\belsif\\b" << "\\bempty\\b" << "\\bescape\\b" << "\\bexcept\\b" << "\\bexceptions\\b" << "\\bexecute\\b" << "\\bexit\\b" << "\\bexternal\\b"
            << "\\bfinal\\b" << "\\bfixed\\b" << "\\bfloat\\b" << "\\bforall\\b" << "\\bforce\\b" << "\\bfunction\\b"
            << "\\bgeneral\\b"
            << "\\bhash\\b" << "\\bheap\\b" << "\\bhidden\\b" << "\\bhour\\b"
            << "\\bimmediate\\b" << "\\bincluding\\b" << "\\bindicator\\b" << "\\bindices\\b" << "\\binfinite\\b" << "\\binstantiable\\b" << "\\bint\\b" << "\\binterface\\b" << "\\binterval\\b" << "\\binvalidate\\b" << "\\bisolation\\b"
            << "\\bjava\\b"
            << "\\blanguage\\b" << "\\blarge\\b" << "\\bleading\\b" << "\\blength\\b" << "\\blevel\\b" << "\\blibrary\\b" << "\\blike2\\b" << "\\blike4\\b" << "\\blikec\\b" << "\\blimit\\b" << "\\blimited\\b" << "\\blocal\\b" << "\\blong\\b" << "\\bloop\\b"
            << "\\bmap\\b" << "\\bmax\\b" << "\\bmaxlen\\b" << "\\bmember\\b" << "\\bmerge\\b" << "\\bmin\\b" << "\\bminute\\b" << "\\bmod\\b" << "\\bmodify\\b" << "\\bmonth\\b" << "\\bmultiset\\b"
            << "\\bname\\b" << "\\bnan\\b" << "\\bnational\\b" << "\\bnative\\b" << "\\bnchar\\b" << "\\bnew\\b" << "\\bnocopy\\b" << "\\bnumber_base\\b"
            << "\\bobject\\b" << "\\bocicoll\\b" << "\\bocidatetime\\b" << "\\bocidate\\b" << "\\bociduration\\b" << "\\bociinterval\\b" << "\\bociloblocator\\b" << "\\bocinumber\\b" << "\\bociraw\\b" << "\\bocirefcursor\\b" << "\\bociref\\b" << "\\bocirowid\\b" << "\\bocistring\\b" << "\\bocitype\\b" << "\\bonly\\b" << "\\bopaque\\b" << "\\bopen\\b" << "\\boperator\\b" << "\\boracle\\b" << "\\boradata\\b" << "\\borganization\\b" << "\\borlany\\b" << "\\borlvary\\b" << "\\bothers\\b" << "\\bout\\b" << "\\boverriding\\b"
            << "\\bpackage\\b" << "\\bparallel_enable\\b" << "\\bparameter\\b" << "\\bparameters\\b" << "\\bpartition\\b" << "\\bpascal\\b" << "\\bpipe\\b" << "\\bpipelined\\b" << "\\bpragma\\b" << "\\bprecision\\b" << "\\bprivate\\b"
            << "\\braise\\b" << "\\brange\\b" << "\\braw\\b" << "\\bread\\b" << "\\brecord\\b" << "\\bref\\b" << "\\breference\\b" << "\\brem\\b" << "\\bremainder\\b" << "\\brename\\b" << "\\bresult\\b" << "\\breturn\\b" << "\\breturning\\b" << "\\breverse\\b" << "\\brollback\\b" << "\\brow\\b"
            << "\\bsample\\b" << "\\bsave\\b" << "\\bsavepoint\\b" << "\\bsb1\\b" << "\\bsb2\\b" << "\\bsb4\\b" << "\\bsecond\\b" << "\\bsegment\\b" << "\\bself\\b" << "\\bseparate\\b" << "\\bsequence\\b" << "\\bserializable\\b" << "\\bset\\b" << "\\bshort\\b" << "\\bsize_t\\b" << "\\bsome\\b" << "\\bsparse\\b" << "\\bsqlcode\\b" << "\\bsqldata\\b" << "\\bsqlname\\b" << "\\bsqlstate\\b" << "\\bstandard\\b" << "\\bstatic\\b" << "\\bstddev\\b" << "\\bstored\\b" << "\\bstring\\b" << "\\bstruct\\b" << "\\bstyle\\b" << "\\bsubmultiset\\b" << "\\bsubpartition\\b" << "\\bsubstitutable\\b" << "\\bsubtype\\b" << "\\bsum\\b" << "\\bsynonym\\b"
            << "\\btdo\\b" << "\\bthe\\b" << "\\btime\\b" << "\\btimestamp\\b" << "\\btimezone_abbr\\b" << "\\btimezone_hour\\b" << "\\btimezone_minute\\b" << "\\btimezone_region\\b" << "\\btrailing\\b" << "\\btransac\\b" << "\\btransactional\\b" << "\\btrusted\\b" << "\\btype\\b"
            << "\\bub1\\b" << "\\bub2\\b" << "\\bub4\\b" << "\\bunder\\b" << "\\bunsigned\\b" << "\\buntrusted\\b" << "\\buse\\b" << "\\busing\\b"
            << "\\bvalist\\b" << "\\bvalue\\b" << "\\bvariable\\b" << "\\bvariance\\b" << "\\bvarray\\b" << "\\bvarying\\b" << "\\bvoid\\b"
            << "\\bwhile\\b" << "\\bwork\\b" << "\\bwrapped\\b" << "\\bwrite\\b"
            << "\\byear\\b"
            << "\\bzone\\b";

    foreach (QString pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        rule.pattern.setCaseSensitivity ( Qt::CaseInsensitive );
        highlightingRules.append(rule);
    }

    // Reserved Words
    reservedFormat.setForeground(Qt::black);
    reservedFormat.setFontWeight(QFont::Bold);
    QStringList reservedPatterns;
    reservedPatterns << "\\ball\\b" << "\\balter\\b" << "\\band\\b" << "\\bany\\b" << "\\barray\\b" << "\\barrow\\b" << "\\bas\\b" << "\\basc\\b" << "\\bat\\b"
            << "\\bbegin\\b" << "\\bbetween\\b" << "\\bby\\b"
            << "\\bcase\\b" << "\\bcheck\\b" << "\\bclusters\\b" << "\\bcluster\\b" << "\\bcolauth\\b" << "\\bcolumns\\b" << "\\bcompress\\b" << "\\bconnect\\b" << "\\bcrash\\b" << "\\bcreate\\b" << "\\bcurrent\\b"
            << "\\bdecimal\\b" << "\\bdeclare\\b" << "\\bdefault\\b" << "\\bdelete\\b" << "\\bdesc\\b" << "\\bdistinct\\b" << "\\bdrop\\b"
            << "\\belse\\b" << "\\bend\\b" << "\\bexception\\b" << "\\bexclusive\\b" << "\\bexists\\b"
            << "\\bfetch\\b" << "\\bform\\b" << "\\bfor\\b" << "\\bfrom\\b"
            << "\\bgoto\\b" << "\\bgrant\\b" << "\\bgroup\\b"
            << "\\bhaving\\b"
            << "\\bidentified\\b" << "\\bif\\b" << "\\bin\\b" << "\\bindexes\\b" << "\\bindex\\b" << "\\binsert\\b" << "\\bintersect\\b" << "\\binto\\b" << "\\bis\\b"
            << "\\blike\\b" << "\\block\\b"
            << "\\bminus\\b" << "\\bmode\\b"
            << "\\bnocompress\\b" << "\\bnot\\b" << "\\bnowait\\b" << "\\bnull\\b"
            << "\\bof\\b" << "\\bon\\b" << "\\boption\\b" << "\\bor\\b" << "\\border\\b" << "\\boverlaps\\b"
            << "\\bprior\\b" << "\\bprocedure\\b" << "\\bpublic\\b"
            << "\\brange\\b" << "\\brecord\\b" << "\\bresource\\b" << "\\brevoke\\b"
            << "\\bselect\\b" << "\\bshare\\b" << "\\bsize\\b" << "\\bsql\\b" << "\\bstart\\b" << "\\bsubtype\\b"
            << "\\btabauth\\b" << "\\btable\\b" << "\\bthen\\b" << "\\bto\\b" << "\\btype\\b"
            << "\\bunion\\b" << "\\bunique\\b" << "\\bupdate\\b" << "\\buse\\b"
            << "\\bvalues\\b" << "\\bview\\b" << "\\bviews\\b"
            << "\\bwhen\\b" << "\\bwhere\\b" << "\\bwith\\b";

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

    // Functions
    functionFormat.setForeground(Qt::darkGreen);
    QStringList functionPatterns;
    functionPatterns << "\\babs\\b" << "\\bacos\\b" << "\\badd_months\\b" << "\\bascii\\b" << "\\basin\\b" << "\\batan\\b" << "\\batan2\\b" << "\\bavg\\b"
            << "\\bbetween\\b" << "\\bbfilename\\b"
            << "\\bcase\\b" << "\\bceil\\b" << "\\bchartorowid\\b" << "\\bchr\\b" << "\\bconcat\\b" << "\\bconvert\\b" << "\\bcos\\b" << "\\bcosh\\b" << "\\bcount\\b"
            << "\\bdecode\\b" << "\\bdense_rank\\b" << "\\bderef\\b" << "\\bdump\\b"
            << "\\bempty_blob\\b" << "\\bempty_clob\\b" << "\\bexists\\b" << "\\bexp\\b"
            << "\\bfloor\\b"
            << "\\bgreatest\\b" << "\\bgrouping\\b"
            << "\\bhextoraw\\b"
            << "\\bin\\b" << "\\binitcap\\b" << "\\binstr\\b" << "\\binstrb\\b" << "\\bis\\b"
            << "\\blast_day\\b" << "\\bleast\\b" << "\\blength\\b" << "\\blengthb\\b" << "\\blike\\b" << "\\bln\\b" << "\\blog\\b" << "\\blower\\b" << "\\blpad\\b" << "\\bltrim\\b"
            << "\\bmake_ref\\b" << "\\bmax\\b" << "\\bmin\\b" << "\\bmod\\b" << "\\bmonths_between\\b"
            << "\\bnew_time\\b" << "\\bnext_day\\b" << "\\bnls_charset_decl_len\\b" << "\\bnls_charset_id\\b" << "\\bnls_charset_name\\b" << "\\bnls_initcap\\b" << "\\bnls_lower\\b" << "\\bnlssort\\b" << "\\bnls_upper\\b" << "\\bnvl\\b"
            << "\\bpercent_rank\\b" << "\\bpower\\b"
            << "\\brank\\b" << "\\brawtohex\\b" << "\\bref\\b" << "\\breftohex\\b" << "\\breplace\\b" << "\\bround\\b" << "\\browidtochar\\b" << "\\brow_number\\b" << "\\brpad\\b" << "\\brtrim\\b"
            << "\\bsign\\b" << "\\bsin\\b" << "\\bsinh\\b" << "\\bsoundex\\b" << "\\bsqrt\\b" << "\\bstddev\\b" << "\\bsubstr\\b" << "\\bsubstrb\\b" << "\\bsum\\b" << "\\bsys_context\\b" << "\\bsys_guid\\b" << "\\bsysdate\\b"
            << "\\btan\\b" << "\\btanh\\b" << "\\bto_char\\b" << "\\bto_date\\b" << "\\bto_lob\\b" << "\\bto_multi_byte\\b" << "\\bto_number\\b" << "\\bto_single_byte\\b" << "\\btranslate\\b" << "\\btrim\\b" << "\\btrunc\\b"
            << "\\buid\\b" << "\\bupper\\b" << "\\buser\\b" << "\\buserenv\\b"
            << "\\bvalue\\b" << "\\bvariance\\b" << "\\bvsize\\b";

    foreach (QString pattern, functionPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = functionFormat;
        rule.pattern.setCaseSensitivity ( Qt::CaseInsensitive );
        highlightingRules.append(rule);
    }

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

void KvOracleHighlighter::highlightBlock(const QString &text)
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
