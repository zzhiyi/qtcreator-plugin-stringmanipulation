#include "stringmanipulationplugin.hpp"
#include "stringmanipulationconstants.hpp"

#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/coreconstants.h>
#include <coreplugin/icontext.h>
#include <coreplugin/icore.h>
#include <texteditor/texteditorconstants.h>
#include <cppeditor/cppeditorconstants.h>

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>

namespace StringManipulation
{
namespace Internal
{

StringManipulationPlugin::StringManipulationPlugin()
{
    // Create your members
}

StringManipulationPlugin::~StringManipulationPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool StringManipulationPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    Core::ActionContainer *cppEditorContextMenu =
        Core::ActionManager::createMenu(CppEditor::Constants::M_CONTEXT);

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("String Manipulation"));
    Core::ActionContainer *contextMenu =
        Core::ActionManager::createMenu(Constants::CONTEXT_MENU_ID);
    contextMenu->menu()->setTitle(tr("String Manipulation"));

    // Search in Google
    QAction *actionSearchInGoogle = new QAction(tr("Search in Google"), this);
    Core::Command *cmdSearchInGoogle = Core::ActionManager::registerAction(
        actionSearchInGoogle, Constants::SEARCH_IN_GOOGLE,
        Core::Context(TextEditor::Constants::C_TEXTEDITOR));
    connect(actionSearchInGoogle, &QAction::triggered, &core,
            &StringManipulationCore::searchInGoogle);
    cppEditorContextMenu->addAction(cmdSearchInGoogle);
    menu->addAction(cmdSearchInGoogle);

    // Sort Declaration By Length
    QAction *actionSortDeclarationByLength = new QAction(tr("Sort Declaration By Length"), this);
    Core::Command *cmdSortDeclarationByLength = Core::ActionManager::registerAction(
        actionSortDeclarationByLength, Constants::SORT_DECLARATION_BY_LENGTH,
        Core::Context(TextEditor::Constants::C_TEXTEDITOR));
    connect(actionSortDeclarationByLength, &QAction::triggered, &core,
            &StringManipulationCore::sortDeclarationByLength);
    menu->addAction(cmdSortDeclarationByLength);
    contextMenu->addAction(cmdSortDeclarationByLength);

    // Paste Diff
    QAction *actionPasteDiff = new QAction(tr("Paste Diff"), this);
    Core::Command *cmdPasteDiff = Core::ActionManager::registerAction(
        actionPasteDiff, Constants::PASTE_DIFF,
        Core::Context(TextEditor::Constants::C_TEXTEDITOR));
    connect(actionPasteDiff, &QAction::triggered, &core,
            &StringManipulationCore::pasteDiff);
    menu->addAction(cmdPasteDiff);
    contextMenu->addAction(cmdPasteDiff);

    // Selected String to Char Array
    QAction *actionSelectedTextToCharArray = new QAction(tr("Selected String to Char Array"), this);
    Core::Command *cmdSelectedStringToCharArray = Core::ActionManager::registerAction(
        actionSelectedTextToCharArray, Constants::SELECTED_STRING_TO_CHAR_ARRAY_ACTION_ID,
        Core::Context(TextEditor::Constants::C_TEXTEDITOR));
    connect(actionSelectedTextToCharArray, &QAction::triggered, &core,
            &StringManipulationCore::selectedStringToCharArray);
    menu->addAction(cmdSelectedStringToCharArray);
    contextMenu->addAction(cmdSelectedStringToCharArray);

    // Strip Space
    QAction *actionStripSpaceInSelectedString = new QAction(tr("Strip Space in Selected String"), this);
    Core::Command *cmdStripSpaceInSelectedString = Core::ActionManager::registerAction(
        actionStripSpaceInSelectedString, Constants::STRIP_SPACE_IN_SELECTED_STRING,
        Core::Context(TextEditor::Constants::C_TEXTEDITOR));
    connect(actionStripSpaceInSelectedString, &QAction::triggered, &core,
            &StringManipulationCore::stripSpaceInSelectedString);
    menu->addAction(cmdStripSpaceInSelectedString);
    contextMenu->addAction(cmdStripSpaceInSelectedString);

    // Add Break Point
    QAction *actionAddBreakPoint = new QAction(tr("Add Break Point"), this);
    Core::Command *cmdAddBreakPoint = Core::ActionManager::registerAction(
        actionAddBreakPoint, Constants::ADD_BREAK_POINT,
        Core::Context(TextEditor::Constants::C_TEXTEDITOR));
    connect(actionAddBreakPoint, &QAction::triggered, &core,
            &StringManipulationCore::addBreakPoint);
    menu->addAction(cmdAddBreakPoint);
    contextMenu->addAction(cmdAddBreakPoint);

    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    cppEditorContextMenu->addSeparator(Core::Context(CppEditor::Constants::CPPEDITOR_ID));
    cppEditorContextMenu->addMenu(contextMenu);

    return true;
}

void StringManipulationPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag StringManipulationPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

} // namespace Internal
} // namespace StringManipulation
