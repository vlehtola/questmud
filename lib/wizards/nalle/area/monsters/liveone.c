inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }

    set_gender(0);
    set_animal(1);

    set_level(25);
    set_name("liveone");
    set_alias("creation");
    set_short("A failed creation, known as a liveone");
    set_long("This is one of Darvox's failed creations. It looks hideous.\n");

    set_al(-10);
    set_aggressive(1);
    set_block_dir("east");

    armour = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armour, this_object());
    init_command("wear armour");
}


