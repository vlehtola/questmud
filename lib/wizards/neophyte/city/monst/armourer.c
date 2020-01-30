inherit "obj/monster";
object gloves,key,g;
reset(arg) {
	string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("armourer");
        set_alias("loxie");
        set_level(45+random(6));
        set_gender(2);
        set_race("dark elf");
        set_al(-10);
        set_special();
        set_short("Loxie Lowie the city armourer");
        set_long("She is currently the one who is responsible for armours and stuff like\n"+
                 "that. She has a needle and cotton rope in her hands. She surely doesn't\n"+
                 "look an usual armourer.\n");
        set_skill("cranekick", 80);
        set_skill_chance("cranekick", 50);
        set_dead_ob(this_object());
        set_log();
        set_max_hp(query_hp()+50000);
        set_hp(query_max_hp());
        set_special(15);
        gloves = clone_object("/wizards/neophyte/city/eq/agloves");
        move_object(gloves, this_object());
        init_command("wear gloves");
                key = clone_object("/wizards/neophyte/city/obj/lowiekey");
		        move_object(key,this_object());
		                             if (!chat_str) {
		                                         chat_str = allocate(2);
		                                         chat_str[0] =
		                                 "Loxie says: 'I can make armours from hides.\n";
		                                 chat_str[1] =
		                                 "Loxie says: 'Just ask me to build armour if you happeng to got hides.'\n";
		                                }
        load_chat(3, chat_str);

}
special_move() {
  object *ob;
  int i,x;
  ob = all_inventory(environment(this_object()));
  for(i=0;i<sizeof(ob);i++) {
          if(living(ob[i])) {
		x = random(i);
		if(ob[x] == this_object()) return;
		tell_object(ob[x], "Loxie moves you to the guard post and orderds guards to take care of you!\n");
		move_object(ob[x], "/wizards/neophyte/city/gpost");
		g = present("guard", environment(ob[x]));
		ob[x]->attack_object(g);
}
}
}

ask_question(str) {
	object ob,award,sheep,award1;
	ob = present("suden_talja", this_player());

        if(str == "armours") {
                say("Loxie says: 'Yes i can make cloaks from animal hides.'\n");
                return 1;
        }
        if(str == "help") {
			say("Loxie says: 'I have heard that you can get sheep hide from farm,where lives an old woman.\n");
			return 1;
		}
		if(str == "build armour" || str == "build") {
			say("Loxie says: 'I can make two types of armours, wolf and sheep cloak.'\n");
			return 1;
		}
        if(str == "wolf cloak") {
			if(!ob) {
			say("Loxie says: 'But you don't have a wolf hide.'\n");
			return 1;
		}
        say("Loxie says: 'Yes that wolf hide looks intresting maybe i can make something out of it'.\n");
        write("You give the hide to Loxie and she start to making something from it.\n");
        destruct(ob);
        award = clone_object("/wizards/neophyte/city/eq/wolfcloak");
        move_object(award, this_player());
        write("Loxie gives you something.\n");
        say("loxie gives something to "+this_player()->query_name()+".\n",this_player());
        return 1;
}
sheep = present("lampaan_talja", this_player());
if(str == "sheep cloak") {
	if(!sheep) {
		say("Loxie says: 'But you don't have a sheep hide.'\n");
		return 1;
	}
	destruct(sheep);
	award1 = clone_object("/wizards/neophyte/city/eq/sheepcloak");
	move_object(award1, this_player());
	write("Loxie gives you something.\n");
	say("Loxie gives something to "+this_player()->query_name()+".\n",this_player());
	return 1;
}

say("Loxie says: 'I dont know anything about that.\n");
return 1;
}

monster_died() {
	call_other("/wizards/neophyte/city/armour_shop.c", "set_killer", this_player()->query_name());
	return 0;
}
