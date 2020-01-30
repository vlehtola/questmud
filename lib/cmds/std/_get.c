/* recode by Celtron */

#define STACK_D "/daemons/string_stack_d"

cmd_get(string str) {
  string item;
  string container;
  object item_o, ob, pl;
  pl = this_player();
  if (!pl->check_condis()) { return 1; }
  if (!str) {
    write("Take what?\n");
    return 1;
  }
  if (sscanf(str, "%s from %s", str, container) == 2) {
    ob = present(container, pl);
    if(!ob) ob = present(container, environment(pl));
    if (!ob) {
      write("There is no " + container + " here.\n");
      return 1;
    }
    if (!call_other(ob, "can_put_and_get", 0)) {
      write("You can't do that!\n");
      return 1;
    }
  }
  if (!ob) { ob = environment(pl); }
  item_o = call_other("/daemons/filter", "EQ_FILTER", str, ob);
  if(!item_o) {
    write("Nothing taken.\n");
    return 1;
  }
  get_all(item_o, pl, ob);
  pl->fix_weight();
  return 1;
}

status can_get_item(object ob) {
  if(!ob->get()) return 0;
  if(!this_player()->add_weight(ob->query_weight() )) {
	write("You cannot carry "+ob->short()+".\n");
	return 0;
  }
  return 1;
}

get_all(object *list, object pl, object container_ob) {
  int i,n;
  string *kamat, lista;
  string *livings;
  
  list = filter(list, "can_get_item");
  kamat = allocate(sizeof(list));
  for(i=0; i < sizeof(list); i++) {
    kamat[i] = list[i]->short();
    move_object(list[i], this_player());
    if(container_ob) container_ob->add_weight( - list[i]->query_weight());
  }
  lista = STACK_D->stack_item_list(kamat);
  if(!lista) {
    write("Nothing taken.\n");
    return 1;
  }
  write("You take "+lista+".\n");

  // Loop for environment-colour compatibility -- N

  livings = filter(all_inventory(environment(this_player())), #'living );

   for(i=0; i < sizeof(livings); i++)
   {
    if(livings[i]!=this_player())
     {
        for(n=0; n < sizeof(list); n++)
        {
         if(list[n]->query_weapon() || list[n]->query_armour()) {
            kamat[n] = list[n]->target_short(livings[i]);
            } else {
            kamat[n] = list[n]->short();
	    }
	  }
	  lista = STACK_D->stack_item_list(kamat);
      tell_object(livings[i], this_player()->query_name()+" takes "+lista+".\n");
     }
   }

  /*
  tell_room(environment(this_player()), this_player()->query_name()+" takes "+lista+".\n", ({ this_player(), }) );
   */

  if(container_ob->automatic_weight()) 
   {
     container_ob->calc_weight();
   }

  return 1;
}
