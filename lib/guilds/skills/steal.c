get_time() { return 5; }
query_type() { return "neutral"; }

resolve_skill(target, arg) {
  object ob, nonwear;
  int i, ii;
  string item;
  ob = all_inventory(present(target,environment(this_player())));
  if (!ob || !first_inventory(target)) {
   write("You notice that "+capitalize(target->query_name())+"'s backpack is empty.\n");
   return 1;
  }
  if (arg) {
    if (sscanf(arg, "take %s", item) == 1) {
      nonwear = present(item, target);
      if (nonwear && !nonwear->drop()) {
	if (nonwear->query_worn() && nonwear->query_wielded()) {
	  write("You cannot steal weared items.\n");
	  tell_object(target, capitalize(this_player()->query_name())+
		      " tries to rip off your "+item+", but fails.\n");
	  return 1;
	}
      } else {
	write(capitalize(target->query_name())+" hasn't got any "+item+".\n");
	return 1;
      }
    } else {
      write("Usage: use steal at <player> [take <item>]\n");
      return 1;
    }
  } else {
    while(i<sizeof(ob)) {
      if (!ob[i]->query_worn() && !ob[i]->query_wielded() && !ob[i]->drop())
	{ nonwear = ob[i]; i = sizeof(ob); }
      i += 1;
    }
  }
  if (!nonwear) {
   write("You notice that "+capitalize(target->query_name())+"'s backpack is empty.\n");
   return 1;
  }
  move_object(nonwear, this_player());
  write("You put your hand into "+capitalize(target->query_name())+
	"'s backpack and pull out "+nonwear->short()+".\n");
  return 1;
}

fail_skill(target) {
  write("Shit! "+capitalize(target->query_name())+" notices your attempt!\n");
  tell_object(target, "Hey! What the fuck is "+
      capitalize(this_player()->query_name()) +"'s hand doing in your backpack?!\n");
  return 1;
}
