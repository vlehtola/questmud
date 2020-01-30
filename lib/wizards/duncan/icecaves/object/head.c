inherit "obj/food";

reset(arg) {

   set_name("head");
   set_alias("do_not_abuse_this_one");
   set_short("A head of an ancient animal <frozen>");
   set_long("A frozen and half-burnt head of an ancient animal. It's medium-sized and\n"+
            "well preserved. You can discern its fearful look from the half-burnt face.\n");

set_weight(100);
set_value(0);
set_strength(10000);
}

query_no_save() { return 1; }
  
