status is_npc(object ob){
	if(living(ob) &&ob == this_player()->query_attack())return 1;
	if(living(ob) && this_player() == ob->query_attacker())return 1;
	
	return 0;
}


cmd_scan(string monsu) {
    string cap_monsu;
    object ob;
    object *obs;
    int mob_hp;
    int i;
    if (!this_player()->check_condis()) { return 1; }
    if (!this_player()->query_attack() && !monsu) {
        write("You are not in combat right now.\n");
        return 1;
    }
    if (!monsu && this_player()->query_attack()) { ob = this_player()->query_attack(); }
    if(monsu == "all") {
    	obs = all_inventory(environment(this_player()));
    	obs = filter_array(obs,"is_npc");
	if(sizeof(obs)==0){
		write("None of your enemies are here.\n");
		return 1;
	}
	for(i=0;i<sizeof(obs);i++) {
	cap_monsu = capitalize(obs[i]->query_name());
   	mob_hp = obs[i]->query_hp()*100 / obs[i]->query_max_hp();
    	switch(mob_hp){
    		case 0..13:
    			write(cap_monsu + " is about to die.\n");break;
    	        case 14..20:
    	        	write(cap_monsu + " is in very bad shape.\n");break;
       	        case 21..33:
       	        	write(cap_monsu + " is in bad shape.\n");break;
       	        case 34..50:
       	        	write(cap_monsu + " is injured.\n");break;
  		case 51..75:
  			write(cap_monsu + " is somewhat injured.\n");break;
  		case 76..80:
  		        write(cap_monsu + " is slightly hurt.\n");break;
       	        case 81..99:
       	        	  write(cap_monsu + " is in good shape.\n");break;
       	        default:
       	        	write(cap_monsu + " is in excellent shape.\n");break;
 }
 }
return 1;	
}
    if (!ob&&monsu) { ob = present(monsu, environment(this_player())); }
        
    if (!ob) {
        write("No " + monsu + " here.\n");
        return 1;
    }
    if(!living(ob)) {
        write(monsu+" is not a living thing.\n");
        return 1;
    }
    cap_monsu = capitalize(ob->query_name());
    if(ob->query_gender())
        cap_monsu = capitalize(ob->query_pronoun());
    
    
    mob_hp = ob->query_hp()*100 / ob->query_max_hp();
    	switch(mob_hp){
    		case 0..13:
    			write(cap_monsu + " is about to die.\n");break;
    	        case 14..20:
    	        	write(cap_monsu + " is in very bad shape.\n");break;
       	        case 21..33:
       	        	write(cap_monsu + " is in bad shape.\n");break;
       	        case 34..50:
       	        	write(cap_monsu + " is injured.\n");break;
  		case 51..75:
  			write(cap_monsu + " is somewhat injured.\n");break;
  		case 76..80:
  		        write(cap_monsu + " is slightly hurt.\n");break;
       	        case 81..99:
       	        	  write(cap_monsu + " is in good shape.\n");break;
       	        default:
       	        	write(cap_monsu + " is in excellent shape.\n");break;
       	        
       	        	
 }
        
}
