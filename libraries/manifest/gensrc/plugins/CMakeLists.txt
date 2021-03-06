
# The steemit_plugins target links with all plugins
add_library( steemit_plugins
   plugins.cpp )

target_link_libraries( steemit_plugins

   steemit_raw_block

   steemit_private_message

   steemit_tags

   steemit_follow

   steemit_account_history

   steemit_account_statistics

   steemit_account_by_key

   steemit_debug_node

   steemit_witness

   steemit_block_info

   steemit_blockchain_statistics

   steemit_market_history

   steemit_delayed_node

   steemit_auth_util

)

# The `steemit_mf_plugins` target has prototypes for querying plugins
# as abstract, but does not itself define the plugins.
#
# The reason for this design is that if we try to use `plugins`
# we will have this circular dependency:
#
# ```
# xxx_plugin ===> steemit::app ===> plugins ===> xxx_plugin
# ```
#
# To break the dependency, we create `mf_plugins` which only
# has a "weak" reference to the plugin:
#
# ```
# xxx_plugin ===> steemit::app ===> mf_plugins ---> xxx_plugin
# ```
#
# This weak reference is implemented by a declaring a
# `create_xxx_plugin()` global function which returns a
# `shared_ptr< abstract_plugin >`.  The weak reference isn't
# resolved until link time.  So as long as we link with both
# `steemit_mf_plugins` and `steemit_plugins` we are fine.
#

add_library( steemit_mf_plugins
   mf_plugins.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/ucenio/manifest/plugins.hpp
)

target_include_directories( steemit_mf_plugins
   PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
   )
target_link_libraries( steemit_mf_plugins fc )

INSTALL( TARGETS
   steemit_mf_plugins

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)