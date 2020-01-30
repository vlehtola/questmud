inherit "obj/weapon";

start() {
    set_class(10);
    set_sub_type("broad sword");
    set_name("blade");
    set_alias("azurewarth");
    set_short("Angelic broad sword called Azurewarth");
    set_long("The handle is made of strange meteor stone. There are"+
" some uncomprehensible runes carved on the blade.\n");
}

wield_func() {
  tell_room(environment(wielded_by), short()+" glows brigthly for a while as it's wielded.\n");
  set_class(wielded_by->query_alignment()/2+30);
}

