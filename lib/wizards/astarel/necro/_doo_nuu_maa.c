/* HPBoost */

status filtteri(object ob) {
	if(ob->query_horde_master()) {
		if(lower_case(ob->query_horde_master()) == lower_case(this_player()->query_name()))return 1;
	}
	
	return 0;
}

resolve(bonus) {
  int i;
  
  string aura;
  object horde;
  object *obs;
  
  obs = all_inventory(environment(this_player()));
  obs = filter_array(obs,"filtteri");
  
  
if(!obs || sizeof(obs) < 1) {
  	write("There's no horde nearby where you could add this undead.\n");
  	return 1;
}
  
  horde = obs[0];
  if(!horde) {
    write("Your horde is not present.\n");
    return 1;
  }
  if(horde->query_hpboost()) {
  	if(horde->query_statboost())write("You horde is already surrounded by dark red aura.\n");
  	else write("Your horde is already surrounded by bright red aura.\n");
  	return 1;
  	}

aura = "bright red";
if(horde->query_statboost())aura = "dark red";  	  
 
 i = this_player()->query_int();
 i+= this_player()->query_wis()/2;
 i+= this_player()->query_skills("cast unholy arms");
 i+= this_player()->query_skills("cast dark power");
 
 i*=2;
 
 horde->start_hpboost(i);
 
 
write("You create a "+aura+" aura to surround your horde.\n");
  
say(this_player()->query_name()+" creates a "+aura+" aura to surround "+this_player()->query_possessive()+" horde.\n");
  
return 1;
}