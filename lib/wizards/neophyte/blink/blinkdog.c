inherit "obj/monster";
#define EVENT_D "/wizards/neophyte/blink/start"
reset(arg) {
        ::reset(arg);
        if(arg) {return; }
        set_name("dog");
        set_alias("blink dog");
        set_level(5);
        set_al(0);
        set_gender(1);
        set_short("A blink dog");
        set_long("This blink dog quite much looks like an ordinary dog.\n"+
                 "He has velvet golden fur which is constantly changing.\n"+
                 "Then you release the eyes of dog what are blinking strangely.\n");
        set_max_hp(100000+query_hp()*1000);
        set_hp(query_max_hp());
}

query_blink_dog() { return this_object(); }

blink() {
	say("The dog blinks his eyes and are suddenly vanished.\n");
	move_object(this_object(), ({
"/world/city/cs",
"/world/city/gold3",
"/world/city/gold2",
"/world/city/gold1",
"/world/city/gold5",
"/world/city/gold6",
"/world/city/gold7",
"/world/city/gold8",
"/world/city/wood2",
"/world/city/wood3",
"/world/city/wood4",
"/world/city/wood5",
"/world/city/wood6",
"/world/city/silver1",
"/world/city/silver2",
"/world/city/silver3",
"/world/city/silver4",
"/world/city/silver5",
"/world/city/silver6",
"/world/city/silver7",
"/world/city/emerald1",
"/world/city/diamond2",
"/world/city/diamond3",
"/world/city/diamond4",
"/world/city/diamond6",
"/world/city/diamond7",
"/world/city/diamond1",
})[random(26)]);
call_out("blink", 3);
return 1;
}

catch_me() {
	object ob,money;
	int i,award;
	ob = present("adventurer", find_object("/world/city/cs"));
	award = ob->query_award();
	ob->dest_me();
	i = remove_call_out("blink");
	write("You managed to catch the blink dog.\n");
	write("Shepherd tells you 'Here is a little award to you!\n");
	write("Shepherd arrives from somewhere.\n");
	write("Shepherd gives you "+award+" bronze coins.\n");
	shout(this_player()->query_name()+" managed to catch the dog!\n");
	shout("And is awarded "+award+" bronze.\n");
	money = clone_object("/obj/new_money");
	money->add_value(award);
	money->set_type(3);
	move_object(money,this_player());
	EVENT_D->winner(this_player()->query_name(), award);
	destruct(this_object());
	return 1;
}
