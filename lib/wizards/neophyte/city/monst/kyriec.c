inherit "obj/monster";
object belt;
reset(arg) {
	string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("kyriec");
        set_alias("witch");
        set_level(35+random(6));
        set_gender(2);
        /*
        set_race("dryad");
        */
        set_al(-40);
        set_short("Kyriec the travelling witch archmage");
        set_long("She is wearing an decent travelling clothers, a cloak which hides\n"+
                 "her in the shadows and belt where she stores her vials. She is staying\n"+
                 "night in this inn and switching information. She looks quite smart\n"+
                 "and sensible old woman.\n");
        set_log();
        set_int(query_int()*5);
        set_max_hp(query_hp()+30000);
        set_hp(query_max_hp());
        belt = clone_object("/wizards/neophyte/city/eq/belt");
        move_object(belt, this_object());
        init_command("wear all");
        if(!chat_str) {
          chat_str = allocate(2);
		  chat_str[0] = "Kyriec looks at you curiously.\n";
		  chat_str[1] = "Kyriec adjusts her precious belt.\n";
}
  load_chat(2,chat_str);
          set_skill("reflect spell", 70);
          set_skill("counter spell", 50);
          set_skill("cast essence", 100);
          set_skill("cast fire", 100);
          set_skill("cast bolt", 100);
          set_skill("cast storm", 100);
          set_skill("power channeling", 100);
          set_skill("mana control", 100);
          set_skill("chanting", 100);
          set_skill("power focusing", 100);
          set_skill("power concentration", 100);
          set_skill("knowledge of heat", 100);
          set_skill("stunned maneuvers", 100);
          set_skill("inner strength", 100);
          set_skill("tumble", 60);
          set_skill("quick chant", 100);
          set_spell_chance(50,"exs fla blt");
          set_spell_chance(30,"exs fla strm");

}

ask_question(str) {
        if(str == "witch") {
                say("Kyriec says: 'Yes, i am proud member of witch guild.'\n");
                return 1;
        }
        if(str == "dryad") {
			say("Kyriec says: 'We are dying race and only a couple of as is left.\n");
			return 1;
		}
		if(str == "zinuq") {
			say("Kyriec says: 'Zinuq is a teacher and grand elder of the witches guild.\n");
			return 1;
		}
        write("Kyriec says: 'I don't know anything about that'.\n");
        return 1;
}

