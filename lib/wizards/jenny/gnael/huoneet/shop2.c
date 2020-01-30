inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "The city armoury";
  long_desc = "You have arrived into Gnael's armoury. There are\n"+
              "many kind of armours hanged on the walls and the\n"+
              "air smells like rust and oil.\n"+
              "Available commands: list, sell <item>, buy <item>, peek <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("west", "/wizards/jenny/gnael/huoneet/city51.c");
  load_item("wizards/jenny/gnael/rojut/silk_shirt",2,6);
  load_item("wizards/jenny/gnael/rojut/trousers",3,4);
  load_item("wizards/jenny/gnael/rojut/robe",3,5);
  load_item("wizards/jenny/gnael/rojut/shirt",2,3);
  load_item("wizards/jenny/gnael/rojut/leather_armour",2,4);
  load_item("wizards/jenny/gnael/rojut/worn_trousers",1,2);
  load_item("wizards/jenny/gnael/rojut/clean_trousers",3,2);
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
