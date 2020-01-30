#include <ansi.h>

status reset() {
  string str;
  str = BLUE_F+"Sininen ukkeli"+OFF;
  return this_player()->set_wiz_short(str);
}

