inherit "obj/monster";
int join,award;
reset(arg) {
	join = 0;
	award = 0;
        ::reset(arg);
        if(arg) {return; }
        set_name("eventmaster");
        set_alias("adventurer");
        set_level(90);
        set_gender(1);
        set_short("An adventurer searching something");
        set_long("He is wearing and shepherd clothing and old wooden stick.\n"+
                 "He is constantly whistling to his dog and shouting to it come\n"+
                 "back. Maybe you should say join if you want to participate.\n");
}
query_join() { return join; }

catch_tell(str) {
	object ob;
	string joiner;
	if (sscanf(str, "%s says 'join'", joiner) == 1) {
		if(present("whip", this_player())) {
		 write("You have already joined.\n");
		 return 1;
	 }
	if(query_join() == 1) { write("You can't join anymore.\n"); return 1; }

	ob = clone_object("/wizards/neophyte/blink/whip");
	move_object(ob, this_player());
	write("You participate the hunt and man gives you whip.\n");
	write("Man says 'You can try to hunt the dog with this.\n");
	award(100);
	return 1;
}
}
dest_me() {
destruct(present("eventmaster",find_object("/world/city/cs")));
}

start_count() {
	int time;
	shout("You have 5 minute left to join the event.\n");
	call_out("minute", 240);
	call_out("minutes",180);
	call_out("start_event", 300);
	return 1;
}
minute() {
	shout("You have 1 minute left to join the event.\n");
}

minutes() {
	shout("You have 3 minute left to join the event.\n");
}

start_event() {
	if(award == 0) {
	shout("Adventurer shouts: 'I have to cancel this because no one havent joined.\n");
	return 1;
}
	shout("Adventurer shouts: Let the hunt begin!\n");
	call_other("/wizards/neophyte/blink/event.c", "start_blink", 1);
	join = 1;
	return 1;
}
award(int i) {
	award += i;
	if(award > 1000) award = 1000;

}
query_award() { return award; }

self_destruct() {
destruct(present("adventurer",find_object("/world/city/cs")));
        destruct(this_object());
}