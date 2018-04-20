#include <boost/container/flat_map.hpp>
#include <boost/preprocessor/seq/for_each.hpp>

#include <ucenio/manifest/plugins.hpp>

namespace ucenio { namespace plugin {


std::shared_ptr< ucenio::app::abstract_plugin > create_raw_block_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_private_message_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_tags_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_follow_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_account_history_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_account_statistics_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_account_by_key_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_debug_node_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_witness_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_block_info_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_blockchain_statistics_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_market_history_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_delayed_node_plugin( ucenio::app::application* app );

std::shared_ptr< ucenio::app::abstract_plugin > create_auth_util_plugin( ucenio::app::application* app );


boost::container::flat_map< std::string, std::function< std::shared_ptr< ucenio::app::abstract_plugin >( ucenio::app::application* app ) > > plugin_factories_by_name;

void initialize_plugin_factories()
{
   
   plugin_factories_by_name[ "raw_block" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_raw_block_plugin( app );
   };
   
   plugin_factories_by_name[ "private_message" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_private_message_plugin( app );
   };
   
   plugin_factories_by_name[ "tags" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_tags_plugin( app );
   };
   
   plugin_factories_by_name[ "follow" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_follow_plugin( app );
   };
   
   plugin_factories_by_name[ "account_history" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_account_history_plugin( app );
   };
   
   plugin_factories_by_name[ "account_statistics" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_account_statistics_plugin( app );
   };
   
   plugin_factories_by_name[ "account_by_key" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_account_by_key_plugin( app );
   };
   
   plugin_factories_by_name[ "debug_node" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_debug_node_plugin( app );
   };
   
   plugin_factories_by_name[ "witness" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_witness_plugin( app );
   };
   
   plugin_factories_by_name[ "block_info" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_block_info_plugin( app );
   };
   
   plugin_factories_by_name[ "blockchain_statistics" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_blockchain_statistics_plugin( app );
   };
   
   plugin_factories_by_name[ "market_history" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_market_history_plugin( app );
   };
   
   plugin_factories_by_name[ "delayed_node" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_delayed_node_plugin( app );
   };
   
   plugin_factories_by_name[ "auth_util" ] = []( ucenio::app::application* app ) -> std::shared_ptr< ucenio::app::abstract_plugin >
   {
      return create_auth_util_plugin( app );
   };
   
}

std::shared_ptr< ucenio::app::abstract_plugin > create_plugin( const std::string& name, ucenio::app::application* app )
{
   auto it = plugin_factories_by_name.find( name );
   if( it == plugin_factories_by_name.end() )
      return std::shared_ptr< ucenio::app::abstract_plugin >();
   return it->second( app );
}

std::vector< std::string > get_available_plugins()
{
   std::vector< std::string > result;
   for( const auto& e : plugin_factories_by_name )
      result.push_back( e.first );
   return result;
}

} }