inherit "obj/monster";
reset(arg) {
	 string chat_str;
     ::reset(arg);
     if(arg) {return; }
     set_name("bear");
     set_level(50+random(10));
     set_gender(0);
     set_al(-30+random(10));
     set_alias("shadow");
     set_alt_name("shadow bear");
     set_move_at_reset();
     set_short("A shadow bear");
     set_long(
	 "This once so magnificent creature is now just a shadow from that what is was\n"+
	 "before. In the eyes of bear can be seen hatred torwards anything that is\n"+
	 "living. A skin of this creature is full of blood and wounds. The bear looks\n"+
	 "massive and strong and it is constantly growling and cutting down trees with\n"+
         "its claws. The bear looks somehow very twisted and deformed. You start to\n"+
	 "think who would do this kind of ravage things to this forest and these animals.\n");

	set_animal();
	set_aggressive(1);
	set_block_dir(({ "west","east","north","south", })[random(4)]);
	set_str(query_str()+100);
	set_max_hp(query_hp()+10000);
	set_hp(query_max_hp());
			set_skill("stomp",90);
			set_skill_chance("stomp", 90);

	if (!chat_str) {
	chat_str = allocate(2);
	chat_str[0] = "The shadow bear growls angrily at you!\n";
	chat_str[1] = "The bear starts to cut down a tree.\n";
	       }
    load_chat(5, chat_str);
	}
