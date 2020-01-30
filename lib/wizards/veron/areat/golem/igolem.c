inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(random(3)+47);
    set_str(query_str()+55);
    set_str(query_con()+70);
    set_max_hp(query_hp()+15000);
    set_name("golem");
    set_alias("golem");
    set_race("golem");
    set_short("A HUGE iron golem");
    set_long("A creature formed of pure iron to serve it's master.\n"+
              "The golem glitters as light reflects from it's smooth \n"+
		  "skin.\n");
             
    set_al(10);
    set_aggressive(0);
    
      set_skill("strike", 80);
    set_skill("tumble", 10);
 set_skills("bare hands", 100);
 set_skill("doublehit", 80);

   
}