inherit "obj/monster";
int i = random(4);
reset(arg) {
    object weapon,armour,armour2,armour3,weapon2,superkvest;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    set_level(90 + (i * 3));
    call_other(this_object(), "set_name", "Darvox");
    call_other(this_object(), "set_alias", "darvox");
    call_other(this_object(), "set_short", "Darvox, the master of the elements");
    call_other(this_object(), "set_long", "This is Darvox, one of the most dreaded magic-users in the realm.\n" +
                                          "The undisputed leader of the black-robed magic users is fairly\n" +
                                          "young and tall. The air around him crackles with magical energy.\n");
    call_other(this_object(), "set_al", -60);
 
    call_other(this_object(), "set_aggressive", 1);
    set_log();
    set_mage(10);

    weapon = clone_object("/wizards/nalle/area/eq/darvstaffnew");
    move_object(weapon, this_object());
    init_command("wield staff");

    if(i == 0) {
    armour = clone_object("/wizards/nalle/area/eq/newdarvrobes");
    move_object(armour, this_object());
    init_command("wear robes");
    armour2 = clone_object("/wizards/nalle/area/eq/newdarvboots");
    move_object(armour2, this_object());
    init_command("wear boots"); }
 
    if(i == 2) { armour2 = clone_object("/wizards/nalle/area/eq/newdarvboots");
    move_object(armour2, this_object());
    init_command("wear boots"); 
    armour3 = clone_object("/wizards/nalle/area/eq/darvring");
    move_object(armour3, this_object());
    init_command("wear ring"); }
 
    if(i == 1) { armour3 = clone_object("/wizards/nalle/area/eq/darvring");
    move_object(armour3, this_object());
    init_command("wear ring"); }
 
    if(i == 3) { weapon2 = clone_object("/wizards/nalle/area/eq/redemptor");
    move_object(weapon2, this_object());
    init_command("wield axe"); 
    clone_object("/wizards/nalle/area/eq/newdarvrobes");
    move_object(armour, this_object());
    init_command("wear robes"); }

    superkvest = clone_object("/wizards/nalle/area/eq/darvstaff2");
    move_object(superkvest, this_object());
    init_command("smile");

}
