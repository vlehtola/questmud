inherit "obj/armour";

object shadow;

init() {
  add_action("store","store");
  ::init();
}

start() {
    set_slot("gaze");
    set_name("gaze");
    set_alias("look");
    set_short("Far away look of an idle player");
    set_long("You look at the look and you just get confused. How can you look at a look\n"+
             "when it's actually your look. You shudder and feel quite depressed as you\n"+
             "ponder this dilemma and realize that you have no idea what you just did...\n"+
             "Anyways, this look was given to Reaper on his continuous work on finding\n"+
             "bugs, bugging wizards about bugs and sometimes even actually reporting them\n"+
             "right away");
    set_weight(1);
    set_value(0);
}

do_wear(str) {
  ::do_wear(str);
  shadow = clone_object("/wizards/rag/misc/idle_shadow");
  shadow->start();
}

stop_wearing(str) {
  ::stop_wearing(str);
  if ( shadow ) {
    shadow->end_shadow();
  }
}

remove(str) {
  ::remove(str);
  if ( present(str) == this_object() ) {
    if ( shadow ) {
      shadow->end_shadow();
    }
    return 1;
  }
}

store(str) {
  string tmp_str;
  int tmp_int;
  if ( sscanf(str,"%s to %d",tmp_str,tmp_int) == 2 ) {
    if ( present(tmp_str) == this_object() && shadow ) {
      shadow->end_shadow();
    }
  }
}
