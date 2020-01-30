inherit "obj/monster";
object armour;
object weapon;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name("Shinryu");
    set_alias("dragon");
    set_level(100);  
    set_special(10);
    set_str(query_str()*3);
    set_max_hp(query_max_hp()*2);
    set_skill("bare hands", 100);
    set_skill("agility", 100);
    set_skill("inner strength", 100);
    set_skill("tumble", 80);
    set_skill("punch", 100);
    set_skill("critical", 100);
    set_skill("enhance criticals", 100);
    set_skill("find weakness", 100);
    set_al(0);
    set_alias("shinryu");
    set_short("Shinryu the Dragon from Hell");
    set_long("This enormous dragon is capable of shredding it's enemies into\n" +
             "pieces. Mayby you should start running and leave this ferocious beast\n" +
             "alone\n");
    set_aggressive(0);
    armour = clone_object("wizards/rehti/dormund/obj/shinbracu.c");
    move_object(armour, this_object());
    armour = clone_object("wizards/rehti/dormund/obj/shinleg.c");
    move_object(armour, this_object());
    weapon = clone_object("wizards/rehti/dormund/obj/ekuaxe.c");
    move_object(weapon, this_object());
    set_log();
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Shinryu bites your head off\n");
  ob->hit_with_spell(3000, "physical");
}