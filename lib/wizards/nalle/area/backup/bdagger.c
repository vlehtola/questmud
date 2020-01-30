inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("dagger");
    set_short("A sharp dagger named The Presence of Death");
    set_long("This beautiful black dagger would surely sink into anyone's\n"+
 	      "back with ease.\n");
    set_class(60);
    set_weapon_type("dagger");
    set_value(50000);
    set_weight(1);
}
