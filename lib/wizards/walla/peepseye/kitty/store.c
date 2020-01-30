inherit "room/room";  
inherit "room/shop_d";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "Ye Frontier Trading Post";
  long_desc = "This is OilOhnRocks Trading Post, which has however abandoned all business\n" +
                     "made by trade. You can buy things here.\n"+
              "Available commands: list, sell <item>, buy <item>\n";
  add_exit("north", "/wizards/walla/peepseye/kitty/m2");
  /* mita on varastossa, kuinka paljon, min ja max */
  load_item("world/eq/lantern",7,10);
  load_item("world/eq/torch",14,20);
  load_item("world/eq/oilbag",6,7);
  load_item("world/objects/shovel",7,12);
  
}
init() {
  ::init();
  ::shop_commands();
}
 
can_sell(ob) {
  /* mita voi myyda, returnaa ykkosen jos voi myyda ko ekun */
  /* ei suositeltavaa jollei tieda mita tekee */
  /* ei tarvita enempaa wepa / armor shoppeja mudiin */
  if(!ob->query_wc() && !ob->query_shield_factor() && !ob->query_ac()) {
    if(!ob->drop())
      return 1;
  }
}




