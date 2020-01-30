id(str) { return str=="potion"; }
 
short() { return "A potion of extra-healing"; }
 
long() {
 write("This is a potion. To use it, type 'quaff'.\n");
}
 
query_value() { return 500; }
 
get() { return 1; }
 
init() {
 add_action("quaff","quaff");
}
 
quaff() {
 write("You quaff a potion.\n");
 say(this_player()->query_name()+" imee pullon kierteella.\n");
 cure_light();
 write("Your potion disintegrates.\n");
 destruct(this_object());
 return 1;
}
 
cure_light() {
 object tar;
 int hp,max;
  tar = this_player();
  hp = call_other(tar,"query_hp");
  max = call_other(tar,"query_max_hp");
  if(hp<max) {
   call_other(tar,"set_hp", hp+5000);
   hp = call_other(tar,"query_hp");
   max = call_other(tar,"query_max_hp");
   if(hp>max) call_other(tar,"set_hp",max);
   write("You feel much better!\n");
   say(this_player()->query_name()+" looks much better.\n");
   return 1;
  }
}
