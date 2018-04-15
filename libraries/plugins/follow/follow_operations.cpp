#include <ucenio/follow/follow_operations.hpp>

#include <ucenio/protocol/operation_util_impl.hpp>

namespace ucenio { namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } //ucenio::follow

DEFINE_OPERATION_TYPE( ucenio::follow::follow_plugin_operation )
