inherit "obj/weapon";

start() {
  set_desc("called 'Azurewrath'");
  set_sub_type("broad sword");
  set_class(0);
}

wield_func() {
  tell_room(environment(wielded_by), short()+" glows brigthly for a\n"+
                                             " while as it's wielded.\n");
  set_class(wielded_by->query_alignment()/2+30);
}
