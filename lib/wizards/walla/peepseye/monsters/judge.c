inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(30);
    set_name("judge");
    set_alias("monster");
    set_gender(1);
    set_short("Judge Mike");
    set_long("Judge Mike is the one that keeps the order here in town. He is the one that decides of the rules,\n"+
             "in concordance with the sheriff. Judge Mike has sentenced many men to the rope, and to this day,\n"+
             "he has the reputation of being the meanest judge alive. Not bribable and sticks strictly to the justice.\n");
    set_al(3);
    set_aggressive(0);
    set_move_at_random(0);   
    set_log();

}



