#define REPAIR_COST     60;

inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "The weaponsmith";
  long_desc = "Gnael's smithy serves it's customers both as\n"+
              "a weapon and as a repair shop. Many smithes\n"+
              "are constantly working on the weapons they hold\n"+
              "on anvils. The air is extremely hot and a thick\n"+
              "smoke covers the roof so that it is barely visible.\n"+
              "Available commands: list, sell <item>, buy <item>, peek <item>, repair <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("east", "/wizards/jenny/gnael/huoneet/city51.c");
  load_item("wizards/jenny/gnael/rojut/battle_axe",2,6);
  load_item("wizards/jenny/gnael/rojut/hand_axe",1,4);
  load_item("wizards/jenny/gnael/rojut/mace",3,5);
  load_item("wizards/jenny/gnael/rojut/maul",2,3);
  load_item("wizards/jenny/gnael/rojut/short_sword",3,6);
  load_item("wizards/jenny/gnael/rojut/shield",3,6);
}

init() {
  ::init();
  ::shop_commands();
  add_action("repair_weapon", "repair");
}

can_sell(object ob) {
  if(ob->query_weapon()) {
    if(!ob->drop())
      return 1;
  }
}

repair_weapon(string weapon) {
  object ob;
  int cost;
  if(!weapon) return 0;
  ob = present(weapon, this_player());
  if(!ob) {
    write("You don't have such a weapon.\n");
    return 1;
  }
  cost = ob->query_class()*REPAIR_COST;
  if(this_player()->query_money(3) < cost) {
    write("You are too poor, go get cash kid! (Cost is "+cost+")\n");
    return 1;
  }
  ob->repair_weapon();
  this_player()->reduce_money(cost,3);
  write("The repair cost you "+cost+" bronze coins.\n");
  add_balance(cost);
  return 1;
}

save_shop() {}
