inherit "obj/armour";
int i;
start(){
	i = 3;
	set_class(3);
	set_name("ring");
	set_short("A ring with small diamond eye");
	set_long("The ring itself is made from bronze but an diamond eye is attached\n"+
	         "on the ring tightly. The ring feels quite strange and warm. maybe\n"+
	         "you can do something with that diamond eye.\n");
	set_slot("finger");
	}

init() {
	::init();
	add_action("wear", "wear");
	add_action("remove", "remove");
}
wear(str) {
	if(str == "ring" && !query_worn()) {
	write("You accidently touch the diamond eye and everything looks much more clear now.\n");
	say(this_player()->query_name()+" somehow looks much clear now.\n");
	set_light(i);
	do_wear();
	return 1;
}
else {
	return;
}
}

remove(str) {
	if(str == "ring" && query_worn()) {
		write("As you remove the ring everything turns blurred.\n");
		say(this_player()->query_name()+" looks much blurred now.\n");
		set_light(-i);
		stop_wearing();
		return 1;
	}
	else {
		return;
	}
}
