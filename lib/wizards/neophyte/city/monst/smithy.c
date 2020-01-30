inherit "obj/monster";
object hammer,key,crystal,key1;
string chat_str;
status comp;
status k;
reset(arg) {
	string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("caulos");
        set_alias("smithy");
        set_level(50+random(6));
        set_gender(1);
        set_race("human");
        set_al(-10);
        set_special(70);
        set_short("Caulos Lowie the city smithy");
        set_long("He is the smithy in the city. He doesn't look an usual smith.\n"+
                 "He is wielding a great hammer which he uses to forge equipment.\n");
        set_skill("cranekick", 80);
        set_skill_chance("cranekick", 30);
        set_dead_ob(this_object());
        set_log();
        set_max_hp(query_hp()+20000);
        set_hp(query_max_hp());
        hammer = clone_object("/wizards/neophyte/city/eq/bhammer");
        move_object(hammer,this_object());
        init_command("wield hammer");
        key = clone_object("/wizards/neophyte/city/obj/lowiekey");
        move_object(key,this_object());
                if(!chat_str) {
		  chat_str = allocate(2);
		  chat_str[0] = "Smithy mumbles something about his house.\n";
		  chat_str[1] = "A loud banging sound can be heard everytime he hits his hammer.\n";
		}
		load_chat(2, chat_str);


}

ask_question(str) {
        if(str == "house") {
                say("Caulos says: 'Yes i can use a little help.'\n");
                return 1;
        }
        if(str == "help") {
			say("Caulos says: 'We left hurry and forged to extinguish all the candles our precious kitchen.'\n");
			return 1;
		}
		if(str == "performed") {
			say("Caulos says: 'Let me think a second.'\n");
			perform();
			return 1;
		}

        if(str == "key") {
			if(!k) {
			say("Caulos says: 'I am sorry forged to give you this and remember to say 'performed' when you have accomplished the task.'\n");
			key1 = clone_object("/wizards/neophyte/city/obj/lowiekey");
            move_object(key1, this_player());
            tell_object(this_player(), "Caulos gives you the key.\n");
            say("Caulos gives something to "+this_player()->query_name()+".\n",this_player());
            k = 1;
            return 1;
		}
		say("Caulos says: 'I already gived the key to some one else.'\n");
		return 1;
	}
        write("Caulos says: 'I don't know anything about that'.\n");
        return 1;
}

perform() {
	if(!call_other("/wizards/neophyte/city/house/kitchen.c", "query_burning",0)) {
		say("Caulos says: 'But they are not extinguished.'\n");
		return 1;
	}
	if(call_other("/wizards/neophyte/city/house/kitchen.c", "query_who",0) != this_player()->query_name()) {
		say("Caulos says: 'But you haven't the one who extinguished the candle!'\n");
		return 1;
	}
	if(!comp) {
	say("Caulos says: 'Yes you have extinguished the candle.\n");
	crystal = clone_object("/wizards/neophyte/city/eq/crowbar");
	move_object(crystal, this_player());
	say("Caulos says: 'Here is a little reward for you.\n");
	say("Caulos says: 'It's not a good weapon but you mighty use it somethign else.\n");
	comp = 1;
	return 1;
}
say("Caulos says: 'I already gave the reward away.'\n");
return 1;
}

monster_died() {
	call_other("/wizards/neophyte/city/weapon_shop.c", "set_killer", this_player()->query_name());
	return 0;
}