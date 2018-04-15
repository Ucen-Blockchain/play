#pragma once

#include <ucenio/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace ucenio{ namespace app {
   struct api_context;
} }

namespace ucenio { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const ucenio::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // ucenio::account_statistics

FC_API( ucenio::account_statistics::account_statistics_api, )
