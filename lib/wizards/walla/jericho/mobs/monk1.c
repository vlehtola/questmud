inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(28+random(5));
    set_name("monk");
    set_alias("monk");
    set_short("Monk of the red moon");
    set_long("The monks of the moon have started a congregation here in Jericho, when\n"+
             "Leb-Kamar left the area. During that time, they became very popular, as they\n"+
             "taught the citizens some ancient oriental arts, to defend themselves. Even now\n"+
             "the monks are considered deadly to their foes.\n");
    set_al(0);
    set_gender(1);
    set_block_dir("down");
    set_race("human");
 
    
}
