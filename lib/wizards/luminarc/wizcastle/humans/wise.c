inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(35);
    set_name("man");
    set_alias("man");
    set_short("Wise and old man searching something");
    set_long("This old man is wearing some old white rags. He looks very\n"+ 
             "old. Man has long grey hair and brown eyes. He is wearing\n"+
             "worn out wooden shoes and he stinks pretty bad.\n");
    set_gender(1);
    set_al(10);
    set_aggressive(0);
    set_race("human");

}

