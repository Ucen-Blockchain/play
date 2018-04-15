#include <ucenio/witness/witness_operations.hpp>

#include <ucenio/protocol/operation_util_impl.hpp>

namespace ucenio { namespace witness {

void enable_content_editing_operation::validate()const
{
   chain::validate_account_name( account );
}

} } // ucenio::witness

DEFINE_OPERATION_TYPE( ucenio::witness::witness_plugin_operation )
