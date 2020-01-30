resolve(dama, type, word1, word2) {
  object ob, next_ob, p_ob;
  string target_list, last_target;
  int damage;
  target_list = "";
  last_target = "";
  if (this_player()->query_tester()) {
	write("Daman pitas olla:"+dama+"\n");
  }
  if (this_player()->query_leader_ob() &&
     present("party object",this_player()->query_leader_ob())) {
	p_ob = present("party_object", this_player()->query_leader_ob());
  }
  if (this_player()->query_tester() && p_ob) {
	write("Party found..\n");
  }
  ob = first_inventory(environment(this_player()));
  while(ob) {
    next_ob = next_inventory(ob);
    if (last_target != "") {
	if (!next_ob) { target_list = target_list + " and "; }
	else if (target_list != "") {
		target_list = target_list + ", "; 
	}
	target_list = target_list + last_target;
    }
    if (living(ob) && ob != this_player()) {
      if (p_ob && p_ob->check_members(ob)) {
      } else {
	last_target = ob->query_name();
	damage = random(dama/2)+dama/2;
	if (this_player()->query_tester()) {
		write("Hitting:"+ob->query_name()+"\n");
	}
	tell_object(ob, this_player()->query_name()+
	  " hits you with a "+word1+" "+word2+"!\n");
	this_player()->attack_object(ob, 1);
	ob->hit_with_spell(damage, type);
      }
    }
    ob = next_ob;
  }
  if (last_target != "") {
     target_list = target_list+" and "+last_target;
  }
  write("You hit "+target_list+" with your "+word1+" "+word2+".\n");
}
