inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(50);
    set_name("ymiel");
    set_alias("demon");
    set_short("Ymiel, Guardian demon summoned by Darvox");
    set_long("Ymiel is the materialization of your nightmares. Death, pain and blood\n" +
             "combines in it, leaving behind retroactive flashbacks to every adventurer\n"+
             "who meets it. Its face is covered with black hood, as its whole body is\n"+
             "clothed in dark cloak. Only its bright red eyes are visible.\n" +
             "It is a member of the demon race.\n");
    set_max_hp(55000 + random(6000));
    set_hp(query_max_hp());
    set_al(-50);
    set_spell_chance(60, "exs fla blt");
    set_aggressive(1);
    set_skill("cast essence", 56);
    set_skill("cast fire", 56);
    set_skill("cast bolt", 56);
    set_skill("mana control", 13);
    set_skill("chanting", 13);
    set_skill("axes", 90);
    set_skill("cut", 90);
    set_skill("criticals", 100);
    set_skill("enhance criticals", 80);
    set_block_dir("up");
    set_gender(0);
    set_mage(1);

    weapon = clone_object("/wizards/nalle/area/eq/demaxe");
    move_object(weapon, this_object());
    init_command("wield axe");
}

