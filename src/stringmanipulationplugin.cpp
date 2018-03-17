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

    QAction *actionSelectedText2CharArray = new QAction(tr("Selected Text to Char Array"), this);
    Core::Command *cmdSelectedText2CharArray = Core::ActionManager::registerAction(
        actionSelectedText2CharArray, Constants::SELECTEDTEXT2CHARARRAY_ACTION_ID,
        Core::Context(TextEditor::Constants::C_TEXTEDITOR));
    connect(actionSelectedText2CharArray, &QAction::triggered, &core,
            &StringManipulationCore::stringToCharArray);

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("String Manipulation"));
    menu->addAction(cmdSelectedText2CharArray);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    Core::ActionContainer *cppEditorContextMenu =
        Core::ActionManager::createMenu(CppEditor::Constants::M_CONTEXT);
    Core::ActionContainer *contextMenu =
        Core::ActionManager::createMenu(Constants::CONTEXT_MENU_ID);
    contextMenu->menu()->setTitle(tr("String Manipulation"));
    contextMenu->addAction(cmdSelectedText2CharArray);
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
