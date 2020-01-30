inherit "obj/monster";
reset(arg) {
	object armour;
        ::reset(arg);
        if(arg) {return; }
        set_name("goblin");
        set_level(23+random(3));
        set_al(-25);
        set_gender(0);
        set_race("goblin");
        set_short("A female Goblin");
        set_long("This goblin looks quite small and weak. She has a thin grey skin and there can\n"+
                 "be seen blood veins on the face of goblin. She has a grinning look on his round\n"+
                 "head and the eyes are constantly blinking, because of that light. She seems to\n"+
                 "be fearing something, maybe that light which is coming outside of the hut.\n");
        set_skill("kick", 100);
        set_skill_chance("kick", 30);
                armour = clone_object("/wizards/neophyte/village/eq/armour.c");
		        move_object(armour, this_object());
init_command("wear all");
}
