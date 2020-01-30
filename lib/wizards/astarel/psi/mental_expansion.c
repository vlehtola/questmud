get_time(str) {
  return random(4)+2;
}
ep_cost() { return 1; }
query_type() { return "neutral"; }


resolve_skill(str) {

int chance,amount,time;
float fl;

	if(this_player()->query_mentale()) {
		write("You mind is already expanded.\n");
		return 1;
	}
	
	
	fl = to_float(this_player()->query_max_ep());
	
	chance = this_player()->query_skills("mental expansion")/2;
	chance+= this_player()->query_skills("knowledge of mind")/2;
	
	time = 120;
	time *= chance;
	
	amount = to_int((fl/100)*chance);
	if(amount > this_player()->query_max_ep())amount = this_player()->query_max_ep();
	amount *=3;
	
	write("You expand your mind.\n");
	clone_object("/guilds/psi/specials/mental_expansion_shadow")->start(this_player(),amount,time);
	
}

fail_skill(str) {
        
    if(random(100) < this_player()->query_skills("mental expansion")) {
        resolve_skill(str);
        return 1;
    }
           
    write("You lose your concentration and fail the skill.\n");
    return 1;
    
}