#include <ansi.h>
inherit "obj/food";

void reset(status x)
{

 ::reset(x);
  if (x) { return; }
  set_name("kakku");
  set_alias("syntt�rikaakku");
  set_short("moonshdw's syntt�rikaakku");
  set_long("This is moonshdw's syntt�rikakku, you can see 30 beautiful candles.\n");
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
  say(this_player()->query_name()+" blows all 30 candles!\n");
  write("You blow all 30 candles!\n");
  shout("HAPPY BIRTHDAY MOONSHDW!!!\n");
  write("The candles magically light up again. Darn :D\n");
  return 1;
}
