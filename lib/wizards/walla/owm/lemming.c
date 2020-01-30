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
    j= random(5);
    if(j==0) lvl = 1;
    if(j==1) lvl = 11;
    if(j==2) lvl = 21;
    if(j==3) lvl = 31;
    if(j==4) lvl = 41;
    set_level(lvl);
    set_name("lemming");
    set_alias("rodent");
    set_short("A "+str+" lemming");
    set_long("This is a typical small rodent, that lives in the realm of Deleria. \n"+
             "The lemming is about 5 inches long, with a stout body and thick fluffy fur.\n"+
             "It has small ears, and a very short tail, and it's only boon is it's long claws.\n"); 
    set_al(50);
    set_gender(0);
    set_animal();


}
