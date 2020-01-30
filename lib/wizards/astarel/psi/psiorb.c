object owner;

reset(arg) {
	if(arg)return;
	owner = this_player();
}

short() {
return owner->query_name()+"'s blue orb of psionicists";
}

long() {
	write("This is the guilditem of the Psionicists guild.\n");
	write("Command:             Info:\n");
	write("psiscan <target>     Tells you the mental state of the target.\n");
	write("psiguild             Teleports you into the guild.\n");
}



query_auto_load() {
return "wizards/astarel/psi/psiorb:";
}

drop() { return 1; }
get() { return 1;}

id(str) {
	if(str == "orb")return 1;
}

init() {
	add_action("psiscan","psiscan");
	add_action("psiguild","psiguild");
	}

status psiguild() {
	if(this_player()->query_attack()) {
		write("Try to kill your enemies before going to the guild.\n");
		return 1;
	}
	write("You are transported to the guild.\n");	
	move_object(this_player(),"/wizards/astarel/psi/psiguild");
	return 1;
}


status psiscan(string str) {
object target;
int sp;

	if(!str) {
		write("Usage: psiscan <target>.\n");
		return 1;
		}
	
	if(!present(str,environment(this_player()))) {
		write("No "+str+" here.\n");
		return 1;
	}
	target = present(str,environment(this_player()));
	
	if(!target) {
		write("No "+str+" here.\n");
		return 1;
	}
	
	if(!living(target) || !target->query_npc()) {
		write("You can only scan monsters.\n");
		return 1;
	}
	
	sp = (target->query_sp()*100)/target->query_max_sp();
	
	write(target->query_name()+"'s mental state is "+sp+"% complete.\n");
	return 1;
}
