#define IW_SP_NEEDED 50
#define BASE_DURATION 100
#define MASTERY_D "/daemons/mastery_d"
get_time(str) {
  return random(4)+2;
}
ep_cost() { return 1; }
query_type() { return "neutral"; }


resolve_skill(str) {


int time, sp_needed;
//Disabled by Moonstar 7.6.2004
  write("This skill has been disabled.\n");
  return 1;

        if(this_player()->query_iiwee()) {
                write("You are already affected by iron will.\n");
                return 1;
        }

        if(this_player()->query_stun_resist()) {
                write("Your will is already hardened by something else.\n");
                return 1;
        }

        sp_needed = IW_SP_NEEDED - MASTERY_D->check_mastery("Power of the mind",this_player())/3;

    if(this_player()->query_sp() < sp_needed) {
        
        write("You lack the mental strength to accomplish this attack.\n");
        return 1;
}
this_player()->reduce_sp(sp_needed);
        
        
        time = BASE_DURATION;
        time += this_player()->query_skills("iron will")/10;
        time += this_player()->query_skills("knowledge of mind")/10;
        time += MASTERY_D->mastery("Power of the mind",this_player())/10;

        time *= 6;
        
        if(time < 1) time = 6;  
                        
        write("You harden your will.\n");
        clone_object("/guilds/psi/specials/iron_will_shadow")->start(this_player(),time);
        
}

fail_skill(str) {
        
    if(random(100) < this_player()->query_skills("iron will")) {
        resolve_skill(str);
        return 1;
    }
           
    write("You lose your concentration and fail the skill.\n");
    
}
