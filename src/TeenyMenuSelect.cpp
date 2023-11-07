#include <Arduino.h>
#include "TeenyMenuSelect.h"
#include "TeenyMenuConstants.h"

TeenyMenuSelect::TeenyMenuSelect(byte length_, SelectOptionByte* options_)
  : _type(TEENYMENU_VAL_BYTE)
  , _length(length_)
  , _options(options_)
{ }

TeenyMenuSelect::TeenyMenuSelect(byte length_, SelectOptionInt* options_)
  : _type(TEENYMENU_VAL_INTEGER)
  , _length(length_)
  , _options(options_)
{ }

TeenyMenuSelect::TeenyMenuSelect(byte length_, SelectOptionInt32t* options_)
  : _type(TEENYMENU_VAL_INT32T)
  , _length(length_)
  , _options(options_)
{ }

byte TeenyMenuSelect::getType() {
  return _type;
}

byte TeenyMenuSelect::getLength() {
  return _length;
}

int TeenyMenuSelect::getSelectedOptionNum(void* variable) {
  SelectOptionByte*   optsByte   = (SelectOptionByte*)_options;
  SelectOptionInt*    optsInt    = (SelectOptionInt*)_options;
  SelectOptionInt32t* optsInt32t = (SelectOptionInt32t*)_options;
  boolean found = false;
  for (byte i=0; i<_length; i++) {
    switch (_type) {
      case TEENYMENU_VAL_BYTE:
        if (optsByte[i].val_byte == *(byte*)variable) { found = true; }
        break;
      case TEENYMENU_VAL_INTEGER:
        if (optsInt[i].val_int == *(int*)variable) { found = true; }
        break;
      case TEENYMENU_VAL_INT32T:
        if (optsInt32t[i].val_int32t == *(int32_t*)variable) { found = true; }
        break;
    }
    if (found) { return i; }
  }
  if (!found) { return -1; }
}

char* TeenyMenuSelect::getSelectedOptionName(void* variable) {
  int selectedOptionNum = getSelectedOptionNum(variable);
  return getOptionNameByIndex(selectedOptionNum);
}

char* TeenyMenuSelect::getOptionNameByIndex(int index) {
  const char* name;
  SelectOptionByte*   optsByte   = (SelectOptionByte*)_options;
  SelectOptionInt*    optsInt    = (SelectOptionInt*)_options;
  SelectOptionInt32t* optsInt32t = (SelectOptionInt32t*)_options;
  switch (_type) {
    case TEENYMENU_VAL_BYTE:
      name = (index > -1 && index < _length) ? optsByte[index].name : "";
      break;
    case TEENYMENU_VAL_INTEGER:
      name = (index > -1 && index < _length) ? optsInt[index].name : "";
      break;
    case TEENYMENU_VAL_INT32T:
      name = (index > -1 && index < _length) ? optsInt32t[index].name : "";
      break;
  }
  return const_cast<char*>(name);
}

void TeenyMenuSelect::setValue(void* variable, int index) {
  SelectOptionByte*   optsByte   = (SelectOptionByte*)_options;
  SelectOptionInt*    optsInt    = (SelectOptionInt*)_options;
  SelectOptionInt32t* optsInt32t = (SelectOptionInt32t*)_options;
  if (index > -1 && index < _length) {
    switch (_type) {
      case TEENYMENU_VAL_BYTE:
        *(byte*)variable = optsByte[index].val_byte;
        break;
      case TEENYMENU_VAL_INTEGER:
        *(int*)variable = optsInt[index].val_int;
        break;
      case TEENYMENU_VAL_INT32T:
        *(int32_t*)variable = optsInt32t[index].val_int32t;
        break;
    }
  }
}

