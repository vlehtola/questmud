#include "/sys/ansi.h"
inherit "obj/armour";
 start() {
  set_class(5);
  set_slot("boxers");
  set_name("boxers");
  set_short("ultra cool micky mouse boxers with"+BOLD+YELLOW_F+" yellow stripes"+OFF+"");
  set_long("vaatteita sulle ja vaatteita mulle");
  set_ac(10);
  set_value(25000);
  set_stats("str", 20);
  set_stats("con", 20);
  set_stats("dex", 20);
  set_stats("spr", 20);

}
