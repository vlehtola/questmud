inherit "obj/armour";

start() {
set_class(8);
set_sub_type("leggings");
set_short("Leggings of the everlasting Fraternity");
set_long("The leggings are made of satin, because satin is comfortable and light\n"+
          "in use. Satin repels mainly water, but also some other elements. The\n"+
          "leggings are unadorned, but they look fine without any ornaments.\n"
          "A small stigma symbolizes two hands, which are shaking, is burned\n"+
          "in the leggings. The stigma symbolizes everlasting Fraternity");

    set_stats("int", 5);
    set_stats("wis", 10);
    set_stats("spr", 10);
    set_slot("legs");
    set_resists("cold", 10);
    set_resists("fire", 2);
}

