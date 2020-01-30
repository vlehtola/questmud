get_time(str) {
  return random(4)+4;
}
ep_cost() { return 5; }
query_type() { return "neutral"; }


resolve_skill(str) {

int chance,amount;
float fl;

	fl = to_float(this_player()->query_max_ep())/2;
	
	chance = this_player()->query_skills("mental balance")/2;
	chance+= this_player()->query_skills("knowledge of mind")/2;
	
	amount = to_int((fl/100)*chance);
	if(amount > this_player()->query_ep())amount = this_player()->query_ep();
	
	write("You close your eyes and fall in dormancy.\n");
	clone_object("/guilds/psi/specials/mental_balance_shadow")->start(this_player(),amount);
	
}

fail_skill(str) {
        
    if(random(100) < this_player()->query_skills("mental balance")) {
        resolve_skill(str);
        return 1;
    }
           
    write("You lose your concentration and fail the skill.\n");
    
}