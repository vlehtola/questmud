inherit "obj/armour";

start() {
    set_slot("cloak");
    set_name("cloak");
    set_alias("cape");
    set_short("Black hooded cloak");
    set_long("This cloak looks like a normal hooded cloak, but he material of\n"+
                "this cloak is something that you've never seen before. It is very\n"+
                "durable and light weight. It feels very nice on your skin. The large\n"+
                "hood easily conceals your face and you get the feeling that the former\n"+
                "owner of this cloak didn't want people to see his face");
    set_weight(10);
    set_value(2000);
    set_stats("dex",6);
}
