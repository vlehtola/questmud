#define MD_SP_NEEDED 50
#define INVIS_MODIFIER 20

get_time(str) {
  return random(2)+2;
}
ep_cost() { return 5; }

query_type() { return "neutral"; }

resolve_skill(str) {

    
int time;
    
	if(str) {
		write("You cant give targets for this skill.\n");
		return 1;
	}
if(this_player()->query_mentaldenial()) {
	write("You are already mentally denied.\n");
	return 1;
	}
       
    if(this_player()->query_sp() < MD_SP_NEEDED) {
    	
    	write("You lack the mental strength to accomplish this attack.\n");
    	return 1;
}
this_player()->reduce_sp(MD_SP_NEEDED);

time = this_player()->query_int() / 10;
time += INVIS_MODIFIER;
time += this_player()->query_skills("mental denial")/10;
time += this_player()->query_skills("knowledge of mind")/10;

	
    
        write("You concentrate for awhile and then release your powers forcing everyone to deny your existence.\n");
        //say(this_player()->query_name()+" concentrates for a while and suddenly you cant see "+this_player()->query_possessive()+" anymore.\n");

	clone_object("/guilds/psi/specials/denial_shadow")->start(this_player(),time); 
}

fail_skill(str) {
        
    if(random(100) < this_player()->query_skills("mental denial")) {
        resolve_skill(str);
        return 1;
    }
        
    write("You lose your concentration and fail the skill.\n");
    
}