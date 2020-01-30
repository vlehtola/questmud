inherit "obj/armour";
status active;
string *msgs;

start() {
    set_class(0);
     set_slot("head");
    set_name("hat");
    set_short("Finely crafted hat that has Big 'G' in front of it");
    set_long("It's a honour to carry this hat, it gives you strength\n"+
             "to go through the life as you accept the religious what\n"+
             "this hat has to offer to you, the only rule is to obey\n"+
             "every command the great and mighty G tells you!\n"+
             "It looks like you can command it as hat");

    set_heart_beat(1);
    msgs = ({
"The hat bounces around and finally jumps back on it's owner's hands.\n",
"The hat booms: Big G in tha house shall rock you like mouse!\n",
"The hat booms: Beware as the destruction will come!\n",
"The hat booms: The lord of destruction is knocking at your door!\n",
"The hat booms: The lord will not spare anyone as the arrival comes true!\n",
"The hat booms: I used to watch a show called as 'BumbtsiBum' everyday...\n",
"The hat booms: Changes are to come - Nothing can be shown, but the wisdom is known!\n",
});
}

init() {
  ::init();
  add_action("activate","hat");
}

status activate(string str) {
  int i;
  if(str == "on") {
    active = 1;
    write("You activate the hat.\n");
    return 1;
  } else if (str == "off") {
    active = 0;
    write("You de-activate the hat.\n");
    return 1;
  }
  write("Hat what?\n");
  return 1;
}

void heart_beat() {
  if(!environment(this_object()) || !active || random(30) < 29) return;
  if(!environment(this_object())->query_long()) tell_room(environment(environment(this_object())),msgs[random(sizeof(msgs))]);
  if(environment(this_object())->query_long()) tell_room(environment(this_object()),msgs[random(sizeof(msgs))]);
}
