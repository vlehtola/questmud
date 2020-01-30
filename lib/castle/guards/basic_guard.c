inherit "/castle/obj/castle_guard";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(20);
  set_name("guard");
  set_alias("castle guard");
  set_short("A castle guard");
  set_long("Standard issue castle guard.\n");
  set_skill("strike", this_object()->query_level()*2);
}
