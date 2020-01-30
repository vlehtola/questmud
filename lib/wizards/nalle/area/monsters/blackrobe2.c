inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    set_level(21);
    set_name("mage");
    set_mage(1);
    set_race("human");
    set_gender(2);
    set_short("A black robed mage");
    set_long("An apprentice, clad in black robes.\n");
    set_al(-5);
    set_spell_chance(80, "exs brr blt");
    set_aggressive(1);
    set_block_dir("up");
    set_skill("cast essence", 90);
    set_skill("cast ice", 90);
    set_skill("cast bolt", 90);
    set_skill("mana control", 50);
    set_skill("chanting", 40);
}
