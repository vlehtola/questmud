inherit "obj/monster";
int i = random(4);
int ekstroja=0;

reset(arg) {
    object weapon,armour,armour2,armour3,weapon2,superkvest;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    set_level(80 + (i * 2));
    call_other(this_object(), "set_name", "Darvox");
    call_other(this_object(), "set_alias", "darvox");
    call_other(this_object(), "set_short", "Darvox, the master of the elements");
    call_other(this_object(), "set_long", "This is Darvox, one of the most dreaded magic-users in the realm.\n" +
                                          "The undisputed leader of the black-robed magic users is fairly\n" +
                                          "young and tall. The air around him crackles with magical energy.\n");
    call_other(this_object(), "set_al", -20);
 
    call_other(this_object(), "set_aggressive", 1);
    set_log();
    set_mage(10);
    set_extra(1);

    weapon = clone_object("/wizards/nalle/area/eq/darvstaff2002");
    move_object(weapon, this_object());
//    init_command("wield staff");

    armour = clone_object("/wizards/nalle/area/eq/darvrobes2002");
    move_object(armour, this_object());
    init_command("wear robes");
    armour2 = clone_object("/wizards/nalle/area/eq/darvboots2002");
    move_object(armour2, this_object());
    init_command("wear boots");
 
    armour3 = clone_object("/wizards/nalle/area/eq/darvring");
    move_object(armour3, this_object());
    init_command("wear ring"); 
 
    weapon2 = clone_object("/wizards/nalle/area/eq/newredemptor");
    move_object(weapon2, this_object());
//    init_command("wield axe"); 

    superkvest = clone_object("/wizards/nalle/area/eq/darvstaff2");
    move_object(superkvest, this_object());

}

extra() {
    object ekstramosa;

    if (!attacker_ob) { 
        return; 
    }

  if(ekstroja<30)
   if(!present("mage",environment(this_player())))
    if(random(25) == 0) {
        ekstramosa = clone_object("/wizards/nalle/area/monsters/blackrobe");    
        move_object(ekstramosa, environment(this_object()));
        say("Darvox flinches and roars 'Disciples. Attend!'\n");
        say("A blackrobed mage teleports into the room.\n");
        ekstroja++;
    }
   if(ekstroja<50)
   if(!present("liveone",environment(this_player())))
    if(random(13) == 0) {
        ekstramosa = clone_object("/wizards/nalle/area/monsters/liveone");    
        move_object(ekstramosa, environment(this_object()));
    say("Darvox speaks dark words of magic.\n");
    say("A corpse lets out a muffled scream and gets up.\n");
        ekstroja++;
    }
}

