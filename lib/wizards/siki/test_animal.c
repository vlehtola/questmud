inherit "obj/monster";

reset(arg) {
	 string chat_str;
     ::reset(arg);
     if(arg) {return; }
     set_name("rabbit");
     set_level(20+random(10));
     set_gender(0);
     set_al(-15+random(10));
     set_alias("possessed");
     set_alt_name("possessed rabbit");
     set_move_at_reset();
     set_short("A possessed rabbit");
     set_long(
	 "Rabbits are usually very peaceful and fluffy, but something says that this rabbit is very violent and dangerous. "+
	 "The fur of this beast is almost full of blood, but still some white spots can be seen. Eyes of this rabbit "+
	 "are full of rage. This mighty beast looks like attacking soon to somewhere, because it moves like a cat when hunting.\n");
	set_animal();
	set_race("rabbit");
	set_block_dir(({ "west","east","north","south", })[random(4)]);
	set_aggressive(1);
	set_str(query_str()+40);
	set_max_hp(query_hp()+4000);
	set_hp(query_max_hp());
	if (!chat_str) {
	chat_str = allocate(2);
	chat_str[0] = "The rabbit shrieks in pain\n";
	chat_str[1] = "A blood drops from the fur of rabbit.\n";
	       }
    load_chat(5, chat_str);
	}
