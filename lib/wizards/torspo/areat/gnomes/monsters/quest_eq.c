inherit "obj/food";

reset(arg) {
set_name("head");
set_alias("do_not_abuse_this_one");
set_short("Head of white wolf");
  set_long("The head of white wolf is the item Lalli the gnome wants as a proof of his\n"+
           "quest. Head is bloody and ripped, taking it away from the wolf must have been a\n"+
           "difficult task.\n");
set_weight(10);
set_value(0);
set_strength(10000);
}

query_no_save() { return 1; }
