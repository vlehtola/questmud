inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return; /* PERKELE! */
    set_level(23);
    set_name("Knight");
    set_gender(1);
    set_mage(1);
    set_race("human");
    set_alias("knight");
    set_short("A Dequan Knight, order of the Maple");
    set_long("A serious-looking knight. He wields no weapons.\n");
    set_al(50);
    set_block_dir("down");
    set_spell_chance(70, "exs fla blt");
    set_skill("mana control", 40);
    set_skill("cast essence", 80);
    set_skill("cast fire", 80);
    set_skill("cast bolt", 100);
    set_skill("chanting", 70);
    set_int(query_int() + 50);
}
