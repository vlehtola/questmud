inherit "obj/monster";
object feet;
reset(arg) {
	string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("fanud");
        set_alias("man");
        set_level(40+random(6));
        set_gender(1);
        set_race("hobbit");
        set_al(-60);
        set_short("An man is moving in the shadows");
        set_long("A man is moving in the shadows looking like he is hiding from\n"+
                 "someone. He is wearing a dark clothes and black cloak. He has\n"+
                 "a brown hair, which look like it haven't seen in years a decent\n"+
                 "comb.\n");
        set_skill("fire building", 100);
        set_skill_chance("fire building", 20);
        set_skill("shaldrin", 100);
        set_skill_chance("shaldrin", 10);
        set_log();
        set_max_hp(query_hp()+50000);
        set_hp(query_max_hp());
        feet = clone_object("/wizards/neophyte/city/eq/feet");
        move_object(feet, this_object());
        init_command("wear all");
        if(!chat_str) {
  chat_str = allocate(2);
  chat_str[0] = "Fanud looks at you and ponders something.\n";
  chat_str[1] = "Fanud moves a little.\n";
}
load_chat(2, chat_str);
}

ask_question(str) {
        if(str == "thief") {
                say("Fanud says: 'Yes, i am thief.'\n");
                return 1;
        }
        if(str == "halfling") {
			say("Fanud says: 'We are quite well race for thief's.\n");
			return 1;
		}
        write("Fanud says: 'I don't know anything about that'.\n");
        return 1;
}

