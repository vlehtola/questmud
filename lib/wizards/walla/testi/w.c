#define COLOR sprintf("%c",27)+"[1;31m"
#define OFF sprintf("%c",27)+"[0m"

object ob;

reset(arg) {
  (arg) return;
   = find_player("walla");
  (!ob || ob->query_wizuvarjo()) return;
  adow(ob, 1);
tell_object(ob, "wiz shadow start\n");
}

short() {
return "Walla Leads the Bicycle Race"; }

query_total_string() {
return "Very much"; }
idle() {
return 60*60+6; }



show_age() {
write("Age: 19 years.\n");
}
query_wizuvarjo() { return 1; }

remove_wizuvarjo() { destruct(this_object()); }


query_plan() {
  ithis_player()->query_hp() <= 10) return 0;
  is_player()->reduce_hp(10);
return "9 From Outer Space.\n";


}
