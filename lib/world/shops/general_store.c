inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  /* mita on varastossa, kuinka paljon, min ja max */
  /* resetiss� lis�� kamaa varastoon */
//  load_item("world/eq/lantern",7,10);
  load_item("world/eq/torch",14,20);
  load_item("world/objects/shovel",7,12);
  load_item("world/objects/sack1",3,5);
  load_item("world/objects/sack2",5,7);
  load_item("world/objects/sack3",7,10);
  load_item("world/objects/money_purse",5,7);
  if(arg) return;
  short_desc = "The general store";
  long_desc = "This is the Duranghom's general store. You can buy and sell items in here.\n"+
	      "Available commands: list, sell <item>, buy <item>, peek <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("south", "/world/city/mainstr8");
}

init() {
  ::init();
  ::shop_commands();
}

can_sell(ob) {
  string str, tmp;
  /* mita voi myyda, returnaa ykkosen jos voi myyda ko ekun */
  /* ei suositeltavaa jollei tieda mita tekee */
  /* ei tarvita enempaa wepa / armor shoppeja mudiin */
  if(!ob->query_wc() && !ob->query_shield_factor() && !ob->query_ac()) {
    if(!ob->drop() && ob->query_value()) {
      return 1;
    }
  }
}
