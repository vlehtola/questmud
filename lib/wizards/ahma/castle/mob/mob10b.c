inherit "obj/monster";

reset(arg) {
  object blade;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2)+17);
  set_str(75);
  set_name("imp");
  set_alias("demon");
  set_short("Frail demon imp");
  set_long("Short and weak-looking pinkish imp is sitting quietly in the corner of the\n" + 
           "room, like it would be trying to avoid your sight. This hairless creature\n" + 
           "has very long and thin arms and legs, and it looks like there is no muscles\n" + 
           "at all in those limbs. After a moments examine you realize that this whole\n" + 
           "creature looks like a sitting skeleton in the corner. But something extremely\n" + 
           "evil can be seen in its poison-green eyes. A small electric bolt sparkles\n" + 
           "softly on the tip of creature's right hand little finger. Imp's slender tail\n" + 
           "is a shape of a dull arrow.\n");
  set_al(-55);
  set_aggressive(0);
  set_resists("fire",55);
  set_mage();

  if(random(2)) {
    blade = clone_object("/wizards/ahma/castle/eq/blade");
    move_object(blade, this_object());
    init_command("wield blade");
  }
}
