inherit "obj/armour";

start() {
set_class(19);
    set_sub_type("cap");
    set_name("beret");
    set_alias("hat");
    set_short("A dark green beret with a golden eagle");
    set_long("This beret has belonged to a skilled fighter from the coast.\n"+
             "The beret is made out of strong cotton, and the golden eagle\n"+
             "shines in the sunlight.");
    set_value(5000);
    set_stats("dex",3);
    set_stats("str",8);
    set_stats("con",3);
    set_weight(3);
}
