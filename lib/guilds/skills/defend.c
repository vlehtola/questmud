get_time() {
    return random(2)+2;
}
query_type() { return "defensive"; }

ep_cost() {
    return 7;
}

resolve_skill() {
  object defend;
  int parry, dodge;
  if(this_player()->query_defend()) {
    write("You cannot use defend now.\n");
    return 1;
  }
/*
  dodge = call_other("/daemons/combat", "dodge_chance", this_player());
  parry = call_other("/daemons/combat", "parry_chance", this_player())+
	call_other("/daemons/combat", "parry_chance", this_player(), 1);
  parry = parry * 2/3;
  dodge = dodge * 2/3;
  if(parry > 100) parry = 100;
  if(dodge > 100) dodge = 100;
*/
  write("You concentrate on your defence.\n");
  defend = clone_object("/guilds/skill_obj/defendob");
  call_other(defend, "start", this_player(),dodge, parry);
}

fail_skill() {
   int i;
   i = random(3) + 1;
   if (i == 1) {
       write("You failed in concentration.\n");
   } else if (i == 2) {
       write("You feel like you forgot something important.\n");
   } else {
       write("You were unable to focus your defence.\n");
   }
}
