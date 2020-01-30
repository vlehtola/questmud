inherit "obj/monster";
reset(arg) {
	 string chat_str;
     ::reset(arg);
     if(arg) {return; }
     set_name("wolf");
     set_level(40+random(10));
     set_gender(0);
     set_al(-25+random(10));
     set_alias("frenzied");
     set_alt_name("frenzied wolf");
     set_move_at_reset();
     set_short("A frenzied wolf");
     set_long(
	 "The creature which is walking near the bushes seems to be like a normal wolf,\n"+
	 "but when it comes closer, it seems to tremble with fury and bloodlust. When\n"+
         "the beast opens its mouth to growl, blood drips from its teeth. This wolf seems\n"+
	 "to be in some kind of a frenzy to kill everything it sees. The fur is also a\n"+
         "little bloody. The blood is most likely from its previous victims.\n");

	set_animal();
	set_aggressive(1);
	set_block_dir(({ "west","east","north","south", })[random(4)]);
	set_str(query_str()+50);
	set_max_hp(query_hp()+5000);
	set_hp(query_max_hp());
			set_skill("stomp",50);
			set_skill_chance("stomp", 50);
	if (!chat_str) {
	chat_str = allocate(2);
	chat_str[0] = "The frenzied wolf howls in frenzy!\n";
	chat_str[1] = "The frenzied wolf looks for something, maybe its next victim!\n";
	       }
    load_chat(5, chat_str);
	}
