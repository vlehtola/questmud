#define REPAIR_COST     60;

inherit "room/room";
inherit "room/shop_d";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "The weaponsmith";
  long_desc = "The weaponsmith of Amaranthgard. This place is\n"+
              "one of the most visited places in this city. It is\n"+
              "known everywhere that dwarves are the best ones\n"+
              "to handle steel and rock.\n"+
              "Available commands: list, sell <item>, buy <item>, peek <item>, repair <item>;\n";
  set_not_out(1);
  set_light(3);

  add_exit("east", "katu36.c");

  load_item("wizards/kaappi/dcity/items/ksword",3,5);
  load_item("wizards/kaappi/dcity/items/kaxe",2,5);
  load_item("wizards/kaappi/dcity/items/kaxe2",3,5);
  load_item("wizards/kaappi/dcity/items/kshield3",1,2);
  load_item("wizards/kaappi/dcity/items/kmaul",1,2);
  load_item("wizards/kaappi/dcity/items/kshield2",1,4);
  load_item("wizards/kaappi/dcity/items/kmace",2,4);
  load_item("wizards/kaappi/dcity/items/kshield",2,5);
  load_item("wizards/kaappi/dcity/items/ksword",1,3);
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
    write("You don't have enough money. (Cost is "+cost+")\n");
    return 1;
  }
  ob->repair_weapon();
  this_player()->reduce_money(cost,3);
  write("The repair cost you "+cost+" bronze coins.\n");
  add_balance(cost);
  return 1;
}

save_shop() {}
