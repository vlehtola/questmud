inherit "obj/monster";
 
reset(arg) {
    int i;
    object weapon,weapon2;
    object armour,armour2;
    ::reset(arg);
    if (arg) { return; }
    i = random(3);
    set_level((i+1)*4+50);
    set_name("tyrael");
    set_alias("paladin");
    set_alt_name("commander");
    set_short("Tyrael the paladin commander");
    set_long("Tyrael is guarding the meteor and lets no one to touch\n"+
             "it. Tyrael's shield has the same glow as the meteor.\n");
    set_al(100);
    set_race("human");
    set_mage(1);
    set_str(query_str()*2);
    set_log();
    set_skill("shield bash", 100);
    set_skill("stun", 100);
    set_skill("tumble", 60);
    set_skill("tremendous blow", 80);
    set_skill_chance("tremendous blow", 12);

    weapon = clone_object("/wizards/grathlek/area1/eq/shield.c");
    move_object(weapon, this_object());
    init_command("wield shield");

    weapon2 = clone_object("/wizards/grathlek/area1/eq/tyraxe.c");
    move_object(weapon2, this_object());
    init_command("wield axe");

      if(i==0) { 
    armour = clone_object("/wizards/grathlek/area1/eq/tyro.c");
    move_object(armour, this_object());
    init_command("wear robes");
      }

    if(i==1) { 
    armour = clone_object("/wizards/grathlek/area1/eq/hyto.c");
    move_object(armour, this_object());
    init_command("wear gauntlets");
     }

    if(i==2) { 
    armour = clone_object("/wizards/grathlek/area1/eq/tyro.c");
    move_object(armour, this_object());
    init_command("wear robes");
    armour2 = clone_object("/wizards/grathlek/area1/eq/hyto.c");
    move_object(armour2, this_object());
    init_command("wear gauntlets");
     }
}
