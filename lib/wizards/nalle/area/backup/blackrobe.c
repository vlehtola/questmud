inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    set_level(21);
    set_name("mage");
    set_short("A black robed mage");
    set_long("An apprentice clad in black robes.\n");
    set_al(-5);
    set_spell_chance(80, "exs fla grs");
    set_aggressive(1);
    set_block_dir("up");
    set_skill("cast essence", 90);
    set_skill("cast fire", 90);
    set_skill("cast grasp", 90);
    set_skill("mana control", 50);
    set_skill("chanting", 40);
    set_dead_ob(this_object());
}
