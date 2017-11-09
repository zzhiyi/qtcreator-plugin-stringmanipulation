#pragma once

#include "stringmanipulation_global.hpp"
#include "stringmanipulationcore.hpp"
#include <extensionsystem/iplugin.h>

namespace StringManipulation {
namespace Internal {

class StringManipulationPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "StringManipulation.json")

public:
    StringManipulationPlugin();
    ~StringManipulationPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    StringManipulationCore core;
};

} // namespace Internal
} // namespace StringManipulation
