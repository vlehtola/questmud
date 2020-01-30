/* recode by Celtron */

#define STACK_D "/daemons/string_stack_d"

status can_give_ob(object ob, object target) {
  if(this_player()->query_keep(ob))
	return 0;
  if(ob->drop())
	return 0;
  if(!target->add_weight(ob->query_weight() )) {
	write(target->query_name()+" cannot carry "+ob->short()+".\n");
	return 0;
  }
  return 1;
}

cmd_give(string str) {
  int i,n;
  object *item_ob, dest_ob;
  string gived, dest;
  object *livings;

  if (!this_player()->check_condis()) { return 1; }
  if (!str || sscanf(str, "%s to %s", str, dest) != 2) {
    write("Give what to whom?\n");
    return 1;
  }
  dest_ob = present(dest, environment(this_player()));
  if (!dest_ob) {
    write("There is no " + capitalize(dest) + " here.\n");
    return 1;
  }
  if (!living(dest_ob) || dest_ob == this_player()) {
    write("You can't do that.\n");
    return 1;
  }
  item_ob = call_other("/daemons/filter", "EQ_FILTER", str, this_player());
  if(!item_ob) {
    write("Nothing given.\n");
    return 1;
  }
  item_ob = filter(item_ob, "can_give_ob", this_object(), dest_ob);
  gived = "";
  for(i=0; i<sizeof(item_ob); i++) {
    if(item_ob[i]->query_worn()) item_ob[i]->stop_wearing(); 
    if(item_ob[i]->query_wielded()) item_ob[i]->unwield(0,1);
    move_object(item_ob[i], dest_ob);
    gived += item_ob[i]->short()+",";
  }
  this_player()->save_me(1); /* cheat stop */

  gived = STACK_D->stack_item_list(explode(gived, ","));

  // Altered by Nalle
  write("You give " + gived + " to " + capitalize(dest) + ".\n");

  livings = filter(all_inventory(environment(this_player())), #'living );

  for(n=0 ; n<sizeof(livings) ; n++)
  {
  gived = "";
   if(livings[n] != this_player())
    {
	for(i=0; i<sizeof(item_ob); i++) 
   	{
    		if(item_ob[i]->query_weapon() || item_ob[i]->query_armour())
       		 gived += item_ob[i]->target_short(livings[n])+",";
        	else
       		 gived += item_ob[i]->short()+",";
   	}
   gived = STACK_D->stack_item_list(explode(gived, ","));

    if(livings[n] != dest_ob)
     tell_object(livings[n],this_player()->query_name() + " gives " + gived + " to " + capitalize(dest)+"\n");
      else
     tell_object(livings[n],this_player()->query_name() + " gives " + gived + " to you.\n"); 
   }
  }

  if (this_player()->query_wiz() == 1) {
        log_file("GIVED_OB", extract(ctime(time()), 4, 15)+" Giver: " +
                this_player()->query_name() + ", Dest: "+dest_ob->query_name() + ", Item: " + gived + ".\n");
  }

/* For monsters to easier react on gives: */
  dest_ob->gived_you(item_ob);

  this_player()->fix_weight();
   dest_ob->fix_weight();
  return 1;
}   


