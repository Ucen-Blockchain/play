
#pragma once

#include <ucenio/app/plugin.hpp>

namespace ucenio { namespace plugin { namespace raw_block {

using ucenio::app::application;

class raw_block_plugin : public ucenio::app::plugin
{
   public:
      raw_block_plugin( application* app );
      virtual ~raw_block_plugin();

      virtual std::string plugin_name()const override;
      virtual void plugin_initialize( const boost::program_options::variables_map& options ) override;
      virtual void plugin_startup() override;
      virtual void plugin_shutdown() override;
};

} } }
