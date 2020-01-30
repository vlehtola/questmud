inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_race("golem");
    set_level(random(3)+44);
    set_str(query_str()+50);
    set_max_hp(query_hp()+15000);

    set_name("golem");
    set_alias("golem");
    set_short("A fire golem");
    set_long("A creature created of magic and fire. The heat\n"+
              "coming from it makes you sweat and your clothes\n"+
		  "begin to smoke. You wonder why the room isn't\n"+
		  "on fire.\n");
             
    set_al(10);
    set_aggressive(0);
    set_resists("fire",100);
    set_skills("tumble", 10);
    set_skills("stun", 50);
    set_skills("critical", 50);
    set_skills("bare hands", 100);
 
}

     
   
