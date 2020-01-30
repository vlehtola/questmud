
inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_name("elemental");
    set_alias("fire");
    set_alias("elemental");
    set_race("human");
    set_gender(2);
    set_mage(1);
    set_special(10); 
    set_al(0);  
    set_aggressive(1);    
    set_level(25+random(5));
    set_short("Conjured fire elemental protecting the mage.");
    set_long("This elemental has been created with magic to protect the\n"+
             "caster in combat. It can cause lots of damage to its opponents\n"+ 
             "and is quite resistant to every source of damage.\n");
set_skill("cast essence", 100);
set_skill("cast bolt", 100);
set_skill("cast ice", 100);
set_skill("mana control", 300);
set_mage();
set_skill("attack", 100);
set_skill("dodge", 30);
set_skill("parry", 40);
set_skill("critical", 50);
set_skill("attack", 100);
set_skill("bare hands", 100);
}
special_move() {
   object ob;
   ob = this_object()->query_attack();
   tell_object(ob, "The elemental throws a burning rock at you!\n");
   say("The elemental throws a burning rock at "+ob->query_name()+"!\n", ob);
   ob->hit_with_spell(150, "fire");
}
