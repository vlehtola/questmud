inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_name("gavyn");
    set_alias("archmage");
    set_race("human");
    set_gender(1);
    set_mage(0);
    set_al(20);  
    set_aggressive(0);    
    set_level(60+random(3));
    set_resists("cold", 20 + random(15));
    set_resists("fire", 20 + random(15));
    set_resists("electric", 20 + random(15));
    set_short("Elder archmage tutor of Alsatia called 'Gavyn'");
    set_long("All the mages share the same ways of living and clothing in the tower but this\n"+ 
             "one looks different. Compared to others this one feels respected and maybe\n"+
             "a little feared amongst the other fellow mages. Looks like he works as an mentor\n"+
             "and caretaker in the tower. All the paperworks, requests, tests and lesson\n"+ 
             "schedules go through him. It seems he has noticed you and has something to say.\n"+ 
             "You wonder what would elderly mage want from an outsider. Maybe you should ask\n"+ 
             "him about help.\n");

  move_object(clone_object("/wizards/nipa/areat/torni/ekut/hat.c"),this_object());
  move_object(clone_object("/wizards/nipa/areat/torni/ekut/archrobe.c"),this_object());
  move_object(clone_object("/wizards/nipa/areat/torni/ekut/quarterstaff.c"),this_object());
     
    init_command("wear all");
    init_command("wield staff");
    
    set_skill("attack", 100);
    set_skill("dodge", 20);
    set_skill("parry", 20);
    set_skill("critical", 70);
    set_skill("attack", 100);
    set_skill("deceived attack", 30);
    set_skill("enhance criticals", 40);
    set_skill("find weakness", 40);
    set_skill("throw weight", 20);
    set_skill("blades", 100);
    set_skill("bludgeons", 100);
    set_skill("axes", 100);
    set_skill("slash", 80);
    set_skill("pound", 80);
    set_skill("cut", 80);
    set_skill("bare hands", 100);
    set_skill("punch", 100);
    set_skill("stun", 70);
    set_skill("tumble", 20);
    set_mage();
    set_skill("chanting", 100);
    set_skill("mana control", 100);
    set_skill("cast essence", 100);
    set_skill("cast bolt", 100);
    set_skill("cast storm", 100);
    set_skill("cast ice", 100);
    set_skill("cast fire", 100);
    set_skill("cast electric", 100);
    set_skill("lore of cold", 100);
    set_skill("knowledge of heat", 100);
    set_skill("theory of electricity", 100);
    // VULNI //
    set_skill("abjuration", 100);
    set_skill("cast abjuration", 100);
    set_skill("cast vulnerability", 100);
    set_skill("enhance weakness", 70);
    set_spell_chance(40, "kyo brr rhj");
    set_spell_chance(40, "kyo fla rhj");
    set_spell_chance(50, "kyo zzt rhj");

}
