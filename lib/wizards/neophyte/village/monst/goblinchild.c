inherit "obj/monster";
reset(arg) {
	object armour;
        ::reset(arg);
        if(arg) {return; }
        set_name("goblin");
        set_level(15+random(6));
        set_al(-30);
        set_gender(1);
        set_race("goblin");
        set_alias("child");
        set_short("A goblin child is here playing with a toy boat");
        set_long("A small goblin child. He is playing with a boat and he looks\n"+
                 "like a having good time. He is wearing typically child clothes,\n"+
                 "nothing special just a trousers and shirt.\n");
        armour = clone_object("/wizards/neophyte/village/eq/armour.c");
        move_object(armour, this_object());
        init_command("wear all");
        set_skill("kick", 50);
        set_skill_chance("kick", 10);
}
