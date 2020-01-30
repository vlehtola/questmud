inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "The magic shop";
  long_desc = "You have arrived into a mystical looking magic shop.\n"+
              "Everywhere you look you can see magical items and\n"+
              "mystical looking scrolls\n"+
              "Available commands: list, sell <item>, buy <item>, peek <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("west", "/wizards/jenny/gnael/huoneet/city26.c");

  load_item("/guilds/obj/spellscroll",3,5);
  load_item("/world/eq/special/ring",1,2);
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

save_shop() {}
