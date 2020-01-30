inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) {return; }
    set_level(98);
    set_hp(650000);
    set_max_hp(650000);
    set_sp(150000);
    set_max_sp(150000);
    set_name("ishmail");
    set_alias("manipulator");
    set_al(20);
    set_spell_chance(70, "exs zzt blt");
    set_race("human");
    set_short("Ishmail Windicator, the weather manipulator");
    set_long("This is Ishmail. He is old and extremely wise man, but still\n" +
             "he  looks physically  tough person. The way  he controls the\n" +
             "controls the weather, makes cold vibrations slide all the way\n"+
             "in your spine\n");
    set_skill("cast essence", 80);
    set_skill("cast electric", 80);
    set_skill("cast storm", 80);
    set_skill("cast bolt", 80);
    set_skill("mana control", 50);
    set_skill("chanting", 70);
    set_skill("theory of electricity", 75);
    set_skill("power concentration", 60);
    set_skill("power channeling", 60);
    set_skill("power focusing", 70);
}