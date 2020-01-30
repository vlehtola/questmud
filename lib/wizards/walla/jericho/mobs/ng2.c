inherit "obj/monster";

reset(arg) {
    object torso,gloves,shard1;
    ::reset(arg);
    if (arg) return;
    set_level(45);
    set_experience(2891000);
    set_str(query_str() + 250);
    set_dex(query_dex() + 200);
    set_name("nightgaunt");
    set_alias("undead");
    set_mage(1);
    set_short("A nightgaunt (undead)");
    set_long("Before you hovers a black creature, with smooth, oily, whale-like surfaces,\n"+
             "and unpleasant horns that are curved inward toward each other. A pair of bat-like\n"+
             "wings are spread out on the creatures back. As the creature turns you can see a barbed\n"+
             "tail, that lashes, yet making no sound.\n");
    set_al(-200);
    set_gender(1);
    set_log();

    torso = clone_object("/wizards/walla/jericho/stuph/hfplate");
    move_object(torso, this_object());
    init_command("wear plate");

    gloves = clone_object("/wizards/walla/jericho/stuph/vbgloves");
    move_object(gloves, this_object());
    init_command("wear gloves");

    shard1 = clone_object("/wizards/walla/jericho/stuph/obj2");
    move_object(shard1, this_object());

}


