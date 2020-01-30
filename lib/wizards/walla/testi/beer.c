reset(arg){
    int i;
    i = random(3);
    if(i==0) str = "'Koff'";
    if(i==1) str = "'Karhu'";
    if(i==2) str = "'Karjala'";

}

short() { return "A bottle of beer (labeled "+str+")"; }

long() {
  write("A bottle of beer, brought from another dimension\n");
  write("probably by Walla or Nalle.\n");
  }

get() { return 1; }

drop() { return 0; }

id(str) { return str == "beer"; }

init() {
  add_action("juo", "drink");
}

juo(str) {
  if(str != "beer" && str != "beer") { return; }
  write("AAAAh, that feels good.\n");
  this_player()->drink_soft(10000);
  destruct(this_object());
  return 1;
}

