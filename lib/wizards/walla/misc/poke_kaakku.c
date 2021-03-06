#include <ansi.h>
inherit "obj/food";

void reset(status x) {
  ::reset(x);
  if (x) { return; }
  set_name("kaakku");
  set_alias("synttärikaakku");
  set_short("Poke's synttärikaakku");
  set_long("This is Poke's synttärikaakku, you can see the beautiful candles.\n");
  set_weight(10);
  set_value(-500);
  set_strength(1000000);
}

void init() {
  add_action("blow_candles","blow");
}

status blow_candles(string str) {
  if(str != "candles") {
    write("Blow what?\n");
    return 1;
  }
  say(this_player()->query_name()+" blows all of the candles!\n");
  write("You blow all of the candles!\n");
  shout("HAPPY BIRTHDAY Poke!!!\n");
  write("The candles magically light up again. Darn :D\n");
  return 1;
}
