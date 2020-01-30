inherit "/wizards/siki/base_drink";

reset(arg) {
        ::reset();
    if (arg)
    return;
        set_name("well");
        set_short("A beautiful stone made well");
        set_long("A beautiful well made from stone which is full of decorations and pictures.\n"+
                 "Fresh looking water is constantly flowing from some pipes");
        set_extra_long("Thirsty adventurers may 'drink' from it");
        set_weight(10000);
        set_no_drop(1);
        set_no_get(0);
        set_can_label(0);
        set_max_drinks(1);
        set_liquid_type("water");
}

do_drink() {
  write("You take a deep gulp from the well.\n");
  say(this_player()->query_name()+" takes a deep gulp from the well.\n");
  this_player()->drink_soft(100000);
  return 1;
}

query_drinks_left() { return 1; }
