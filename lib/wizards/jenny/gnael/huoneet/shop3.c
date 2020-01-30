inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
//  load_item("world/eq/lantern",7,10);
  load_item("world/eq/torch",14,20);
  load_item("world/objects/shovel",7,12);
  load_item("world/objects/sack1",3,5);
  load_item("world/objects/sack2",5,7);
  load_item("world/objects/sack3",7,10);
  load_item("world/objects/money_purse",5,7);
  if(arg) return;
  short_desc = "The general store";
  long_desc = "You have entered the general store of Gnael.\n"+
              "There are all kind of tools in here and if you look\n"+
              "up you can see a marvelous looking chandelier hanging\n"+
              "from the ceilings.\n"+
              "Available commands: list, sell <item>, buy <item>, peek <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("south", "/wizards/jenny/gnael/huoneet/city26.c");
}

init() {
  ::init();
  ::shop_commands();
}

can_sell(ob) {
  string str, tmp;
  if(!ob->query_wc() && !ob->query_shield_factor() && !ob->query_ac()) {
    if(!ob->drop() && ob->query_value()) {
      return 1;
    }
  }
}

save_shop() {}
