inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  /* mita on varastossa, kuinka paljon, min ja max */
  /* resetiss^D lis^D^D kamaa varastoon */
  if(!present("zinuq")) {
    move_object(clone_object("/wizards/neophyte/swamp/zinuq"), this_object());
  }

  load_item("guilds/witch/obj/pouch",5,10);
  if(arg) return;
  short_desc = "The witch shop";
  long_desc = "This is the Zinuq private witch shop.\n"+
              "Whole shop is decorated with different witch things.\n"+
              "Available commands: list, sell <item>, buy <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("south", "/guilds/witch/witch");
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
