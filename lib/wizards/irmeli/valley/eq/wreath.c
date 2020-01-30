inherit "obj/armour";

start() {
set_class(7);
set_sub_type("helm");
    set_alias("wreath");
    set_short("Laurels of Victory");
    set_long("The laurel wreath is made from laurel leaves. The leaves are\n"+
             "still green and shining in the wreath. A golden thread binds\n"+
             "the leaves together. It's made for winners");
    set_stats("dex", -2);
    set_stats("con", 3);
    set_stats("wis", 4);
    set_stats("int", 8);
    set_stats("spr", 12);
}

