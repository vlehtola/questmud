#define REPAIR_COST     60;

inherit "room/room";
inherit "room/shop_d";
object mob;
reset(arg) {
if(!mob) {
 mob = clone_object("/wizards/yodin/areas/village/monsters/weapon");
 move_object(mob, this_object());
 }


  ::reset(arg);
  if(arg) return;
  short_desc = "The village's smithy";
  long_desc =   "You are standing in a small house. The walls are covered\n" +
				"with large shelves filled with different type of weapons\n" +
				"such as axes, maces, swords and daggers. At the northern\n" +
				"end of the shop there is a counter desk and a man standing\n" +
				"behind it. A large chandelier is hanging from the roof,\n" +
				"obviously planned as a light source for this place in night\n" +
				"times.\n" +
                "Available commands: list, sell <item>, buy <item>, peek <item>, repair <item>\n";

property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";

  set_light(3);

  add_exit("west", "vh17.c");
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

