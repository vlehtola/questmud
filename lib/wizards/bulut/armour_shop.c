inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "Armoury";
  long_desc = "This is the Duranghom's armoury. You can buy and sell armor in here.\n"+
	      "Available commands: list, sell <item>, buy <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("north", "/world/city/diaeme2");
  load_item("world/eq/armours/bracers",2,6);
  load_item("world/eq/armours/gauntlets",3,4);
  load_item("world/eq/armours/helm",3,5);
  load_item("world/eq/armours/leggings",2,3);
  load_item("world/eq/armours/chainmail",2,4);
  load_item("world/eq/armours/platemail",1,2);
}

init() {
  ::init();
  ::shop_commands();
}

can_sell(ob) {
  if(ob->query_ac()) {
    if(!ob->drop())
      return 1;
  }
}
