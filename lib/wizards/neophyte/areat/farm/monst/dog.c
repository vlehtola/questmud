inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }

    set_level(random(5)+15);
    set_name("dog");
    set_alias("sheepdog");
    set_short("A golden sheepdog");
    set_long("The dog looks strong and wise. It has been trained to look after the\n"+
             "sheep and prevent them from getting lost.\n");
    set_gender(0);
    set_animal();
}

