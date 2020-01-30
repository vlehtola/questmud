#define SP_NEEDED 50
#define PSI_LEVELLIMIT 20
#define CONFUSE_MODIFIER 20
get_time(str) {
  return random(2)+2;
}
ep_cost() { return 1; }
query_type() { return "offensive"; }

resolve_skill(str) {
    int att,def,time;
    object target;
    
    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      write("Use confuse at whom?\n");
      return 1;
    }
    
        
    target = present(str, environment(this_player()));
    if(!target || !living(target) || target == this_player()) {
      write(str+" is not a valid target.\n");
      return 1;
    }
    
    if(!target->query_npc()) {
    	write("You can not confuse other players!\n");
    	return 1;
    	}
    
    if(target->query_level() > PSI_LEVELLIMIT) {
    	write(target->query_name()+"'s mind is too strong to be confused!.\n");
    	if(target->query_attack() != this_player())target->attack_object(this_player());
	if(this_player()->query_attack() != target)this_player()->attack_object(target);
    	return 1;
}
	if(target->query_undead()) {
		write(target->query_name()+" is undead and the mindwave reflects on you !\n");
		this_player()->set_stunned(random(10)+1);
		if(target->query_attack() != this_player())target->attack_object(this_player());
		return 1;
	}
	
    
    if(this_player()->query_sp() < SP_NEEDED) {
    	
    	write("You lack the mental strength to accomplish this attack.\n");
    	return 1;
}
this_player()->reduce_sp(SP_NEEDED);

	att = this_player()->query_int();
	att += this_player()->query_skills("confuse");
	att += this_player()->query_skills("knowledge of mind");
	if(this_player()->query_mentaldenial()) {
		att *= 2;
		this_player()->remove_denial();
	}
	att /= 2;
	att += random(att);
	
	def = target->query_wis();
	def += target->query_skills("mental block");       
    	def /= 2;
if(target->query_attack() == this_player()) def *= 2;
    	def += random(def);

if(att < def) {
	//muuta descit
	write("Your concentrate for a moment and release your powers but "+target->query_name()+" resists your attempt completely!\n");
	
	say(this_player()->query_name()+" concentrates for a moment and tries to confuse "+target->query_name()+" but fails miserably!\n",target);
	if(target->query_attack() != this_player())target->attack_object(this_player());
	if(this_player()->query_attack() != target)this_player()->attack_object(target);
	return 1;
	
}
    
att -= def;
att /= 10;
time = att*CONFUSE_MODIFIER;

    
    write("You concentrate for a second and release your powers towards "+target->query_name()+"'s weak mind and confuse "+target->query_objective()+" totally!\n");
    say(this_player()->query_name()+" concentrates for a second and releases "+this_player()->query_possessive()+" powers towards "+target->query_name()+" confusing "+target->query_objective()+" totally!\n",target);
    clone_object("/wizards/astarel/psi/specials/confuse_shadow")->start(target,time);
    //if(target->query_attack() != this_player())target->attack_object(this_player());
    //if(this_player()->query_attack() != target) this_player()->attack_object(target);
    
}

fail_skill(str) {
    object target;
    if(!str) {
        write("Use confuse at who?\n");
        return 1;
    }
    if(random(100) < this_player()->query_skills("confuse")) {
        resolve_skill(str);
        return 1;
    }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    write("You to concentrate on confusing " + target->query_name() + "'s mind, but fail.\n");
    //tell_object(target, this_player()->query_name() + " concentrates a moment but suddenly shakes "+this_player()->query_possessive()+" head.\n");
    say(capitalize(this_player()->query_name()) + " concentrates for a moment but suddenly shakes "+this_player()->query_possissve()+" head.\n", target);
    //target->attack_object(this_player());
    //this_player()->attack_object(target);
}
