inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
set_mage();
    set_level(20);
    set_name("wraith");
    set_short("A wraith of a dead citizen of Jericho");
    set_long("This wraith hovers 2 feet in the air.\n");
    set_al(0);
    set_spell_chance(100, "exs brr blt");
    set_aggressive(0);
set_undead(1);
    set_skill("cast essence", 45);
    set_skill("cast ice", 45);
    set_skill("cast bolt", 70);
    set_skill("mana control", 20);
      set_skill("chanting", 80);
    set_dead_ob(this_object());
}
