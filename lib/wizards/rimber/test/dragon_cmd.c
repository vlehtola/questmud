
string str;
object drg;

void cmd_dragon(string tmp) { str = tmp; }

status cmd_d(object obju) {
   drg = obju;
  object ob;
  object item_o;
  string target, who;
 if(str == "follow") {
  tell_room(environment(this_player()), "Dragon booms: 'I will follow you Master.'\n");
  drg->setFollowMode(1);
  return 1;
 }
 else if(str == "stay") {
  tell_room(environment(this_player()), "Dragon booms: 'I will stay here Master.'\n");
  drg->setFollowMode(0);
  return 1;
 }

// DISMISS DRAGON
 else if(str == "dismiss") {
 tell_room(environment(this_player()), "Dragon booms: 'If that's your command Master.\n");
 tell_room(environment(drg), "Dragon flies away.\n");
  destruct(drg);
  return 1;
 }
// ATTACK
 else if(sscanf(str, "attack %s", target) == 1) {
  if(find_player(target)) {
  tell_room(environment(drg), "Dragon booms: 'I won't kill players, Master!'\n");
   return 1;
  }
 if(environment(drg)->query_property("no_kill")) {
   tell_room(environment(drg), "Dragon booms: 'I cannot attack here Master.'\n");
   return 1;
 }

  ob = present(lower_case(target), environment(drg));
  if(!ob) {
   tell_room(environment(drg), "Dragon booms: 'I don't see "+capitalize(target)+" here Master.'\n");
   return 1;
  }
  else if(!living(ob)) {
   tell_room(environment(drg), "Dragon booms: '"+capitalize(target)+" is not living thing.'\n");
   return 1;
  }
  else if(ob == drg) {
   tell_room(environment(drg), "Dragon booms: 'I won't do that Master.'\n");
   return 1;
  }
  else if(ob == drg->query_attacker()) {
   tell_room(environment(drg), "Dragon booms: 'I'm already killing that one!'\n");
   return 1;
 }
  tell_room(environment(drg), "Dragon booms: 'As you wish Master.'\n");
  tell_room(environment(drg), "Dragon attacks "+ob->query_name()+"!\n");
  drg->attack_object(ob);
  return 1;
 }
 // END ATTACK

	// HELP
else if(str == "help") {
  write("Dragon's commands:\n"+
 "'alias <arg>'\t\t To give your dragon individual name.\n"+
 "'follow'\t\t Makes dragon to follow you.\n"+
 "'stay'\t\t\t Makes your dragon stop following.\n"+
 "'eat corpse'\t\t Dragon eats corpse.\n"+
 "'inventory'\t\t To show what your dragon carries.\n"+
 "'get <arg>'\t\t Dragon takes specific item from the ground.\n"+
 "'drop <arg>'\t\t Dragon drops specific item.\n"+
 "'give <arg> to <target>' Dragon give something to someone.\n"+
 "'attack <target>'\t Makes dragon to attack given target.\n"+
 "'dismiss'\t\t The dragon leaves.\n"+
 "'help'\t\t\t This help.\n"+
 "------------------------\n");
} // END HELP

 // EAT CORPSE
 if(sscanf(str, "eat %s", target) == 1) {
 if(drg->query_attacker()) {
  tell_room(environment(drg), "Dragon booms: 'Can't you see I'm fighting!'\n");
  return 1;
 }
 ob = present(target, environment(drg));
 if(!ob) {
   tell_room(environment(drg), "Dragon booms: 'There isn't such a thing in here Master.'\n");
   return 1;
 }
 if(!ob->query_corpse()) {
   tell_room(environment(drg), "Dragon booms: 'I eat only corpses.'\n");
   return 1;
 }
   tell_room(environment(drg), "Dragon eats "+ob->short()+".\n");
   destruct(ob);
   return 1;
 }
  // END EAT CORPSE

 // GET STAFF
  if(sscanf(str, "get %s", target) == 1) {
   if(target == "all") {
    object *obs, *to_take;
    int a = 0;
    string *list, lista;
    obs = all_inventory(environment(drg));
    to_take = allocate(sizeof(obs));
    list = allocate(sizeof(obs));
    for(int i = 0; i < sizeof(obs); i++) {
     if(obs[i]->get()) {
      to_take[a] = obs[i];
      list[a] = obs[i]->short();
      a++;
     }
    }
    lista = "/daemons/string_stack_d"->stack_item_list(list);
    tell_room(environment(drg), "Dragon takes " +lista+ ".\n");
    for(int i = 0; i < a; i++) { move_object(to_take[i], drg); }
    drg->fix_weight();
    return 1;
   }
   ob = present(target, environment(drg));
   if(!ob) {
    tell_room(environment(drg), "Dragon booms: 'I don't see that here Master.'\n");
    return 1;
   }
   if(!ob->get()) {
    tell_room(environment(drg), "Dragon booms: 'I can't take that, Master.'\n");
    return 1;
   }
   move_object(ob, drg);
   tell_room(environment(drg), "Dragon takes "+ob->short()+".\n");
   drg->fix_weight();
   return 1;
  }
  // END GET STAFF

     // DROP STAFF
  if(sscanf(str, "drop %s", target) == 1) {
   if(target == "all") {
    object *obs, *to_drop;
    string *list, lista;
    obs = all_inventory(drg);
    list = allocate(sizeof(obs));
    for(int i = 0; i < sizeof(obs); i++) {list[i] = obs[i]->short(); }
    lista = "/daemons/string_stack_d"->stack_item_list(list);
    tell_room(environment(drg), "Dragon drops " +lista+ ".\n");
    for(int i = 0; i < sizeof(obs); i++) { move_object(obs[i], environment(drg)); }
    drg->fix_weight();
    return 1;
  }
   ob = present(lower_case(target), drg);
   if(!ob) {
    tell_room(environment(drg), "Dragon booms: 'I don't have that Master.'\n");
    return 1;
   }
   tell_room(environment(drg), "Dragon drops "+ob->short()+".\n");
   move_object(ob, environment(drg));
   drg->fix_weight();
   return 1;
  }
    // END DROP STAFF
    // GIVE
  if(sscanf(str, "give %s to %s", target, who) == 2) {
   object ob_to;
   if(!target) {
    tell_room(environment(drg), "Dragon booms: 'What am I supposed to give?'\n");
    return 1;
   }
   if(!who) {
    tell_room(environment(drg), "Dragon booms: 'Give "+capitalize(target)+" to who?'\n");
    return 1;
   }
   if(who == "me") {
    who = drg->query_controller();
   }
  ob_to = present(lower_case(who), environment(drg));
   if(!ob_to) {
    tell_room(environment(drg), "Dragon booms: '"+capitalize(who)+" isn't here.'\n");
    return 1;
   }
  ob = present(lower_case(target), drg);
   if(!ob) {
    tell_room(environment(drg), "Dragon booms: 'I don't have that Master.'\n");
    return 1;
   }
   tell_room(environment(drg), "Dragon gives "+ob->short()+" to "+ob_to->query_name()+".\n");
   move_object(ob, ob_to);
   drg->fix_weight();
   ob_to->fix_weight();
   return 1;
  }
   // END GIVE

   // INVENTORY
  if(str == "inventory") {
   string *list, lista;
   object *obs;
   obs = all_inventory(drg);
   list = allocate(sizeof(obs));
   for(int i = 0;i < sizeof(obs);i++) {
    list[i] = obs[i]->short();
   }
   lista = "/daemons/string_stack_d"->stack_item_list(list);
  if(!lista) {
   write("Dragon speaks to you mentaly: 'I have nothing.'\n");
    return 1;
  }
   write("Dragon speaks to you mentaly: 'I have "+lista+".\n");
  return 1;
  }
   // END INVENTORY

   // GIVE ALIAS
  if(sscanf(str, "alias %s", who) == 1) {
   who = capitalize(who);
   drg->setAlias(who);
   tell_room(environment(drg), "Dragon booms: 'I'm now on known as "+drg->short()+".'\n");
   return 1;
  }
   // END ALIAS

   // DRAGON STATS
 if(str == "stats") {
  write("Dragon stats: Hp:"+ drg->query_hp() +"("+ drg->query_max_hp() +") SP: "+ drg->query_sp());
  write("("+ drg->query_max_sp() +") EP:"+ drg->query_ep() +"("+ drg->query_max_ep() +")\n");
  return 1;
 } // END DRAGON STATS

 if(str == "strena") {
  "/wizards/rimber/test/testi.c"->Strength(drg);
  int koe = "/wizards/rimber/test/testi.c"->GetStats(drg->query_level());
  tell_room(environment(drg), "My Strength is " + koe);
 return 1;
 }
 return 1;
}

