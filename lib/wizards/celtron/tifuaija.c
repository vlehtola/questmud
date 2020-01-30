inherit "obj/monster";
int c_action;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_level(3);
  set_name("citizen");
  set_alias("thief");
  set_short("A poor citizen");
  move_object(clone_object("/wizards/celtron/dagger"),this_object());
  init_command("wield dagger");
  set_dex(300);
  set_hp(1000);
  set_max_hp(1000);
  set_move_at_reset(1);
  set_skill("tumble", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_dead_ob(this_object());
}

monster_died() {
  object ob;
  ob = attacker_ob;
  if(!ob) ob = previous_object();
  if(!ob) ob = this_object();
  log_file("TIFU", ctime(time())+" thief got killed by "+ob->query_name()+".\n");
}

catch_tell(arg) {
  string tmp,tmp2,tmp3;
  int i;
  object ob;
  if(sscanf(arg, "%s arrives%s", tmp,tmp2) != 2) return;
  ob = find_player(tmp);
  if(!ob) return;
  if(c_action) return;
  c_action = 1;
  call_out("action", 4, ob);
}

action(object ob) {
  int i;
  object item;
  string str;
  c_action = 0;
  i = random(3);
  str = "";
  if(i==0) {
    tell_object(ob, "You feel something sharp penetrating your ribs as someone\n"+
		"stabs you in back! OUCH!\n");
    say(short()+" closes near "+ob->query_name()+"'s back.\n",ob);
    ob->hit_with_spell(800);
    if(ob->query_ghost()) { str = "died "; }
    log_file("TIFU", ctime(time())+" victim: "+ob->query_name()+" "+str+"(backstab)\n");
  }
  if(i==1) {
    tell_object(ob, "You feel like your equipment is getting lighter.\n");
    say(short()+" sneaks behind "+ob->query_name()+" and takes something from "+
	ob->query_objective()+"!\n",ob);
    item = all_inventory(ob);
    item = item[random(sizeof(item))];
    move_object(item, this_object());
    ob->update_stats();
    ob->fix_weight();
    log_file("TIFU", ctime(time())+" victim: "+ob->query_name()+" eq: "+item->short()+" (stolen)\n");
  }
  if(i==2) {
    item = all_inventory(this_object());
    item = item[random(sizeof(item))];
    if(!item) return;
    tell_object(ob, short()+" gives you "+item->short()+".\n");
    say(short()+" gives "+item->short()+" to "+ob->query_name()+".\n",ob);
    move_object(item, ob);
    log_file("TIFU", ctime(time())+" victim: "+ob->query_name()+" eq: "+item->short()+" (gived)\n");
  }
  call_out("action", 20);
}
