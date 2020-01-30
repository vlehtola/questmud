inherit "/wizards/siki/base_object";

int digging;

reset(arg) {
        ::reset();
    if (arg)
    return;
        set_name("shovel");
        set_short("A shovel made from iron");
        set_long("This is typically looking shovel");
        set_extra_long("You can use it to dig graves");
        set_weight(300);
        set_value(10);
        set_no_drop(0);
        set_no_get(1);
        set_can_label(1);
        set_size(30);
        set_material("iron");
        digging = 0;
}

init() {
  add_action("dig", "dig");
}

dig(arg) {
  if(arg != "grave") {
    write("You dig from here and there, but quickly find out that it was no use.\n");
    return 1;
  }
  if ( digging ) {
    write("You are already digging a grave.\n");
    return 1;
  }
  if ( this_player()->query_attacker() ) {
    write("You can't dig a grave in combat.\n");
    return 1;
  }
  write("You start digging.\n");
  say(this_player()->query_name()+" starts digging a grave.\n");
  call_out("end_dig", 3);
  digging = 1;
  return 1;
}

end_dig() {
  object ob;
  int dig;
  dig = 0;
  ob = present("corpse", environment(this_player()));
  while ( ob ) {
    filter_array(all_inventory(ob), #'move_object, environment(this_player()));
    destruct(ob);
    dig = 1;
    ob = present("corpse", environment(this_player()));
  }
  digging = 0;
  if( !dig ) {
    write("There is no corpse to bury.\n");
    say(this_player()->query_name()+" cannot find any corpses and fills the hole.\n");
    return 1;
  }
  write("You finish digging the grave and grab the corpse in it and fill it up.\n");
  say(this_player()->query_name()+" buries the corpse without ceremonies.\n");
  return 1;
}
