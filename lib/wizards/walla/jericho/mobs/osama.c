inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(1);
    set_experience(6666666);
    set_hp(1);
    set_name("osama");
    set_alias("pawn");
    set_short("Osama Bin Laden, enemy of the state");
    set_long("This pawn stands straight up and doesn't seem to move.\n" +
             "He stands in the front row.\n");
    set_al(-90);
    
}
