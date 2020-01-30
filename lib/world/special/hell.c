inherit "room/room";

reset() {
  short_desc = "Hell";
  long_desc = "You are in hell. You can 'pray' or try to get a resurrection.\n";
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
  set_not_out(1);
  set_light(3);
}

init() {
  ::init();
  if(!this_player()->query_wiz() && !this_player()->query_ghost())
    this_player()->death();
  add_action("accept", "accept");
  add_action("cost", "cost");
}
cost() {
        string cost;
    cost = call_other("/world/monsters/cleric","query_ress_cost",this_player());
    write("You ress cost from khaland is: " + cost +".\n");
    return 1;
}
accept(str) {
  int cost;
  string type, name;
  object ob, ob2;
  if (!str) { write("Syntax: 'accept [ress/reinc] from [name]'.\n"); return 1; }
  if (sscanf(str, "%s from %s", type, name) != 2) {
        write("Accept what from whom? Syntax: 'accept [ress/reinc] from [name]'.\n");
        return 1;
  }
  ob = find_player(name);
  if (!ob && name != "khaland") {
    write("No such a player.\n");
    return 1;
  }
  if (type == "ress") {
    if (lower_case(name) == "khaland") {
      cost = call_other("/world/monsters/cleric","query_ress_cost",this_player());
      if (call_other("/room/bank_d","query_money",3) < cost) {
        write("Khaland tells you 'Sorry, but you don't have enough money in bank'.\n");
        return 1;
      }
      if ( cost ) {
        call_other("/room/bank_d", "add_money", -cost, 3);
        call_other(find_object("/world/monsters/cleric"),"add_cleric_money", (cost/2));
      }
      write("Khaland tells you 'Good, resurrection fee "+cost+" bronze coins has been directly reduced from your bank account'.\n");
      this_player()->remove_ghost(70, "/guilds/channel/r02");
      return 1;
    }
  }
  if (!ob) { write("No such a player.\n"); return 1; }
  if (type == "reinc") {
        write("You accept reincarnation from "+capitalize(name)+".\n");
        tell_object(ob, capitalize(this_player()->query_real_name())+
                " accepts reincarnation from you.\n");
        ob2 = clone_object("/guilds/spell_obj/reinc_ob");
        ob2->set_accept(name);
        move_object(ob2, this_player());
        return 1;
  }

}
