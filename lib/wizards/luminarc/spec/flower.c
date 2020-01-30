reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("flower");
set_alias("flower");
set_short("Beautiful purple flower");
set_long("Big flower with beautiful colors \n");
set_weight(20);
set_value(0);
}
query_no_save() { return 1; }
init() {
  add_action("show_x_value", "show_x_value");
  add_action("set_x_value", "set_x_value");
  add_action("reset_x_value", "reset_x_value");
}
show_x_value()
{
call_other("/wizards/luminarc/hmm.c", "show_x_value");
}
set_x_value()
{
call_other("/wizards/luminarc/hmm.c", "set_x_value");
}
reset_x_value()
{
call_other("/wizards/luminarc/hmm.c", "reset_x_value);
}

