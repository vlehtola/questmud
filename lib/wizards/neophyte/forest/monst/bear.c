inherit "obj/monster";
reset(arg) {
        ::reset(arg);
        if(arg) {return; }
        set_name("bear");
        set_alias("brown bear");
        set_level(3);
        set_gender(0);
        set_al(0);
        set_animal();
        set_short("A young brown bear");
        set_long("It is very strong and big looking brown bear.\n"+
                 "It has a brown fur, which is little dirty.\n");
}
