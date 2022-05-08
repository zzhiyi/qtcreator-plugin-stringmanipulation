#ifndef STRINGMANIPULATIONPLUGIN_H
#define STRINGMANIPULATIONPLUGIN_H

#include "stringmanipulation_global.h"
#include "stringmanipulationcore.h"
#include <extensionsystem/iplugin.h>

namespace StringManipulation {
namespace Internal {

class StringManipulationPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "StringManipulation.json")
    
public:
    StringManipulationPlugin();
    ~StringManipulationPlugin() override;
    
    bool initialize(const QStringList &arguments, QString *errorString) override;
    void extensionsInitialized() override;
    ShutdownFlag aboutToShutdown() override;
    
private:
    StringManipulationCore core;
};

} // namespace Internal
} // namespace StringManipulation

#endif // STRINGMANIPULATIONPLUGIN_H
