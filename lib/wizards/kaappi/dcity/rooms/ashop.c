inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "The armour shop";
  long_desc = "This is the armour shop of Amaranthgard.\n"+
              "Many dwarves are working here. A lot of different\n"+
              "kind of armours are placed on the tables and walls.\n"+
              "Available commands: list, sell <item>, buy <item>, peek <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("south", "katu40.c");

  load_item("wizards/kaappi/dcity/items/karmour",1,2);
  load_item("wizards/kaappi/dcity/items/karmour2",2,2);
  load_item("wizards/kaappi/dcity/items/karmour3",1,4);
  load_item("wizards/kaappi/dcity/items/karmour4",3,3);
  load_item("wizards/kaappi/dcity/items/karmour5",1,2);
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

save_shop() {}
