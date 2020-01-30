inherit "obj/monster";

reset(arg) {
  
    object scimitar;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_undead(1);
    set_level(random(10)+30);
    set_str(query_str()+30);
    set_str(query_con()+20);
    set_name("carcass");
    set_alias("citizen");
    set_short("Partly rotten citizen");
    set_long("Slowly stumbling forward, this living carcass still wears\n"+
             "the clothes he had on the moment he died. It stares forward\n"+
 	     "with empty eyesockets, and lets out faint groaning voices,\n"+
             "sending shivers down your spine.\n");
             
    set_al(-10);
    set_aggressive(0);
    
 
   scimitar = clone_object("/wizards/veron/areat/golem/items/scimitar");
    move_object(scimitar, this_object());
    init_command("wield scimitar");     

              
   
}
