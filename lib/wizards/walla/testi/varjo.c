#define COLOR sprintf("%c",27)+"[1;31m"
#define OFF sprintf("%c",27)+"[0m"

object ob;

reset(arg) {
  if(arg) return;
  ob = find_player("walla");
  if(!ob || ob->query_wizuvarjo()) return;
  shadow(ob, 1);
  tell_object(ob, "wiz shadow start\n");
}

short() { 
return "Your friendly neighbourhood anarchist"; }

query_total_string() {
return "Enough"; }
idle() {
  return 60*60+6; } 
  


show_age() {
  write("Age: 19 years.\n");
}
query_wizuvarjo() { return 1; }

remove_wizuvarjo() { destruct(this_object()); }


query_plan() {
  if(this_player()->query_hp() <= 10) return 0;
   this_player()->reduce_hp(10); 
  return "9 from outer space.\n"; 
    
  
} 

