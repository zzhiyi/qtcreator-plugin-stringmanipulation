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

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("String Manipulation"));
    Core::ActionContainer *contextMenu =
        Core::ActionManager::createMenu(Constants::CONTEXT_MENU_ID);
    contextMenu->menu()->setTitle(tr("String Manipulation"));

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

    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    Core::ActionContainer *cppEditorContextMenu =
        Core::ActionManager::createMenu(CppEditor::Constants::M_CONTEXT);
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
