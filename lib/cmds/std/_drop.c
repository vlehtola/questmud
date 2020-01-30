#define STACK_D "/daemons/string_stack_d"

cmd_drop(string str, object arg) {
  object item_o;
  int i;
  if (!this_player()->check_condis()) { return 1; }
  if (!str) { write("Drop what?\n"); return 1; }
  item_o = call_other("daemons/filter", "EQ_FILTER", str, this_player());
  if (arg) { /*Jos arg ni ottaa arraysta autoload itemit pois. (quit)*/
    while(i < sizeof(item_o)) {
      if (item_o[i]->query_auto_load()) { destruct(item_o[i]); }
      i += 1;
    }
  }
  if(!arg) arg = this_player();
  if(!item_o) {
    write("Nothing dropped.\n");
    return 1;
  }
  drop_all(item_o, arg);
  this_player()->fix_weight();
  return 1;
}

/* recoded //Celtron */

status can_drop_item(object ob) {
  int d;
  if(this_player()->query_keep(ob))
	return 0;
  if(!ob) return 0;
  d = ob->drop();
  if(!ob || d) return 0;
  ob->stop_wearing(1); //silently
  return 1;
}

drop_all(object *list, object pl) {
  int i,n;
  string *kamat, lista;
  string *livings;

  list = filter(list, "can_drop_item");
  kamat = allocate(sizeof(list));
  for(i=0; i < sizeof(list); i++) {
    kamat[i] = list[i]->short();
    move_object(list[i], environment(this_player() ));
  }
  lista = STACK_D->stack_item_list(kamat);
  if(!lista) {
    write("Nothing dropped.\n");
    return 1;
  }
  write("You drop "+lista+".\n");
 
  /*
  tell_room(environment(this_player()), 
	this_player()->query_name()+" drops "+lista+".\n", ({ this_player(), }) );
   */


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
	    }
	    else {
	    kamat[n] = list[n]->short();
	    }
	}
      lista = STACK_D->stack_item_list(kamat);
      tell_object(livings[i], this_player()->query_name()+" drops "+lista+".\n");
     }
   }

  this_player()->fix_weight();
  this_player()->update_stats();
  return 1;
}
