/* ungettable reward eku */

inherit "obj/armour";

start() {
  set_desc("shining white divine");
  set_class(10);
  set_sub_type("scale mail");
  set_long("The scale mail seems to be blessed by some awesome force.\n"+
	"It looks quite unique in it's beauty. The strong scales fit\n"+
	"perfectly in their places but still they give up so much\n"+
	"that the wearer is almost not strained at all.\n"+
	"Some runes are carved on the scales that cover the right shoulder.\n");

  set_stats("str", 30);
  set_stats("dex", 10);
  set_stats("con", 20);
  set_stats("ac", 20);

  set_resists("fire", 25);
  set_resists("cold", 25);
  set_resists("electric", 35);
}

list_runes(string str) {
  if(str != "runes") return 0;
  if(this_player() != environment(this_object()) ) {
    write("You must posses the scale to see the runes.\n");
    return 1;
  }
  write("The runes say: 'The strong flex, the nimbles bow but those who worship last longer.'\n");
  return 1;
}

boost_str() {
  write("The plate starts humming for a while and then it stops.\n");
  set_stats("str", 30);
  set_stats("dex", 10);
  set_stats("con", 20);
  worn_by->update_stats();
  return 0;
}

boost_dex() {
  write("The plate starts humming for a while and then it stops.\n");
  set_stats("str", 20);
  set_stats("dex", 30);
  set_stats("con", 10);
  worn_by->update_stats();
  return 0;
}

boost_con() {
  write("The plate starts humming for a while and then it stops.\n");
  set_stats("str", 10);
  set_stats("dex", 20);
  set_stats("con", 30);
  worn_by->update_stats();
  return 0;
}

init() {
::init();
add_action("list_runes", "read");
add_action("boost_str", "flex");
add_action("boost_con", "worship");
add_action("boost_dex", "bow");
}

