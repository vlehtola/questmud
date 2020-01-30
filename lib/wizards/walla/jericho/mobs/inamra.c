inherit "obj/monster";
 
reset(arg) {
    object dress,ring;
    ::reset(arg);
    if (arg) return;
    set_level(29+random(3));
    set_name("inamra");
    set_alias("woman");
    set_short("Inamra, the lady in red");
    set_long("Inamra has come here to purchase fine fabrincs from Init\n"+
             "Inamra is wearing thin red dress which shows her contours\n"+
             "clearly through the fabric. Inamra is actually quite a \n"+
             "good looking woman, although rumours have it that she eats\n"+
             "from the bushy plate.\n");
    set_al(35);
    set_gender(2);
    set_race("human");
    

    dress = clone_object("/wizards/walla/jericho/stuph/inamra-dress");
    move_object(dress, this_object());
    init_command("wear dress");
 
    ring = clone_object("/wizards/walla/jericho/stuph/inamra-ring");
    move_object(ring, this_object());
    init_command("wear ring");
}
