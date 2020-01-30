inherit "obj/monster";

reset(arg) {
    int i;
    int j;
    string str;
    int lvl;
    ::reset(arg);
    if (arg) return;
    i= random(5);
    if(i==0) str = "tiny";
    if(i==1) str = "small";
    if(i==2) str = "medium";
    if(i==3) str = "large";
    if(i==4) str = "HUGE";
    j= i;
    if(j==0) lvl = 19;
    if(j==1) lvl = 25;
    if(j==2) lvl = 30;
    if(j==3) lvl = 40;
    if(j==4) lvl = 48;
    set_level(lvl+random(4));
    set_name("lemming");
    set_alias("blocker");
    set_short("A "+str+" blocker lemming");
    set_long("The lemming is a small rodent, that has started standing on it's hind legs.\n"+
             "The lemming seems to have evolved into a very distinct population under the\n"+
             "mountains. They wear green pants and blue shirts, and live in huge colonies.\n");
    set_al(50);
    set_aggressive(1);
    set_block_dir(({"north", "west", "east", "south", "northwest", "southwest", "southeast", "northeast",})[random(8)]);
    set_gender(0);
    set_animal();


}
