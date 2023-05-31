#include <gtest/gtest.h>
#include <memory>

#include "../src/codegen/ast-to-object.h"
#include "../src/io.h"

// Check object generation
TEST(CodeGenTest, ObjectGeneration) {
  string_to_buffer((char*) R""""(
  function add_one(a):
    a + 1

  add(1);
  )"""");

  auto ast = std::make_unique<TreeAST>(TreeAST());
  compile_object(*ast);
}