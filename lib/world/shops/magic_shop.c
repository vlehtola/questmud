inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "The magic shop";
  long_desc = "This is the Duranghom's magic shop. You can buy and sell some special items in here.\n"+
	      "Available commands: list, sell <item>, buy <item>, peek <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("north", "/world/city/mainstr2");

  load_item("/guilds/obj/spellscroll",3,5);
  load_item("/world/eq/special/red_gloves",1,2);
}

init() {
  ::init();
  ::shop_commands();
}

can_sell(ob) {
  if (ob->query_stats("spregen") || ob->query_stats("int")) {
    return 1;
  }
  if (ob->short() != "An old and yellowed scroll") {
    write(ob->short() + " is not a scroll or a special item.\n");
    return 0;
  }
  return 1;
}
