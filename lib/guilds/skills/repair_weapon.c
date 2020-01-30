/* editted by Celtron */

int get_time() {
    return 10;
}
int ep_cost() { return 10; }
query_type() { return "neutral"; }

void resolve_skill(string tgt) {
  object ob;
  int dmg;

  if(!tgt) {
    write("Repair what?\n");
    return;
  }
  ob = present(tgt,environment(this_player()));
  if(!ob) ob = present(tgt, this_player());
  if(!ob) {
    write("Repair what?\n");
    return;
  }
  if(environment(this_player())->guild_name() != "Smith") {
   write("You don't have the needed equipments to do it.\n");
   return;
 }
  /* the worse is the shape of weapon, the harder it is to repair */
  dmg = ob->query_dur()*this_player()->query_skill("repair weapon") / 100 + 1;
  ob->repair_weapon(dmg);
  say(this_player()->query_name()+" spends some time repairing "+ob->short()+".\n");
  if(ob->query_dur() < ob->query_max_dur())
	write("You spend some time in repairing "+ob->short()+" but are unable to restore it's best shape.\n");
  else
	write("You manage to repair "+ob->short()+" completely, leaving it ready to inflict death again.\n");
}

void fail_skill(string str) {
  if(this_player()->query_skill("repair weapon") > random(150))
	return resolve_skill(str);
  write("You fail to repair your weapon.\n");
}
