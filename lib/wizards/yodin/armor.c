inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "Barthars armours.";
  long_desc = "You have arrived into village's armoury. There are\n"+
              "many fancy looking armours and table in front of you\n"+
              "everything is very clean and looks like there could be\n"+
              "many useful armours in here\n"+
              "Available commands: list, sell <item>, buy <item>, peek <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("west", "lksaf");
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
