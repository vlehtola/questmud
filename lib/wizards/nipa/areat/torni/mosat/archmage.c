inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_name("archmage");
    set_alias("mage");
    set_race("human");
    set_gender(1);
    set_mage(0);
    set_al(-20);  
    set_aggressive(0);    
    set_level(50+random(5));
    set_resists("cold", 20 + random(10));
    set_resists("fire", 20 + random(10));
    set_resists("electric", 20 + random(10));
    set_short("Archmage supervisor clad in red");
    set_long("Archmages erupt a aura of purest magic and are considerable\n"+
             "oppenent for whomever decides to challenge them. Although these\n"+
             "noteworthy mages seem to convey the aura of magic it seems to be\n"+
             "somewhat twisted or corrupted. If you take a closer look at these\n"+
             "mages they all seem to have a blank look in their eyes as if\n"+ 
             "they were under of some kind of a mental domination. However\n"+ 
             "these mages still are responsible for all training that is taking\n"+ 
             "place in this magetower. They are teaching apprentices and guiding\n"+
             "adepts in the ways of arcane arts.\n");

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
    set_skill("enhance weakness", 40);
    set_spell_chance(40, "kyo brr rhj");
    set_spell_chance(40, "kyo fla rhj");
    set_spell_chance(50, "kyo zzt rhj");
}
