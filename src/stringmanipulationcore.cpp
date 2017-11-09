#include "stringmanipulationcore.hpp"
#include <texteditor/texteditor.h>
#include <QStringBuilder>
using namespace TextEditor;

StringManipulationCore::StringManipulationCore(QObject *parent) : QObject(parent)
{

}

static QString stringToCharArrayConverter(const QString &src)
{
    QString result;
    result = "{";

    int i;
    for (i = 0; i < src.size(); i++) {
        result += "'" + src[i] + "',";
    }
    result += "0}";
    return result;
}

void StringManipulationCore::stringToCharArray()
{
    BaseTextEditor *editor = BaseTextEditor::currentTextEditor();
    if (!editor) return;

    QTextCursor cursor = editor->textCursor();
    if (!cursor.hasSelection()) return;

    cursor.insertText(stringToCharArrayConverter(cursor.selectedText()));
}
