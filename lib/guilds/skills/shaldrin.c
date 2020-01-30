// Haste
//
// 12.04.02 - Garath


int get_time(string str) {
  return random(2)+10;
}
int ep_cost() { return 40; }
query_type() { return "neutral"; }

status resolve_skill(string str) {
      int dama;
      object ob;
      write("You look at the sky and pray for the lord.\n");
      write("The great Shaldrin arrives from the sky and makes you energic!\n");
      say(capitalize(this_player()->query_name()) + " looks at the sky.\n");
      ob = clone_object("/guilds/skill_obj/haste_ob.c");
      ob->start(this_player());
}

fail_skill(str) {
    if(this_player()->query_haste()) { write("You already feel energic!\n"); return 1; }
    if(random(100) < this_player()->query_skills("shaldrin")) {
	resolve_skill(str);
	return 1;
    }
}
