inherit "obj/weapon";
  start() {
    set_class(1);
    set_sub_type("club");

    set_alias("pin"); 

    set_short("Rolling pin");
    set_long("This is a rolling pin used to roll out bread. Not really much of \n"+
                    "a weapon but could cause some damage.\n");
}
