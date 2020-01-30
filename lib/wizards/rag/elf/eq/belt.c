inherit "obj/armour";

start() {
    set_slot("belt");
    set_name("belt");
    set_short("Belt of the master bard");
    set_long("This belt is made of sturdy leather. It was given to\n"+
                "Celebmir to honour his skills as a bard. It has a silver\n"+
                "buckle shaped like a harp. The belt seems to adjust to\n"+
                "fit you");
    set_weight(200);
    set_value(6000);
    set_stats("dex",6);
    set_stats("int",6);
    set_stats("spr",3);
}
