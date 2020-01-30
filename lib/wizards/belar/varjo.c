#define COLOR sprintf("%c",27)+"[1;31m"
#define OFF sprintf("%c",27)+"[0m"

object ob;

reset(arg) {
  if(arg) return;
  ob = find_player("Belar");
  if(!ob || ob->query_wizuvarjo()) return;
  shadow(ob, 1);
  tell_object(ob, "wiz shadow start\n");
}

 query_name() {
	return "Darkseid"; }

short() { 
	/* return this_player()->query_name() ;} */
	/* return "- .... . .-.. --- -."; }      */
	 return "Darkseid"; } 

/* query_total_string() {
	return "Too much"; }
idle() {
  return 60*60+6; }  */
  
query_total_string() {
	return "too much"; }
	
show_age() {
  write("Age: 25 years.\n");
}
query_wizuvarjo() { return 1; }

remove_wizuvarjo() { destruct(this_object()); }

/* short() { return OFF+ob->short()+OFF; } */

 query_plan() {
  if(this_player()->query_hp() <= 10) return 0;
   
 return "I'm wise and I know you have "+this_player()->query_total_string()+" exp in total.\n ";
    
  
}
