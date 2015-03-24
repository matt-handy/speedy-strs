#include "s-string.h"
#include <stdio.h>

using namespace speedystring;

size_t SString::len(){
  return length;
}

const char * SString::c_str(){
  return value;
}

bool SString::equals(SString other){
  if(this->length == other.length){
    for(size_t idx = 0; idx < this->length; idx++){
      if(this->value[idx] != other.value[idx]){
        return false;
      }
    }
    return true;
  }else{
    return false;
  }
}

bool SString::contains(SString other){
  bool foundLock = false;
  size_t currIdx = 0;
  size_t otherIdx = 0;
  
  if(other.length > this->length){
    return false;
  }

  while(currIdx < this->length && !foundLock){
    if(this->value[currIdx] == other.value[otherIdx]){
      otherIdx++;
      if(otherIdx == other.length){
        foundLock = true;
      }
    }else{
      otherIdx = 0;
      if((currIdx + other.length) > this->length){
        return false;
      }
    }
    currIdx++;
  }

  return foundLock;
}
