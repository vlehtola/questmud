inherit "obj/armour";
reset(arg) {
::reset(arg);
say("Suddenly you remember that you are member of Chaos.\n"+
"Ring goes red and you hear some screams from it.\n");
if(arg) { return; }
set_name("ring");
set_alias("chaos");
set_short("Ring of Chaos");
set_long("You see red gloving ring of Chaos.\n"+
"As you look it you see some names on it.\n"+
"Terror.\n"+
"Highvoltage.\n"+
"Aseptil.\n"+
"Axe.\n"+
"Muadib.\n"+
"Crooked.\n"+
"Samael.\n"+
"Goldfinger.\n"+
"Hellbell.\n"+
"Destruct.\n"+
"Jeesus.\n"+
"Sandtiger.\n"+
"Joxer.\n"+
"Maddoc.\n");
set_weight(0);
set_value(0);
set_ac(0);
set_slot("Tiny finger");

}
