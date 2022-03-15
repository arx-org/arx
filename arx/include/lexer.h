#pragma once

#include <string>
#include <vector>

// The lexer returns tokens [0-255] if it is an unknown character, otherwise
// one of these for known things.
enum Token {
  tok_eof = -1,

  // commands
  tok_function = -2,
  tok_extern = -3,
  tok_return = -4,

  // primary
  tok_identifier = -10,
  tok_number = -11,

  // control
  tok_if = -20,
  tok_then = -21,
  tok_else = -22,
  tok_for = -23,
  tok_in = -24,

  // operators
  tok_binary = -30,
  tok_unary = -31,

  // var definition
  tok_var = -40,
  tok_const = -41
};

struct SourceLocation {
  int Line;
  int Col;
};

std::string getTokName(int);
int gettok();

class IOSource {
 public:
  static char* content; /* used for testing */
  static char getchar();
};

static SourceLocation CurLoc;
static SourceLocation LexLoc;
static std::string IdentifierStr;  // Filled in if tok_identifier
static double NumVal;              // Filled in if tok_number
