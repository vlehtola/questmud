inherit "obj/monster";
reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
    set_name("master");
    set_alias("dark");
    set_short("The Dark Master of the Evil Realms");
    set_long("This is the dark master of all evils and darkness, he is\n"+
             "standing here waiting for something to enter and destroy it.\n"+
             "He himself is hundreds of years old, a descendant of the\n"+
             "god of darkness who started the war with the armies of goodness,\n"+
             "he even wears the legendary armor that his father wore during\n"+
             "the battles. He stands here waiting to destroy you and the rest of the world.\n");
    set_al(-1000);
    set_hp(1);
    set_max_hp(1);
    set_aggressive(0);
    set_race("human");
    set_mage();
    set_spell_chance(50, "exs ssh bls");
    set_skill("cast essence", 80);
    set_skill("cast fire", 80);
    set_skill("cast grasp", 80);
    set_skill("mana control", 80);
}
