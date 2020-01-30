inherit "obj/armour";

start() {
    set_slot("cloak");
    set_name("cloak");
    set_short("Pure white cloak");
    set_long("This cloak is made of the finest silk. It feels very light\n"+
                "but still it offers good protection from wind and rain.\n"+
                "It is shining of pure white light. There is a beautiful\n"+
                "silvery tree ornament at the back");
    set_weight(10);
    set_value(2000);
    set_light(2);
    set_stats("con",3);
    set_resists("cold",6);
}
