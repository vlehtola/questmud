inherit "obj/monster";

reset(arg) {

 object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(10);
    set_name("Ogre");
    set_alias("warrior");
    set_short("An ogre ice-warrior <ANGRY>");
    set_long("An ogre, crossbreed of an orc and a giant. He is an warrior of the ogre race.\n"+
             "The ogre ice-warriors are low paid, but honoured among their community. The\n"+
             "ogres are rumoured to be very cruel race. The warrior is covered with snow or\n"+
             "at least it seems like it's snow. Or is't his white fur?\n");
    set_aggressive(1);
    set_gender(1);
    set_al(10);
    set_race("ogre"); 
   

    weapon = clone_object("/wizards/duncan/icecaves/eq/axe.c");
    move_object(weapon, this_object());
    init_command("wield axe");
}
    


