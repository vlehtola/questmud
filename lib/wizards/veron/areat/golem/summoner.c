inherit "obj/monster";

reset(arg) {
    object armour,staff;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_level(random(7)+45);
    set_str(query_str()+60);
    set_con(query_con()+60);
    set_name("summoner");
    set_alias("human");
 set_race("human");
    set_short("A summoner");
    set_long("An intelligent-looking old wizard dressed in a black robe.\n"+
             "He seems fully concentrated in his work.\n");
             
    armour = clone_object("/wizards/veron/areat/golem/items/robe");
    move_object(armour, this_object());
    init_command("wear robe");      
    
    staff = clone_object("/wizards/veron/areat/golem/items/staff");
    move_object(staff, this_object());
    init_command("wield staff");      

    set_al(10);
    set_aggressive(0);
    set_resists("fire",20);
    set_resists("electric", 20);
    set_resists("ice",10);
    set_skill("tumble", 10);
    set_skill("doublehit", 40);
    set_skill("critical", 30);
    
      
   
}