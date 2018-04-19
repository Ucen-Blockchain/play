#pragma once
#include <ucenio/protocol/block_header.hpp>
#include <ucenio/protocol/transaction.hpp>

namespace ucenio { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // ucenio::protocol

FC_REFLECT_DERIVED( ucenio::protocol::signed_block, (ucenio::protocol::signed_block_header), (transactions) )
