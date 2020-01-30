inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("staff");
    set_short("The Chessmaster staff");
    set_long("This is a staff, with plenty of small chess figures carved in it. It seems that many people have been doing it for a while.\n");
    set_material(10);
    set_class(35);
    set_weapon_type("bludgeon");
    set_value(5000);
    set_weight(5);
}
