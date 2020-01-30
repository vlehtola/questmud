inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("silvery staff");
    set_alias("staff");
    set_short("Thin silvery staff");
    set_long("A long silvery staff. It should be presented to the mayor of Chamron \n" +
                    "as proof of having slayed Darvox.\n");
    set_material(6);
    set_class(21);
    set_weapon_type("bludgeon");
    set_value(210);
    set_weight(2);
}
