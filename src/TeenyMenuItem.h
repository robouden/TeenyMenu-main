#include "TeenyMenuConstants.h"
#include "TeenyMenuPage.h"

#ifndef HEADER_TEENYMENUITEM
#define HEADER_TEENYMENUITEM

// Macro constants (aliases) for menu item types
#define TEENYMENU_ITEM_VAL 0     // Menu item represents associated variable
#define TEENYMENU_ITEM_LINK 1    // Menu item represents link to another menu page
#define TEENYMENU_ITEM_BACK 2    // Menu item represents Back button
#define TEENYMENU_ITEM_BUTTON 3  // Menu item represents button for calling of user-defined function
#define TEENYMENU_ITEM_LABEL 4   // Non-functional (readonly) Menu item

// Macro constant (alias) for readonly modifier of associated with menu item variable
#define TEENYMENU_READONLY true

// Macro constant (alias) for hidden state of the menu item
#define TEENYMENU_HIDDEN true

// Forward declaration of necessary classes
class TeenyMenuPage;
class TeenyMenuSelect;

// Declaration of TeenyMenuItem class
class TeenyMenuItem {
  template <class T>
  friend class TeenyMenu;
  friend class TeenyMenuPage;
  public:
    /* 
      Constructors for menu item that represents option select, w/ callback
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*)
      @param 'select_' - reference to TeenyMenuSelect option select
      @param 'saveAction_' - pointer to callback function executed when associated variable is successfully saved
    */
    TeenyMenuItem(const char* title_, byte& linkedVariable_, TeenyMenuSelect& select_, void (*saveAction_)());
    TeenyMenuItem(const char* title_, int& linkedVariable_, TeenyMenuSelect& select_, void (*saveAction_)());
    TeenyMenuItem(const char* title_, int32_t& linkedVariable_, TeenyMenuSelect& select_, void (*saveAction_)());
    /* 
      Constructors for menu item that represents option select, w/o callback
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*)
      @param 'select_' - reference to TeenyMenuSelect option select
      @param 'readonly_' (optional) - set readonly mode for variable that option select is associated with
      values TEENYMENU_READONLY (alias for true)
      default false
    */
    TeenyMenuItem(const char* title_, byte& linkedVariable_, TeenyMenuSelect& select_, boolean readonly_ = false);
    TeenyMenuItem(const char* title_, int& linkedVariable_, TeenyMenuSelect& select_, boolean readonly_ = false);
    TeenyMenuItem(const char* title_, int32_t& linkedVariable_, TeenyMenuSelect& select_, boolean readonly_ = false);
    /* 
      Constructors for menu item that represents variable, w/ callback
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*, boolean)
      @param 'saveAction_' - pointer to callback function executed when associated variable is successfully saved
    */
    TeenyMenuItem(const char* title_, byte& linkedVariable_, void (*saveAction_)());
    TeenyMenuItem(const char* title_, int& linkedVariable_, void (*saveAction_)());
    TeenyMenuItem(const char* title_, int32_t& linkedVariable_, void (*saveAction_)());
    TeenyMenuItem(const char* title_, boolean& linkedVariable_, void (*saveAction_)());
    /* 
      Constructors for menu item that represents variable, w/ callback, w/ min/max range
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*, boolean)
      @param 'rangeMin_' - range minimum value
      @param 'rangeMax_' - range maximum value
      @param 'saveAction_' - pointer to callback function executed when associated variable is successfully saved
    */
    TeenyMenuItem(const char* title_, byte& linkedVariable_, byte& rangeMin_, byte& rangeMax_, void (*saveAction_)());
    TeenyMenuItem(const char* title_, int& linkedVariable_, int& rangeMin_, int& rangeMax_, void (*saveAction_)());
    TeenyMenuItem(const char* title_, int32_t& linkedVariable_, int32_t& rangeMin_, int32_t& rangeMax_, void (*saveAction_)());
    /* 
      Constructors for menu item that represents variable, w/o callback
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*, boolean)
      @param 'readonly_' (optional) - set readonly mode for variable that menu item is associated with
      values TEENYMENU_READONLY (alias for true)
      default false
    */
    TeenyMenuItem(const char* title_, byte& linkedVariable_, boolean readonly_ = false);
    TeenyMenuItem(const char* title_, int& linkedVariable_, boolean readonly_ = false);
    TeenyMenuItem(const char* title_, int32_t& linkedVariable_, boolean readonly_ = false);
    TeenyMenuItem(const char* title_, boolean& linkedVariable_, boolean readonly_ = false);
    /* 
      Constructors for menu item that represents variable, w/o callback, w/ min/max range
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*, boolean)
      @param 'rangeMin_' - range minimum value
      @param 'rangeMax_' - range maximum value
      @param 'readonly_' (optional) - set readonly mode for variable that menu item is associated with
      values TEENYMENU_READONLY (alias for true)
      default false
    */
    TeenyMenuItem(const char* title_, byte& linkedVariable_, byte& rangeMin_, byte& rangeMax_, boolean readonly_ = false);
    TeenyMenuItem(const char* title_, int& linkedVariable_, int& rangeMin_, int& rangeMax_, boolean readonly_ = false);
    TeenyMenuItem(const char* title_, int32_t& linkedVariable_, int32_t& rangeMin_, int32_t& rangeMax_, boolean readonly_ = false);
    /* 
      Constructor for menu item that represents link to another menu page (via reference)
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedPage_' - reference to TeenyMenuPage menu page that menu item is associated with
      @param 'readonly_' (optional) - set readonly mode for the link (user won't be able to navigate to linked page)
      values TEENYMENU_READONLY (alias for true)
    */
    TeenyMenuItem(const char* title_, TeenyMenuPage& linkedPage_, boolean readonly_ = false);
    /* 
      Constructor for menu item that represents link to another menu page (via pointer)
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedPage_' - pointer to TeenyMenuPage menu page that menu item is associated with
      @param 'readonly_' (optional) - set readonly mode for the link (user won't be able to navigate to linked page)
      values TEENYMENU_READONLY (alias for true)
    */
    TeenyMenuItem(const char* title_, TeenyMenuPage* linkedPage_, boolean readonly_ = false);
    /* 
      Constructor for menu item that represents returning to the previous/parent menu page
      @param 'readonly_' (optional) - set readonly mode for the link (user won't be able to navigate to previous/parent page)
      values TEENYMENU_READONLY (alias for true)
    */
    TeenyMenuItem(boolean readonly_ = false);
    /* 
      Constructor for menu item that represents button
      @param 'title_' - title of the menu item displayed on the screen
      @param 'buttonAction_' - pointer to function that will be executed when menu item is activated
      @param 'readonly_' (optional) - set readonly mode for the button (user won't be able to call action associated with it)
      values TEENYMENU_READONLY (alias for true)
    */
    TeenyMenuItem(const char* title_, void (*buttonAction_)(), boolean readonly_ = false);
    /* 
      Constructor for menu item that represents a non-functional (readonly) text item
      @param 'title_' - title of the menu item displayed on the screen
    */
    TeenyMenuItem(const char* title_);

    void setTitle(const char* title_);            // Set title of the menu item
    const char* getTitle();                       // Get title of the menu item
    void setReadonly(boolean mode = true);  // Explicitly set or unset readonly mode for variable that menu item is associated with
                                            // (relevant for TEENYMENU_VAL_INTEGER, TEENYMENU_VAL_BYTE, TEENYMENU_VAL_BOOLEAN
                                            // variable menu items and TEENYMENU_VAL_SELECT option select), or menu button TEENYMENU_ITEM_BUTTON
                                            // and menu link TEENYMENU_ITEM_LINK/BACK, pressing of which won't result in any action, associated with them
    boolean getReadonly();                  // Get readonly state of the variable that menu item is associated with (as well as menu link or button)
    void hide(boolean hide = true);         // Explicitly hide or show menu item
    void show();                            // Explicitly show menu item
    boolean isHidden();                     // Get hidden state of the menu item
  private:
    const char* title;
    byte type;
    void* linkedVariable;
    byte linkedType;
    void* rangeMin;
    void* rangeMax;
    boolean readonly = false;
    boolean hidden = false;
    TeenyMenuSelect* select;
    TeenyMenuPage* parentPage = nullptr;
    TeenyMenuPage* linkedPage;
    TeenyMenuItem* menuItemNext;
    TeenyMenuItem* getMenuItemNext();             // Get next menu item, excluding hidden ones
    void (*buttonAction)();
    void (*saveAction)();
};

#endif

