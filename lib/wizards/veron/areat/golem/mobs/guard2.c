inherit "obj/monster";

reset(arg) {
    
    object armour,scimitar;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
 set_race("human");
    set_level(random(10)+30);
    set_str(query_str()+20);
    set_str(query_con()+20);
    set_name("guard");
    set_alias("human");
    set_short("A tough-looking guard");
    set_long("This guard looks aware. He stands still and \n"+
             "watches your every move carefully.\n");
             
    set_al(10);
    set_aggressive(0);
    
   armour = clone_object("/wizards/veron/areat/golem/items/chainmail");
    move_object(armour, this_object());
    init_command("wear mail");      
   scimitar = clone_object("/wizards/veron/areat/golem/items/scimitar");
    move_object(scimitar, this_object());
    init_command("wield scimitar");     
   
}
