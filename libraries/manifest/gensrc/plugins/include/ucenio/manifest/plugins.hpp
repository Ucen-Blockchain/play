
#pragma once

#include <memory>
#include <string>
#include <vector>

namespace ucenio { namespace app {

class abstract_plugin;
class application;

} }

namespace ucenio { namespace plugin {

void initialize_plugin_factories();
std::shared_ptr< ucenio::app::abstract_plugin > create_plugin( const std::string& name, ucenio::app::application* app );
std::vector< std::string > get_available_plugins();

} }
