inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_class(5);
    set_sub_type("boots");
    set_short("High boots of the Dynasty <rusty>");
    set_long("The high boots are made of iron. They are covered with rust and dirt. There is\n"+
             "a coat of arms of the royal family of the hobbits, carved into the left\n"+
             "leg of the boots");
    set_stats("str", 3);
    set_stats("con", 2);
    set_stats("dex", 1);
}
