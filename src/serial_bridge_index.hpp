//
//  serial_bridge_index.hpp
//  Copyright (c) 2014-2018, MyMonero.com
//
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification, are
//  permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//	conditions and the following disclaimer.
//
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//	of conditions and the following disclaimer in the documentation and/or other
//	materials provided with the distribution.
//
//  3. Neither the name of the copyright holder nor the names of its contributors may be
//	used to endorse or promote products derived from this software without specific
//	prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
//  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
//  THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
//  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//

#ifndef serial_bridge_index_hpp
#define serial_bridge_index_hpp
//
#include <string>
#include "cryptonote_config.h" 
//
namespace serial_bridge
{
	using namespace std;
	using namespace cryptonote;
	//
	// Bridging Functions - these take and return JSON strings
	string create_transaction(const string &args_string); // TODO: probably expose tx key as arg
	//
	string decode_address(const string &args_string);
	string is_subaddress(const string &args_string);
	string is_integrated_address(const string &args_string);
	//
	string new_integrated_address(const string &args_string);
	string new_fake_address_for_rct_tx(const string &args_string); // TODO: probably expose random scalar as arg
	string new_payment_id(const string &args_string);
	//
	string newly_created_wallet(const string &args_string); // TODO: probably expose random scalar as arg
	string mnemonic_from_seed(const string &args_string);
	string seed_and_keys_from_mnemonic(const string &args_string);
	string verified_components_for_login(const string &args_string);
	//
	string estimate_rct_size(const string &args_string);
	string calculate_fee(const string &args_string);
	// TODO: possibly add EstimatedTransaction_networkFee analog
	//
	string generate_key_image(const string &args_string);
	//
	// JSON values
	network_type nettype_from_string(const string &nettype_string);
	string string_from_nettype(network_type nettype);
	//
	// JSON keys - Ret vals
	// - - Error
	static inline string ret_json_key__any__err_msg() { return "err_msg"; } // optional
	static inline string ret_json_key__any__err_code() { return "err_code"; } // optional
	// - - Shared
	static inline string ret_json_key__generic_retVal() { return "retVal"; } 
	// - - create_transaction
	static inline string ret_json_key__create_transaction__serialized_signed_tx() { return "serialized_signed_tx"; }
	static inline string ret_json_key__create_transaction__tx_hash() { return "tx_hash"; }
	// - - decode_address
	static inline string ret_json_key__decode_address__pub_viewKey_string() { return "pub_viewKey_string"; }
	static inline string ret_json_key__decode_address__pub_spendKey_string() { return "pub_spendKey_string"; }
	static inline string ret_json_key__decode_address__paymentID_string() { return "paymentID_string"; } // optional
	static inline string ret_json_key__decode_address__isSubaddress() { return "isSubaddress"; }
	
	// JSON keys - Args
	// TODO:
	//	static inline string args_json_key__
}

#endif /* serial_bridge_index_hpp */
