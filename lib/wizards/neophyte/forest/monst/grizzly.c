inherit "obj/monster";
reset(arg) {
        ::reset(arg);
        if(arg) {return; }
        set_name("bear");
        set_alias("grizzly bear");
        set_level(16);
        set_gender(0);
        set_al(0);
        set_animal();
        set_short("A grizzly bear");
        set_long("It is very large bear. It reveals it's teeth as it notices you.\n"+
                 "It surely doesn't like you to be in here.\n");
        }
