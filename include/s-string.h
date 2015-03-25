#ifndef SSTRING_HEADER
#define SSTRING_HEADER

#include <cstring>
#include <vector>

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

    SString(const SString& other){
      init(other.value, other.length);
    }

    virtual ~SString(){
      delete[] value;
    }

    size_t len();
    const char * c_str();
    bool equals(SString other);
    bool contains(SString other);
    bool empty();
    std::vector<SString> split(SString delim);

  private:
    char * value;
    size_t length;

    bool contains(SString other, int &start, int &stop);

    void init(char * value, int len){
      length = len;
      this->value = new char[len + 1];
      strncpy(this->value, value, len);
      this->value[len] = '\0';
    }

};

}
#endif
