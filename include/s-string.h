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

    int len();
    const char * c_str();

  private:
    char * value;
    int length;

    void init(char * value, int len){
      length = len;
      this->value = new char[len + 1];
      strncpy(this->value, value, len);
      this->value[len] = '\0';
    }

};

}
