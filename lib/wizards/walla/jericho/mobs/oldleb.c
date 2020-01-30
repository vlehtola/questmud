inherit "obj/monster";
 
reset(arg) {
    int i,q;
    string chat_str;
    object armour,armour2,armour3,armour4,weapon;
    ::reset(arg);
    if(arg) { return; }
    i = random(6);
 
    set_level((i+2)*5+55);
    set_name("Leb-Kamar");
    set_alias("leb");
    set_alt_name("priest");
    set_race("human");
    set_str(query_str()*2);
    set_max_hp(query_hp() - 25000);
    set_block_dir("south");
    set_mage();
    set_short("Leb Kamar, evil warlord of Jericho");
    set_long("Leb-Kamar is here looking out from his room window, and shouting\n" +
             "orders to the slaves in the bazar downstairs. He looks very\n" +
             "terrifying and is very pissed that you have entered his privacy in\n" +
             "private chamber.\n");
    set_al(-75);
    set_aggressive(1);
    set_gender(1);
    set_log();
 
 
    weapon = clone_object("/wizards/walla/area/weapons/lebsword");
    move_object(weapon,this_object());
    init_command("wield sword");   
 
    armour4 = clone_object("/wizards/walla/area/armour/piece.c");
    move_object(armour4,this_object());
 
    if(i==0) {
    armour = clone_object("/wizards/walla/area/armour/leblegging");
    move_object(armour,this_object());
    init_command("wear leggings");
    armour2 = clone_object("/wizards/walla/area/armour/lebring");
    move_object(armour2,this_object());
    init_command("wear ring");
      }
 
    if(i==1) {
    armour = clone_object("/wizards/walla/area/armour/lebring");
    move_object(armour,this_object());
    init_command("wear ring");
    armour2 = clone_object("/wizards/walla/area/armour/lebbracers");
    move_object(armour2,this_object());
    init_command("wear bracers");
     }
 
    if(i==2) {
    armour = clone_object("/wizards/walla/area/armour/leblegging");
    move_object(armour,this_object());
    init_command("wear leggings");
    armour2 = clone_object("/wizards/walla/area/armour/lebbracers");
    move_object(armour2,this_object());
    init_command("wear bracers");
     }
    if(i==3) {
    armour = clone_object("/wizards/walla/area/armour/leblegging");    
    move_object(armour,this_object());
    init_command("wear leggings");
    armour2 = clone_object("/wizards/walla/area/armour/lebbracers");
    move_object(armour2,this_object());
    init_command("wear bracers");
    armour3 = clone_object("/wizards/walla/area/armour/lebring");
    move_object(armour3,this_object());
    init_command("wear ring");
     }
 
    if(i==4) {
    armour = clone_object("/wizards/walla/area/armour/lebring");
    move_object(armour,this_object());
    init_command("wear ring");
    armour2 = clone_object("/wizards/walla/area/armour/lebplate");
    move_object(armour2,this_object());
    init_command("wear plate");
    armour3 = clone_object("/wizards/walla/area/armour/leblegging");
    move_object(armour3,this_object());
    init_command("wear leggings");
     }
 
    if(i==5) {
    armour = clone_object("/wizards/walla/area/armour/leblegging");
    move_object(armour,this_object());
    init_command("wear leggings");
    armour2 = clone_object("/wizards/walla/area/armour/lebbracers");
    move_object(armour2,this_object());
    init_command("wear bracers");
    armour3 = clone_object("/wizards/walla/area/armour/lebplate");
    move_object(armour3,this_object());
    init_command("wear plate");
     }
 
}
 
 

