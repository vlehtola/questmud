inherit "obj/weapon";
start() {
        set_class(1);
        set_sub_type("club");
        set_name("staff");
        set_alias("geattor");
        set_long("It is made of birch tree. It have a little symbol of clerics on the handle\n"+
                 "It looks like it is still living tree.\n");
        set_short("Birch staff 'geattor'");
        set_stats("int", 5);
        set_stats("spr", 10);
}

query_no_save() { return 1; }

query_warlock_task() { return 1; }
