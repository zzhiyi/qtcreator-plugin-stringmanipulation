#include "stringmanipulationcore.hpp"
#include <texteditor/texteditor.h>
#include <QStringBuilder>
using namespace TextEditor;

StringManipulationCore::StringManipulationCore(QObject *parent) : QObject(parent)
{

}

static QString escape(const QChar &c)
{
    switch(c.unicode())
    {
        case 0x07: return "\\a";    // Alert(Beep, Bell)
        case 0x08: return "\\b";    // Backspace
        case 0x09: return "\\t";    // Horizontal Tab
        case 0x0C: return "\\f";    // Formfeed
        case 0x0A: return "\\n";    // Newline(Line feed)
        case 0x0B: return "\\v";    // Vertical Tab
        case 0x0D: return "\\r";    // Carriage Return
        case 0x22: return "\\\"";   // Double quotation mark
        case 0x27: return "\\\'";   // Single quotation mark
        case 0x3F: return "\\?";    // Question mark
        case 0x5C: return "\\\\";   // Backslash
        default:   return c;        // No need to escape
    }
}

static QString toUnicodeHex(const QChar &c)
{
    return "0x"+QString::number(c.unicode(), 16);
}

static QString stringToCharArrayConverter(const QString &src)
{
    QString result;
    result = "{";

    for (int i = 0; i < src.size(); i++) {
        // ASCII
        if(src[i].unicode()<=0xFF)
        {
            result += "'" + escape(src[i]) + "',";
        } 
        // Unicode Characters
        else {
            result += toUnicodeHex(src[i]) + ",";
        }
    }
    result += "0}";
    return result;
}

void StringManipulationCore::selectedStringToCharArray()
{
    BaseTextEditor *editor = BaseTextEditor::currentTextEditor();
    if (!editor) return;

    QTextCursor cursor = editor->textCursor();
    if (!cursor.hasSelection()) return;

    cursor.insertText(stringToCharArrayConverter(cursor.selectedText()));
}

static QString stripSpaceConverter(const QString &src)
{
    QString result;

    for (int i = 0; i < src.size(); i++) {
        if (src[i] != ' ')
            result += src[i];
    }
    return result;
}

void StringManipulationCore::stripSpaceInSelectedString()
{
    BaseTextEditor *editor = BaseTextEditor::currentTextEditor();
    if (!editor) return;

    QTextCursor cursor = editor->textCursor();
    if (!cursor.hasSelection()) return;

    cursor.insertText(stripSpaceConverter(cursor.selectedText()));
}

void StringManipulationCore::addBreakPoint()
{
    BaseTextEditor *editor = BaseTextEditor::currentTextEditor();
    if (!editor) return;

    QTextCursor cursor = editor->textCursor();
    cursor.insertText("__asm__ __volatile__(\"int3\");");
}
