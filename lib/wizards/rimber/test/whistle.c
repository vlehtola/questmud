object my_dragon;

id(str) { return str == "whistle"; }

short() { return "A bronze whistle"; }

long() { write("Why don't you try to blow on it?\n"); }

get() { return 0; }

drop() { return 1; }

give() { return 0; }

query_weight() { return 1; }

init() {
 add_action("blow", "blow");
}

blow(str) {
  if(str != "whistle") return 1;
  write("The whistle gives a high pitched voice.\n");
  say(this_player()->query_name() +" blows a whistle.\n");
  if(object_name(my_dragon)) {
  call_out("dragon_fly", 5);
  write("Dragon speaks to you mentally: 'I'll be there soon Master.'\n");
   return 1;
  } else {
   write("You don't have a dragon.\n");
   destruct(this_object());
   write("Whistle turns to dust.\n");
   return 1;
  }
}

void setDragon(object drg) { my_dragon = drg; }

int dragon_fly() {
  tell_room(environment(this_player()), "Dragon flies in and sends dust to the air.\n");
   tell_room(environment(this_player()), "Dragon booms: 'Waiting for your orders Master.'\n");
  move_object(my_dragon, environment(this_player()));
  return 1;
}
