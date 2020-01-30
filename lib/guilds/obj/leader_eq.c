inherit "obj/armour";

reset(arg) {
    int i;
    ::reset(arg);
    if(!this_player()->query_race()) {
      destruct(this_object());
      return 0;
    }
    set_name("star");
    set_alias("star of leadership");
    set_short("A Star of leadership of the "+
        capitalize(this_player()->query_race())+
        " race");
    set_long("It is a star made of some strange metal. Maybe you could wear\n"+ 
        "it on your forehead. It is said to possess strange magical powers.\n");
    i = this_player()->query_level()/10;
    //Rag was here 7.7.2004
    if ( i > 30 ) {
      i = 30;
    }
    set_stats("str", i);
    set_stats("dex", i);
    set_stats("con", i);
    set_stats("int", i);
    set_stats("wis", i);
    set_slot("forehead");
}

drop() {
  return 1;
}

stop_wearing() {
  write("The star of leadership vanishes.\n");
  destruct(this_object());
}

query_no_save() {
    return 1;
}

