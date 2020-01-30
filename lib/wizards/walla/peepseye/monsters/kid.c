inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(5);
    set_name("boy");
    set_alias("kid");
    set_gender(1);
    set_short("A boy, throwing marbles on the street");
    set_long("This little kid, about 5-6 years old, is the future hope for the city of OilOhnRock. The population\n"+
             "being quite aged and not willing to work, these little brats are the offspring of the families.\n"+
             "The marble game that he is playing seems to amuse him to the point of swallowing the marbles.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(0);   
    
}


