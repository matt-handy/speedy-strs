#ifndef SSTRING_HEADER
#define SSTRING_HEADER

#include <cstring>

namespace speedystring
{

class SString{

  public:
    SString(char * value){
      init(value, strlen(value));
    }

    SString(char * value, int len){
      init(value, len);
    }

    size_t len();
    const char * c_str();
    bool equals(SString other);
    bool contains(SString other);

  private:
    char * value;
    size_t length;

    void init(char * value, int len){
      length = len;
      this->value = new char[len + 1];
      strncpy(this->value, value, len);
      this->value[len] = '\0';
    }

};

}
#endif
