inherit "obj/monster";
 
reset(arg) {
    int i,q;
    string chat_str;
    object armour,armour2,armour3,weapon;
    ::reset(arg);
    if(arg) { return; }
    i = random(6);
 
    set_level((i+2)*5+55);
    set_name("furukitsune");
    set_alias("furukitsune");
    set_alt_name("fox");
    set_race("human");
    set_str(query_str()*2);
    set_mage();
 
 
    set_short("Furukitsune, the old fox");
    set_long("Furukitsune was once the master of the temple, now retired.\n" +
             "These days Furukitsune mostly spends his time meditating in \n" +
             "the garden, although rumours have it, that he has not completely\n" +
             "given up, on fighting.\n");
    set_al(50);
    set_aggressive(0);
    set_gender(1);
    set_log();
 
 
    weapon = clone_object("/wizards/walla/area2/stuph/toibu");
    move_object(weapon,this_object());
    init_command("sword");
    init_command("wield sword");
  	
    armour3 = clone_object("/wizards/walla/area2/stuph/ying.c");    
    move_object(armour3,this_object());
     
    if(i==0) {
    armour = clone_object("/wizards/walla/area2/stuph/geta");
    move_object(armour,this_object());
    init_command("wear shoes");
    armour2 = clone_object("/wizards/walla/area2/stuph/turbocloak");
    move_object(armour2,this_object());
    init_command("wear cape");
      }
 
    if(i==1) {
    armour = clone_object("/wizards/walla/area2/stuph/geta");
    move_object(armour,this_object());
    init_command("wear shoes");
    armour2 = clone_object("/wizards/walla/area2/stuph/turbocloak");
    move_object(armour2,this_object());
    init_command("wear cape");
      }
 
    if(i==2) {
    armour = clone_object("/wizards/walla/area2/stuph/geta");
    move_object(armour,this_object());
    init_command("wear shoes");
    armour2 = clone_object("/wizards/walla/area2/stuph/turbocloak");
    move_object(armour2,this_object());
    init_command("wear cape");
      }
    if(i==3) {
 
    armour = clone_object("/wizards/walla/area2/stuph/geta");
    move_object(armour,this_object());
    init_command("wear shoes");
    armour2 = clone_object("/wizards/walla/area2/stuph/turbocloak");
    move_object(armour2,this_object());
    init_command("wear cape");
      }
 
    if(i==4) {
    armour = clone_object("/wizards/walla/area2/stuph/geta");
    move_object(armour,this_object());
    init_command("wear shoes");
    armour2 = clone_object("/wizards/walla/area2/stuph/turbocloak");
    move_object(armour2,this_object());
    init_command("wear cape");
      }
 
    if(i==5) {
    armour = clone_object("/wizards/walla/area2/stuph/geta");
    move_object(armour,this_object());
    init_command("wear shoes");
    armour2 = clone_object("/wizards/walla/area2/stuph/turbocloak");
    move_object(armour2,this_object());
    init_command("wear cape");
      }
 
}
 
