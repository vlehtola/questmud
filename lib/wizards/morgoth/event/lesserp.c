id(str) { return str=="potion"; }
 
short() { return "A lesser healing potion."; }
 
long() {
 write("This is a lesser healing potion. To use it, type 'quaff'.\n");
}
 
query_value() { return 500; }
 
get() { return 1; }
 
init() {
 add_action("quaff","quaff");
}
 
quaff() {
 write("You quaff a potion.\n");
 say(this_player()->query_name()+" quaffs a potion.\n");
 cure_light();
 write("Your potion vanishes.\n");
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
   call_other(tar,"set_hp", hp+1000);
   hp = call_other(tar,"query_hp");
   max = call_other(tar,"query_max_hp");
   if(hp>max) call_other(tar,"set_hp",max);
   write("You feel better!\n");
   say(this_player()->query_name()+" looks better.\n");
   return 1;
  }
}
