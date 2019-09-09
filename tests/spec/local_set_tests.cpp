#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <catch2/catch.hpp>
#include <utils.hpp>
#include <wasm_config.hpp>
#include <eosio/vm/backend.hpp>

using namespace eosio;
using namespace eosio::vm;
extern wasm_allocator wa;

BACKEND_TEST_CASE( "Testing wasm <local_set_0_wasm>", "[local_set_0_wasm_tests]" ) {
   using backend_t = backend<std::nullptr_t, TestType>;
   auto code = backend_t::read_wasm( std::string(wasm_directory) + "local_set.0.wasm");
   backend_t bkend( code );
   bkend.set_wasm_allocator( &wa );
   bkend.initialize(nullptr);

   CHECK(!bkend.call_with_return(nullptr, "env", "type-local-i32"));
   CHECK(!bkend.call_with_return(nullptr, "env", "type-local-i64"));
   CHECK(!bkend.call_with_return(nullptr, "env", "type-local-f32"));
   CHECK(!bkend.call_with_return(nullptr, "env", "type-local-f64"));
   CHECK(!bkend.call_with_return(nullptr, "env", "type-param-i32", UINT32_C(2)));
   CHECK(!bkend.call_with_return(nullptr, "env", "type-param-i64", UINT64_C(3)));
   CHECK(!bkend.call_with_return(nullptr, "env", "type-param-f32", bit_cast<float>(UINT32_C(1082969293))));
   CHECK(!bkend.call_with_return(nullptr, "env", "type-param-f64", bit_cast<double>(UINT64_C(4617878467915022336))));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-block-value", UINT32_C(0)));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-loop-value", UINT32_C(0)));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-br-value", UINT32_C(0)));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-br_if-value", UINT32_C(0)));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-br_if-value-cond", UINT32_C(0)));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-br_table-value", UINT32_C(0)));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-return-value", UINT32_C(0)));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-if-then", UINT32_C(1)));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-if-else", UINT32_C(0)));
   CHECK(!bkend.call_with_return(nullptr, "env", "type-mixed", UINT64_C(1), bit_cast<float>(UINT32_C(1074580685)), bit_cast<double>(UINT64_C(4614613358185178726)), UINT32_C(4), UINT32_C(5)));
   CHECK(bkend.call_with_return(nullptr, "env", "write", UINT64_C(1), bit_cast<float>(UINT32_C(1073741824)), bit_cast<double>(UINT64_C(4614613358185178726)), UINT32_C(4), UINT32_C(5))->to_ui64() == UINT32_C(56));
}

