#include "s-string.h"

using namespace speedystring;

int SString::len(){
  return length;
}

const char * SString::c_str(){
  return value;
}
