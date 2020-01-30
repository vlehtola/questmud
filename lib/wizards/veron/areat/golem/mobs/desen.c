inherit "obj/monster";
int e = random(3);

reset(arg) {
    object ring,brac,hans,miek;
    ::reset(arg);
    if(arg) { return; }
    set_race("golem");
    set_level(random(5)+68);
    set_str(query_str()*3);
    set_con(query_con()*2);
    set_max_hp(query_hp()+50000);
    set_name("Desencantar");
    set_alias("golem");
    set_short("Desencantar, the iron golem");
    set_long("Desencantar is a HUGE iron golem. Otherwise than the other\n"+
             "golems, he seems to be intelligent. The golem's eyes\n"+
		 "burn red as it stares at you, it's eyes reflecting pure\n"+
             "hatred. Desencantar is wielding a huge flaming scimitar in\n"+
		 "his hand.\n");
		

    set_al(-200);
    set_aggressive(0);
    set_skill("slashing", 100);
    set_skill("enhance criticals", 100);
    set_skill("throw weight", 100);
    set_skill("strike", 100);
    set_skill("agility", 50);
    set_skill("tumble", 45);
    set_skill("critical", 40);
    set_skill("doublehit", 90);
    set_skill("double strike", 100);
    set_skill("stun", 40);
    set_skill("riposte", 70);
    set_skill("foresee attack", 50);
    set_skill_chance("strike", 50);
    set_log();
 
  if(e == 0) {
   ring = clone_object("/wizards/veron/areat/golem/items/ring");
    move_object(ring, this_object());
    init_command("wear ring");      
   miek = clone_object("/wizards/veron/areat/golem/items/desuring");
    move_object(miek, this_object());
    init_command("wear ring");     
}
  if(e == 1) {
    brac = clone_object("/wizards/veron/areat/golem/items/brasu");
    move_object(brac, this_object());
    init_command("wear protectors");      
   miek = clone_object("/wizards/veron/areat/golem/items/desuring");
    move_object(miek, this_object());
    init_command("wear ring");     
}
  if(e == 2) {
    hans = clone_object("/wizards/veron/areat/golem/items/gloves");
    move_object(hans, this_object());
    init_command("wear gloves");      
   miek = clone_object("/wizards/veron/areat/golem/items/desuring");
    move_object(miek, this_object());
    init_command("wear ring");     
}
       
      
   
}

