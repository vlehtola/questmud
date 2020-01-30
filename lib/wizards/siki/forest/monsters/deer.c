inherit "obj/monster";
reset(arg) {
	 string chat_str;
     ::reset(arg);
     if(arg) {return; }
     set_name("deer");
     set_level(30+random(10));
     set_gender(0);
     set_al(-20+random(10));
     set_alias("raging");
     set_alt_name("raging deer");
     set_move_at_reset();
     set_short("A raging deer");
     set_long(
	 "Whole dear is covered in blood and entrails of animals. Some of the blood\n"+
	 "seems to be its own, but most of it seems to belong to the unlucky victims\n"+
	 "which have stepped in this deer's way. The horns of this creature are broken\n"+
         "and twisted like somebody had needed those and didn't have time to take them\n"+
         "peacefully. In the eyes of this creature can be seen a rage that has\n"+
         "developed in many years.\n");

	set_animal();
	set_block_dir(({ "west","east","north","south", })[random(4)]);
	set_aggressive(1);
	set_str(query_str()+40);
	set_max_hp(query_hp()+4000);
	set_hp(query_max_hp());
		set_skill("stomp",50);
		set_skill_chance("stomp", 50);
	if (!chat_str) {
	chat_str = allocate(2);
	chat_str[0] = "The deer seems to be ready to force its horns inside your heart!\n";
	chat_str[1] = "A blood drops from the body of deer.\n";
	       }
    load_chat(5, chat_str);
	}
