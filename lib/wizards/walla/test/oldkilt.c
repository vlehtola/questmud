inherit "obj/armour";

start() {
set_class(9);
set_slot("legs");
set_name("kilt");
set_alias("pants");
set_short("Green kilt");
set_long("The kilt has a leather codpiece attached to it, and seems to be woven\n" +
         "from the finest cotton available. As you touch the fabric, you notice that\n" +
         "it has no flaws on it, and is almost as smooth as silk.");
set_value(5000);
set_stats("int",-3);
set_stats("wis",-2);
set_stats("hpr",8);
set_stats("str",6);
set_stats("con",3);
set_resists("electric", 10);
set_weight(4);
}



