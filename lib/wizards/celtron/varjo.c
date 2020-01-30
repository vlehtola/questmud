#define COLOR sprintf("%c",27)+"[1;31m"
#define OFF sprintf("%c",27)+"[0m"

object ob;

reset(arg) {
  if(arg) return;
  ob = find_player("celtron");
  if(!ob || ob->query_wizuvarjo()) return;
  shadow(ob, 1);
  tell_object(ob, "wiz shadow start\n");
}
/*
idle() {
  return 60*6+6;
}
*/
show_age() {
  write("Age: -2s.\n");
}
query_wizuvarjo() { return 1; }

remove_wizuvarjo() { destruct(this_object()); }

short() { return COLOR+ob->short()+OFF; }

query_plan() {
  if(this_player()->query_hp() <= 10) return 0;
  this_player()->reduce_hp(10);
  return "I know somebody who has "+this_player()->query_total_string()+" exp in total,\n"+
         "and just lost 10 hit points.\n";
}

