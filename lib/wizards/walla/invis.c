inherit "obj/monster";
 
reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 25);
    call_other(this_object(), "set_name", "stalker");
    call_other(this_object(), "set_alias", "monster");
    call_other(this_object(), "set_short", "");
    call_other(this_object(), "set_long", "This invisible stalker hides out in the dark backstabbing\n" +
                                          "you every now and then.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

   set_spell_chance(100, "exs poi blt");
    set_aggressive(0);
    set_skill("cast essence", 100);
    set_skill("cast poison", 100);
    set_skill("cast bolt", 100);
    set_skill("mana control", 100);
    set_skill("chanting", 69);
    set_skill("quick chant", 100);
    set_skill("quick spelling", 100);
    set_dead_ob(this_object());
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
}
