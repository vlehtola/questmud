inherit "obj/monster";
reset(arg) {
	object armour,legs;
        ::reset(arg);
        if(arg) {return; }
        set_name("goblin");
        set_level(25+random(6));
        set_al(-30);
        set_gender(1);
        set_race("goblin");
        set_alias("reclude");
        set_short("A goblin reclude is here reading a book");
        set_long("This goblin looks quite intelligence when compared other goblins.\n"+
                 "He is sitting one of the chairs and reading a book, sometimes turning\n"+
                 "a page. He is wearing a tall and narrow pointed red hat with one feather\n"+
                 "empadded on it. He is constantly cursing something when he is reading that\n"+
                 "that book.\n");
        armour = clone_object("/wizards/neophyte/village/eq/armour.c");
        move_object(armour, this_object());
        legs = clone_object("/wizards/neophyte/village/eq/legs.c");
        move_object(legs, this_object());
        init_command("wear all");
        set_mage(1, 25);
                set_hp(query_hp()*2);
		        set_max_hp(query_max_hp());
        set_log();
        set_max_hp(query_hp()*2);
        set_hp(query_max_hp());
}
