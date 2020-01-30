#define MD_LVL_LIMIT 20
#define MD_DRAIN_MODIFIER 20

get_time(str) {
  return random(3)+2;
}
ep_cost() { return 1; }
query_type() { return "offensive"; }

resolve_skill(str) {
    int att,def;
    object target;
    
    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      write("Use mental drain at whom?\n");
      return 1;
    }
    
        
    target = present(str, environment(this_player()));
    if(!target || !living(target) || target == this_player()) {
      write(str+" is not a valid target.\n");
      return 1;
    }
    if(target->query_sp() <= (target->query_max_sp()/2)) {
    	write(target->query_name()+"'s mind is weakened too much and you cant drain anything from it!\n");
   	tell_object(target,this_player()->query_name()+" tries to drain the rest from your weak mind but you manage to resist it!\n");
   	if(target->query_attack() != this_player())target->attack_object(this_player());
	if(this_player()->query_attack() != target)this_player()->attack_object(target);
	return 1;

}
        
    if(target->query_level() > MD_LVL_LIMIT) {
    	write(target->query_name()+"'s mind is too strong to be drained!.\n");
    	tell_object(target,this_player()->query_name()+" tries to drain your mental energy!\n");
    	if(target->query_attack() != this_player())target->attack_object(this_player());
	if(this_player()->query_attack() != target)this_player()->attack_object(target);
    	return 1;
}
	if(target->query_undead()) {
		write(target->query_name()+" is undead and the mindwave reflects on you !\n");
		this_player()->set_stunned(random(10)+1);
	//	if(target->query_attack() != this_player())target->attack_object(this_player());
		return 1;
	}
	
	att = this_player()->query_int();
	att += this_player()->query_skills("mental drain");
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

	write("You try to drain "+target->query_name()+"'s mental energy but only manage to irritate "+target->query_objective()+".\n");
	tell_object(target,this_player()->query_name()+" tries to drain your mental energy but only manages to irritate you.\n");
	say(this_player()->query_name()+" stares in "+target->query_name()+"'s eyes and suddenly "+target->query_name()+" gets angry.\n");
	
	if(target->query_attack() != this_player())target->attack_object(this_player());
	if(this_player()->query_attack() != target)this_player()->attack_object(target);
	return 1;
	
}
    
att -= def;

if(att > (target->query_max_sp()/2))att=target->query_max_sp()/2;

if(att > target->query_sp())att = target->query_sp();

if(target->query_sp() - att < 1)att = target->query_sp()-1;

    
    write("You stare in "+target->query_name()+"'s eyes draining "+target->query_possessive()+" mental energy.\n");
    tell_object(target,this_player()->query_name()+" stares in your eyes and you feel how "+this_player()->query_objective()+" drains some of your mental energy.\n");
    say(this_player()->query_name()+" stares in "+target->query_name()+"'s eyes and suddenly "+target->query_name()+" gets a pale look on "+target->query_possessive()+" face.\n",target);
       
    target->reduce_sp(att);
    this_player()->add_sp(att);
    tell_object(this_player(),"You manage to drain "+att+" sp from "+target->query_name()+"\n");
        
    if(target->query_attack() != this_player())target->attack_object(this_player());
    if(this_player()->query_attack() != target) this_player()->attack_object(target);
    
}

fail_skill(str) {
    object target;
    if(!str) {
        write("Use confuse at who?\n");
        return 1;
    }
    if(random(100) < this_player()->query_skills("mental drain")) {
        resolve_skill(str);
        return 1;
    }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }

	write("You fail the skill.\n");
return 1;
    //target->attack_object(this_player());
    //this_player()->attack_object(target);
}
