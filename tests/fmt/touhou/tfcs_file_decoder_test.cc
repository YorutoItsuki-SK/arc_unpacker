#include "fmt/touhou/tfcs_file_decoder.h"
#include "test_support/catch.hh"
#include "test_support/file_support.h"

using namespace au;
using namespace au::fmt::touhou;

TEST_CASE("Touhou TFCS files", "[fmt]")
{
    TfcsFileDecoder decoder;
    auto input_file = tests::file_from_path(
        "tests/fmt/touhou/files/tfcs/ItemCommon.csv");
    auto expected_file = tests::file_from_path(
        "tests/fmt/touhou/files/tfcs/ItemCommon-out.csv");
    auto actual_file = decoder.decode(*input_file);
    tests::compare_files(*expected_file, *actual_file, false);
}