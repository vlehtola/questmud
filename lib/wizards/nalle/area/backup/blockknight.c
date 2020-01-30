inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    set_level(23);
    set_name("Knight");
    set_alias("knight");
    set_short("A Dequan Knight, order of the Maple");
    set_long("A serious looking knight. He wields no weapons.\n");
    set_al(5);
    set_spell_chance(80, "exs fla grs");
    set_block_dir("down");
    set_skill("cast essence", 90);
    set_skill("cast fire", 90);
    set_skill("cast grasp", 90);
    set_skill("mana control", 50);
    set_skill("chanting", 40);
}
