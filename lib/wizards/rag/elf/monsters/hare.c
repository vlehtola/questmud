inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(4);
        set_name("hare");
        set_animal();
        set_short("A brown hare is here eating grass");
        set_long("You see a brown hare. It is very cuddly\n"+
                "and small. Only a very evil person would\n"+
                "want to kill this innocent creature.\n");
        set_al(5);
        set_aggressive(0);
}
