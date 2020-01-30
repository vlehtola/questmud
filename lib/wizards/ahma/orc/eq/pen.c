inherit "obj/weapon";
int i;

start() {
  if(!i) { spikeoff(); } else { spikeon(); }
}

init() {
  ::init();
  add_action("hep", "operate");
  add_action("hep", "push");
}

hep(str) {
  if(str == "pen" || str == "button") {
  if(!i) {
    write("You operate a small button on a side of the pen and a sharp spike is revealed.\n");
    say(this_player()->query_name() + " operates a small pen and a sharp spike is revealed from the tip of it.\n");
    i++;
    spikeon();
    return 1;
  }
  else {
    write("You operate a small button on a side of the pen and the sharp spike disappears.\n");
    say(this_player()->query_name() + " operates a small pen and the sharp spike disappears.\n");
    i--;
    spikeoff();
    return 1;
  }
  }
  else {
    write("Operate what?\n");
    return 1;
  }
}

spikeon() {
  set_class(4);
  set_sub_type("long sword");
  set_name("pen");
  set_short("A small fountain pen with a sharp spike on it");
  set_long("Almost five inches long, sharp spike shimmers from the tip of the fountain\n" +
           "pen. Seems that this pen can be used also as a weapon, not just to illustrate\n" +
           "art and different documents. And as the phrase goes: 'The pen is mightier than\n" +
           "a sword.'\n");
}

spikeoff() {
  set_class(4);
  set_sub_type("staff");
  set_name("pen");
  set_short("A small fountain pen");
  set_long("A small and harmless-looking fountain pen, which is used in common tasks\n" +
           "such as writing and drawing. There is a small spike in the tip of the pen\n" +
           "which is supposed to sink into the ink before starting to draw or write\n" +
           "with it. There is some kind of a button in the upper part of the pen, maybe\n" +
           "it could be operated.\n");
}
