inherit "obj/monster";
ob=("bulut");

reset(arg) {

    ::reset(arg);
    set_level(2);
    set_hp(5000);
    set_name("man");
    set_alias("jack");
    set_short("Annoying man");
    set_long("Jack the fucker.\n");
    set_wc(1);
    set_ac(0);
    set_al(10);
    set_aggressive(0);

void tell_object(ob, "Cant catch me, ya FUCKER);

}

