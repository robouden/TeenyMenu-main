// Macro constant (alias) for supported length of the string (character sequence) variable of type char[TEENYMENU_STR_LEN]
#define TEENYMENU_STR_LEN 17

// Macro constants (aliases) for supported types of associated with menu item variable
#define TEENYMENU_VAL_INTEGER 0  // Associated variable is of type int
#define TEENYMENU_VAL_INT32T  1  // Associated variable is of type int32_t
#define TEENYMENU_VAL_BYTE    2  // Associated variable is of type byte
#define TEENYMENU_VAL_BOOLEAN 3  // Associated variable is of type boolean
#define TEENYMENU_VAL_SELECT  4  // Associated variable is either of type int, byte or char[] with option select used to pick a predefined value from the list
                                 // (note that char[] array should be big enough to hold select option with the longest value)

