inherit "/wizards/siki/base_drink";

reset(arg) {
        ::reset();
    if (arg)
    return;
        set_name("fountain");
        set_short("A beautiful fountain");
        set_long("A gorgeous looking fountain which is made of stone.\n"+
                 "There are many beautiful and decorated pictures on the fountain.\n"+
                 "The pictures describes some adventurers which are drinking from the fountain.\n");
        set_extra_long("Thirsty adventurers may 'drink' from it");
        set_weight(10000);
        set_no_drop(1);
        set_no_get(0);
        set_can_label(0);
        set_max_drinks(1);
        set_liquid_type("water");
}

do_drink() {
  write("You take a deep gulp from the fountain.\n");
  say(this_player()->query_name()+" takes a deep gulp from the fountain.\n");
  this_player()->drink_soft(100000);
  return 1;
}

query_drinks_left() { return 1; }
