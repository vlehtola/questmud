inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    set_level(15);
    set_name("elf");
    set_alias("female");
    set_short("A sea-elven female");
    set_long("A beautiful young sea-elven woman, with bluish skin.\n");
    set_al(9);
    set_spell_chance(80, "chl hea les");
    set_skill("channel", 90);
    set_skill("cast heal", 90);
    set_skill("cast lesser", 90);
    set_skill("mana control", 50);
    set_skill("chanting", 40);
}
