inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_race("elemental");
    set_level(random(5)+45);
    set_str(query_str()+55);
    set_max_hp(query_hp()+5000);
    set_str(query_con()+50);
    set_al(10);
    set_aggressive(0);
    
    set_name("elemental");
    set_alias("elemental");
    set_short("An earth elemental");
    set_long("A massive earth elemental, a creature made of earth.\n"+
              "The elemental stands still, it will only move if it's\n"+
		  "master commands it or if attacked.\n"+
		  "The elemental is not wearing any visible armour\n");
             
    set_skill("strike", 80);
    set_skill("tumble", 10);
    set_skill("double strike", 40);
    set_skill("critical", 40);
    set_skill("find weakness", 50);
 set_skills("bare hands", 100);
    
    
      
   
}