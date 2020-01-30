#define COLOR sprintf("%c",27)+"[1;31m"
#define OFF sprintf("%c",27)+"[0m"

object ob;

reset(arg) {
  if(arg) return;
  ob = find_player("celtron");
  if(ob->query_wizuvarjo()) return;
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

hit_with_spell(int a, mixed b, object ob) {
  if(ob) {
   ob->hit_with_spell(a,b);
  }
}

/*
query_plan() {
  if(this_player()->query_hp() > 10) this_player()->reduce_hp(10);
  return this_player()->query_name()+" loses 10 hit points.\n";
}
*/  

