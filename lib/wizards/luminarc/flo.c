#define HMM "/wizards/luminarc/hmm.c"
/* all functions are optional. */

reset(arg) {
  if(arg) return;
}



do_something() {
  this_player()->death();
}

short() {
  return "Alright, this object has a short";
}
id(str) {
string str;  
return str == "hmm";
  /* we can also return str == name || str == alias || str == alt_name; 
etc */
}

long() {
  write("This is the LONG desc.\n");
}

/* 1 can't drop, 0 can drop. see get() */
drop() {
  return 1;
}

/* uh, heavy */
query_weight() {
  return 1000;
}

/* add your own functions etc. this file proves only, that objects can be
simple */
/* and easily done. coding is fun anyway. //Celtron */

init() {
   add_action("show_x_value", "show_x_value");
  add_action("set_x_value", "set_x_value");
  add_action("reset_x_value", "reset_x_value");
}
show_x_value(str)
{
call_other(HMM, "show_x_value");
}
set_x_value(str)
{
call_other(HMM, "set_x_value");
}
reset_x_value(str)
{
call_other(HMM, "reset_x_value");
}

