object target;

set_target(ob) {
  if(stringp(ob)) target = find_player(ob);
  else target = ob;
  if(!target) {
    destruct(this_object());
    return 1;
  }
  tell_object(target, "You have a bad feeling that something is following you..\n");
  call_out("tic", 10);
}

tic(int num) {
  int i;
  object ob;
  if(!target) { destruct(this_object()); }
  if(environment(target) != environment(this_object())) {
    tell_room(environment(),"The ghost suddenly disappears.\n");
    move_object(this_object(), environment(target));
    tell_room(environment(),"A ghost appears from nowhere.\n");
    call_out("tic",2,num+1);
    return 1;
  }
  ob = all_inventory(target);
  if(num > random(6)+5) {
    if(sizeof(ob) <= 2) {
	tell_room(environment(),"As "+target->query_name()+" doesn't have any items that "+
	"the ghost would like, it eats "+target->query_objective()+" and is gone.\n");
	target->death();
	destruct(this_object());
	return 1;
    }
    while(!ob[i]->get() || !ob[i]->short()) {
      i = random(sizeof(ob));
    }
    tell_room(environment(),"Suddenly, the ghost flies towards "+target->query_name()+", eats "
	+ob[i]->short()+" and is gone.\n");
    destruct(ob[i]);
    destruct(this_object());
    return 1;    
  }
  i = random(5);
  if(i==0) tell_room(environment(),"The ghost stares greedily at "+target->query_name()+".\n");
  if(i==1) tell_room(environment(),"The ghost floats around "+target->query_name()+".\n");
  if(i==2) tell_room(environment(),"The ghost seems to wait for something.\n");
  if(i==3) tell_room(environment(),"Ghost's eyes flash for a moment.\n");
  if(i==4) tell_room(environment(),"The ghost moans in hunger.\n");  

  /* tune 7.2.2002 //Celtron */
  target->reduce_sp(500);
  tell_object(target, "You feel drained by the ghost's presence.\n");

  call_out("tic",random(7)+6,num+1);
}

id(str) { return str == "ghost"; }
short() { return "A hungry ghost stares at your equipment"; }

long() {
  write("It's not easy to see partially invisible ghost. However you notice\n"+
  "that it stares at your equipment and it sure looks hungry!\n"+
  "Maybe you should feed it with some not so valuable items, before\n"+
  "it does something stupid.\n"); 
}

init() {
  add_action("feed", "feed");
}

feed(str) {
  string tmp;
  object ob;
  if(!str) {
    write("Feed whom?\n");
    return 1;
  }
  if(sscanf(str, "ghost with %s", tmp) == 1) {
    ob = present(tmp, this_player());
    if(!ob) {
      write("You don't have any "+tmp+".\n");
      return 1;
    }
    if(ob->query_value() < 10 || !ob->query_ac() && !ob->query_wc()) {
      write("It seems like the ghost won't accept it.\n");
      return 1;
    }
    write("You throw "+tmp+" towards the ghost and they both disappear.\n");
    say(this_player()->query_name()+" throws "+tmp+" towards the ghost and they both disappear.\n");
    destruct(ob);
    destruct(this_object());
    return 1;
  } else {
    write("Feed ghost with what?\n");
    return 1;
  }
}
