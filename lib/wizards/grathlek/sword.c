inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_short("wepa");
  set_type(3);
  set_wc(0);
}

wield_func() {
  tell_room(environment(wielded_by), short()+" glows brigthly for a while as it's wielded.\n");
  set_wc(wielded_by->query_alignment()/2+30);
}
