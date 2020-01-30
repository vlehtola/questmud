#define REPAIR_COST	60;

inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "The city's smithy";
  long_desc = "Duranghom's smithy serves it's customers both as a weapon and a repair shop.\n"+
		"More than one smithes are working on the weapons they hold on anvils.\n"+
		"The air is hot and smoke covers the roof so that it is barely visible.\n"+
	      "Available commands: list, sell <item>, buy <item>, repair <item>\n";
  set_not_out(1);
  set_light(3);

  add_exit("east", "/world/city/emerald4");
  add_exit("north", "/guilds/fighter/smith");
  load_item("world/eq/weapons/battle_axe",2,6);
  load_item("world/eq/weapons/hand_axe",1,4);
  load_item("world/eq/weapons/mace",3,5);
  load_item("world/eq/weapons/maul",2,3);
  load_item("world/eq/weapons/shortsword",3,6);
  load_item("world/eq/weapons/shield",3,6);
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
    write("You don't have enough money for the repair. (Cost is "+cost+")\n");
    return 1;
  }
  ob->repair_weapon();
  this_player()->reduce_money(cost,3);
  write("The repair cost you "+cost+" bronze coins.\n");
  add_balance(cost);
  return 1;
}
