inherit "obj/monster";

reset(arg) {
    object armour;
        ::reset(arg);
    if(arg) { return; }
set_level(40);
    call_other(this_object(), "set_name", "Demon");
    call_other(this_object(), "set_alias", "demon");
    call_other(this_object(), "set_short", "A Bloodred Demon of Morfeus");
    call_other(this_object(), "set_long",
 				"This demon is enormous and extremely muscular. The skin is blood red. It has long claws\n"
			        "and sharp teeth. Demon growls menacily and is very hostile.\n");
    call_other(this_object(), "set_al", -40);
    set_spell_chance(90, "exs brr blt");
    set_skill("cast ice", 90);
    set_skill("cast essence", 90);
    set_skill("cast bolt", 90);
    set_skill("cast grasp", 90);
    set_skill("quick spelling", 50);
    set_skill("mana control", 50);
    set_skill("attack", 100);
    set_skill("tumble", 5);
    set_skill("critical", 30);
    set_skill("dodge", 30);
    call_other(this_object(), "set_aggressive", 1);
    set_block_dir("west");
    set_block_message("Demon blocks your pitiful attempt to flee.\n");
    set_experience(666);
}
