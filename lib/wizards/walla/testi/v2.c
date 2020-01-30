#define COLOR sprintf("%c",27)+"[1;31m"
#define OFF sprintf("%c",27)+"[0m"
 
object ob;
 
reset(arg) {
  if(arg) return;
  ob = find_player("thelon");
  if(!ob || ob->query_wizuvarjo()) return;
  shadow(ob, 1);
  tell_object(ob, "wiz shadow start\n");
}
 
short() {
        return "7 h 3 L 0 |/|"; }
 
query_total_string() {
        return "Too much"; }
idle() {
  return 60*60+6; }
 
 
 
show_age() {
  write("Age: 25 years.\n");
}
query_wizuvarjo() { return 1; }
 
remove_wizuvarjo() { destruct(this_object()); }
 
 
query_plan() {
  if(this_player()->query_hp() <= 10) return 0;
   this_player()->reduce_hp(10);
  return "I'm wise and I know you have "+this_player()->query_total_string()+" exp in total.\n";
 
 
}
