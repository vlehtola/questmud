inherit "obj/monster";

int phase, cost, casting;

reset(arg) {
    int i;
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(90);
    set_name("khaland");
    set_alias("cleric");
    set_log();
    set_short("Khaland the friendly cleric");
    set_long(
"Khaland the cleric offers his services for money.\n"+
"Type 'services' to see what services are available.\n");
    set_al(100);
    set_al_aggr(400);
    set_gender(1);
    set_aggressive(0);
    set_special(33);
}

special_move() {
  object ob;
  ob = attacker_ob;
  if(!ob) return;
  tell_object(ob, "Khaland mumbles something as he hits you. You feel DRAINED!\n");
  ob->death();
}

init() {
  add_action("ask","ask");
  add_action("list", "services");

}

reinc_cost() {
	if(this_player()->query_rebirth() > 1) return 0;
  if(this_player()->query_level()<=50) return (this_player()->query_level()*10);
  if(this_player()->query_level()<=100) return (this_player()->query_level()*100);
  if(this_player()->query_level()<=150) return (this_player()->query_level()*200);
  return (this_player()->query_level())*300;
}

list() {
	
	int cost1, cost2;
	if(this_player()->query_rebirth() > 1 ) {
		cost1 = 0;
		cost2 = 0;
	} else {
		cost1 = 500;
		cost2 = 200;
	}
	
	write("  Available services ('ask for [service]'):\n"+
	"     remove scar                ("+cost1+" bronze coins)\n"+
	"     remove poison              ("+cost2+" bronze coins)\n"+
	"     change gender              ("+cost2+" bronze coins)\n"+
	"     change alignment to <what> ("+cost1+" bronze coins)\n"+
	"     free reincarnation         ("+reinc_cost()+" bronze coins)\n");
	return 1;
}


ask(string str) {
  string tmp;
  if (!str) { return; }
  if (!sscanf(str, "for %s", str)) {
    write("Ask for what?\n");
    return 1;
  }
  if (casting) { write("Khaland is busy, wait a moment.\n"); }
  if(this_player()->query_guest()) return 0;
  if (str == "remove scar") {
    remove_scar();
    return 1;
  }
  if (str == "remove poison") {
    remove_poison();
    return 1;
  }
  if (str == "change gender") {
    change_gender();
    return 1;
  }
  if (sscanf(str,"change alignment to %s",tmp)) {
    change_alignment(tmp);
    return 1;
  }
  if (str == "free reinc" || str == "free reincarnation") {
    free_reinc();
    return 1;
  }

  write("No such a service available.\n");
  return 1;
}

remove_scar() {
  int num;
  if(this_player()->query_rebirth() > 1 ) {
  	num = 0;
  } else {
  	num = 500;
  }
  if(this_player()->query_money(3) < num) {
    write("Khaland says: 'Sorry, but you don't have enough bronze coins.'\n");
    return 1;
  }
  this_player()->reduce_money(num,3);
  write("You hand "+num+" bronze coins to Khaland.\n");
  say("Khaland starts chanting.\n");
  casting = 1;
  call_out("resolve_scar", 10, this_player());
}

resolve_scar(tp) {
  say("Khaland is done with the chant.\n");
  casting = 0;
  if (environment(tp) != environment(this_object())) { return; }
  if(tp->remove_scar())
    tell_object(tp, "One of your scars vanishes!\n");
  else
    tell_object(tp, "Nothing happens.\n");
  return 1;
}

remove_poison() {
  int num;
  if(this_player()->query_rebirth() > 1 ) {
  	num = 0;
  } else {
  	num = 200;
  }
  if(this_player()->query_money(3) < num) {
    write("Khaland says: 'Sorry, but you don't have enough bronze coins.'\n");
    return 1;
  }
  this_player()->reduce_money(num,3);
  write("You hand "+num+" bronze coins to Khaland.\n");
  say("Khaland starts chanting.\n");
  casting = 1;
  call_out("resolve_poison", 2, this_player());
}

resolve_poison(tp) {
  int times;
  write("Khaland is done with the chant.\n");
  casting = 0;
  if (environment(tp) != environment(this_object())) { return; }
  while((present("poison_object", tp))) {
    present("poison_object", tp)->stop();
    tell_object(tp,"Khaland neutralizes the poison.\n");
    times += 1;
  }
  if (!times) {
    tell_object(tp,"Nothing happens.\n");
  }
  return 1;
}

change_gender() {
  int num;
  if(this_player()->query_rebirth() > 1 ) {
  	num = 0;
  } else {
  	num = 200;
  }
  if(this_player()->query_money(3) < num) {
    write("Khaland says: 'Sorry, but you don't have enough bronze coins.'\n");
    return 1;
  }
  this_player()->reduce_money(num,3);
  write("You hand "+num+" bronze coins to Khaland.\n");
  say("Khaland starts chanting.\n");
  casting = 1;
  call_out("resolve_gender", 10, this_player());
}

resolve_gender(tp) {
  write("Khaland is done with the chant.\n");
  casting = 0;
  if (environment(tp) != environment(this_object())) { return; }

  //Male to female
  if(tp->query_gender() == 1) {
    tp->set_gender(2);
    tell_object(tp,"You are now female.\n");
    return 1;
  }
  //Femalte/it to male
  else {
    tp->set_gender(1);
    tell_object(tp,"You are no male.\n");
    return 1;
  }
}

change_alignment(str) {
  int num;
  if(this_player()->query_rebirth() > 1 ) {
  	num = 0;
  } else {
  	num = 500;
  }
  if( str != "evil" && str != "good" && str != "neutral" ) {
    write("Khaland says: 'I can only change your alignment to evil, good or neutral.'\n");
    return 1;
  }
  if(this_player()->query_money(3) < num) {
    write("Khaland says: 'Sorry, but you don't have enough bronze coins.'\n");
    return 1;
  }
  this_player()->reduce_money(num,3);
  write("You hand "+num+" bronze coins to Khaland.\n");
  say("Khaland starts chanting.\n");
  casting = 1;
  call_out("resolve_alignment", 10, this_player(),str);
}

resolve_alignment(tp,str) {
  write("Khaland is done with the chant.\n");
  casting = 0;
  if (environment(tp) != environment(this_object())) { return; }

  if ( str == "evil" ) {
    tp->set_al(-50);
    tell_object(tp,"You are now evil.\n");
    return 1;
  } else if ( str == "good" ) {
    tp->set_al(50);
    tell_object(tp,"You are now good.\n");
    return 1;
  }
  else if ( str == "neutral" ) {
    tp->set_al(0);
    tell_object(tp,"You are now neutral.\n");
    return 1;
  } else {
    tell_object(tp,"Khaland fumbles the spell.\n");
    return 1;
  }
}

free_reinc() {
  cost = 0;
  if(!this_player()->query_tester()) cost = reinc_cost();
  if(this_player()->query_money(3) < cost) {
    write("Khaland says: 'Sorry, but the cost for you is "+cost+" bronze coins.'\n");
    return 1;
  }
  write("All items you are carrying will be dropped, proceed? [Y/n]\n");
  input_to("reinc_proceed");
  return 1;
}

reinc_proceed(str) {
  int i;
  object ob;
  if (str && str != "" && str != "y" && str != "Y" && str != "yes") {
    write("Reincarnation aborted.\n");
    return 1;
  }
  this_player()->reduce_money(cost,3);
  write("You hand "+cost+" bronze coins to Khaland.\n");
  say("Khaland starts chanting.\n");
  casting = 1;
  call_out("resolve_reinc", 15, this_player());
}

resolve_reinc(tp) {
  object ob;
  int i;

  say("Khaland is done with the chant.\n");
  casting = 0;
  if (environment(tp) != environment(this_object())) { return; }
  tell_object(tp,"Reincarnating..\n");

  tp->end_berserk();
  tp->save_me(1);
  if(!tp->reinc(0)) return 1;
  ob = all_inventory(this_player());
  while(i<sizeof(ob)) {
    if(ob[i] && ob[i]->short()) {
      if (!ob[i]->id("house key")) {
        /* force drop all. regardless of keep etc */
        move_object(ob[i], environment(tp));
        // Destruct guildleaderitems ++Celtron
        if(ob[i]->drop()) destruct(ob[i]);
      }
    }
    i += 1;
  }
  move_object(tp, "/obj/race_selection");
  tp->look();
}


query_ress_cost(ob) {
	if(ob->query_rebirth() > 1 ) return 0;
  return ob->query_level() * 40;
}

offer_ress(ob) {
  int cost;
  cost = query_ress_cost(ob);
  tell_object(ob, "Khaland tells you 'Type 'accept ress from khaland' if you wish to be resurrected. It will cost you "+cost+" bronze coins.'\n");
}



add_cleric_money(num) {
  object ob;
  if (!num) return;
  ob = clone_object("/obj/new_money");
  ob->set_type(3);
  ob->set_value(num);
  move_object(ob, this_object());
}
