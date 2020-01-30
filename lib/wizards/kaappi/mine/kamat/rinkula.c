inherit "obj/armour";

start() {
         set_class(5);
        set_slot("finger");
        set_name("ring");
         set_short("A Stone ring");
         set_long("This ring is made of stone, but still it is very\n"+
                  "beautiful and it shines like a gold when the rays\n"+
                   "of light hits it. There is some runes crafted on it.\n");
         
         set_stats("str", 5);
         set_stats("con", 5);
         set_stats("dex", 8);
         set_stats("int", -10);
         set_stats("spr", -25);
}
