inherit "obj/monster";

reset(arg) {
    int i;

    object armour,armour2,weapon;
    ::reset(arg);
    if(arg) { return; }
    i = random(4);

    set_level((i+2)*3+54);
    set_name("wolf king");
    set_alias("king");
    set_race("human");
    set_str(query_str()*2);
    set_mage();
    set_max_hp(39000);
    set_hp(39000);

    set_short("The Wolf King sits on a throne here");
    set_long("A tall man clad in wolf furs sits here on a throne. He is wearing a crown\n"+
         "and many rings. There is a strong aura emitting from him. He has a long beard\n"+
         "and deep eyes. His hair is long and brown, the color of wolf fur. He holds\n"+
         "a huge hammer on his hand and a big book in the other. He has a large\n"+
         "necklace with diamons embedded in it around his neck. His face is covered\n"+ 
         "with many scars and he keeps looking around him all the time.\n");
    set_al(-75);
    set_aggressive(0);
    set_gender(1);
    set_log();
    set_skill("tumble", 70);

    weapon = clone_object("/wizards/shadow/Wolf/weapons/wolfkinghammer");
    move_object(weapon,this_object());
    init_command("wield warhammer");



    if(i==0) { 
    armour = clone_object("/wizards/shadow/Wolf/armour/wolfkingcloak");
    move_object(armour,this_object());
    init_command("wear cloak");
      }

    if(i==1) { 
    armour = clone_object("/wizards/shadow/Wolf/armour/wolfkingnecklace");
    move_object(armour,this_object());
    init_command("wear necklace");
    armour2 = clone_object("/wizards/shadow/Wolf/armour/wolfkingcloak");
    move_object(armour2,this_object());
    init_command("wear cloak");
     }

    if(i==2) { 
    armour = clone_object("/wizards/shadow/Wolf/armour/wolfkingnecklace");
    move_object(armour,this_object());
    init_command("wear necklace");
    armour2 = clone_object("/wizards/shadow/Wolf/armour/wolfkingcrown");
    move_object(armour2,this_object());
    init_command("wear helm");
     }
    if(i==3) {
    armour = clone_object("/wizards/shadow/Wolf/armour/wolfkingcrown");
    move_object(armour,this_object());
    init_command("wear helm");
    armour2 = clone_object("/wizards/shadow/Wolf/armour/wolfkingcloak");
    move_object(armour2,this_object());
    init_command("wear cloak");
     }
}






