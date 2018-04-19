#pragma once

#include <ucenio/chain/evaluator.hpp>

#include <ucenio/private_message/private_message_operations.hpp>
#include <ucenio/private_message/private_message_plugin.hpp>

namespace ucenio { namespace private_message {

DEFINE_PLUGIN_EVALUATOR( private_message_plugin, ucenio::private_message::private_message_plugin_operation, private_message )

} }
